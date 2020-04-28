#pragma once
#include "utils/fileutils.h"
#include "asset/rawmesh.h"
#include "asset/rawskinmesh.h"
#include "meshloader.h"
#include <fbxsdk.h>
#include <fbxsdk/fileio/fbxiosettings.h>
#include "maths/vec3.h"
#include "maths/vec4.h"
#include "asset/skeleton.h"
#include "skeletalpose.h"
#include "map"
#include "list"
#include "animation/animationlayer.h"

namespace sparky
{
	namespace animation
	{
		template<class T>
		class KeyValueNode;
	}
}

using namespace sparky::animation;
using namespace sparky::maths;
namespace sparky {
	namespace asset {

		struct InterVertexData
		{
			InterVertexData()
			{
				CurrentIndex = -1;
				BoneWeight[0] = 0;
				BoneWeight[1] = 0;
				BoneWeight[2] = 0;
				BoneWeight[3] = 0;

				BoneIndex[0] = 0;
				BoneIndex[1] = 0;
				BoneIndex[2] = 0;
				BoneIndex[3] = 0;
			}
			vec3 Position;
			float4 Color;
			vec3 Normal;
			vec3 Tangent;
			float BoneWeight[4];
			int BoneIndex[4];
			int CurrentIndex;
		};
		struct InterMediateMesh
		{
			
			std::map<unsigned int, std::list<unsigned int>> CtrlVertices;
			std::vector<InterVertexData> VertexArray;
			std::vector<unsigned short> Faces;

			bool IsIndexed() { return Faces.size() > 0; }
 
		};

		class FBXMeshPostProcess
		{
		public:
			RawSkinMesh* GetRawSkinMesh(unsigned int id) { return m_SkinMeshAsset[id]; };
			unsigned int GetRawSkinMeshCount() { return m_MeshAsset.size(); };
			RawMesh* GetRawStaticMesh(unsigned int id) { return m_MeshAsset[id]; };
			unsigned int GetRawStaticMeshCount() { return m_MeshAsset.size(); };
		
			virtual void Process(std::vector<InterMediateMesh*>& intermediatemeharray) {};

		protected:
			std::vector<RawMesh*> m_MeshAsset;
			std::vector<RawSkinMesh*> m_SkinMeshAsset;

		};


		class FBXEasyMeshPostProcess:public FBXMeshPostProcess
		{
		public:
			void Process(std::vector<InterMediateMesh*>& intermediatemeharray);


		};



		class FBXLoader 
		{
		public:
			FBXLoader();
			bool LoadFile(const char* file);
			void LoadResources();
			bool LoadMesh(RawMesh& rmesh);
			void Initialize();

			RawSkinMesh* GetRawSkinMesh(unsigned int id) 
			{ 
				return m_PostProcess->GetRawSkinMesh(id); 
			}
			unsigned int GetRawSkinMeshCount() 
			{
				return m_PostProcess->GetRawSkinMeshCount();
			}
			RawMesh* GetRawStaticMesh(unsigned int id) 
			{
				return m_PostProcess->GetRawStaticMesh(id);
			}
			unsigned int GetRawStaticMeshCount() 
			{ 
				return m_PostProcess->GetRawStaticMeshCount(); 
			}

			unsigned int GetClipCount()
			{
				return m_ClipAsset.size();
			}

			unsigned int GetSkeletonCount()
			{
				return m_SkeletalAsset.size();
			}

			Skeleton* GetSkeleton(unsigned int id)
			{
				return m_SkeletalAsset[id];
			}

			SkeletonClip* GetClip(unsigned int id)
			{
				return m_ClipAsset[id];
			}

			unsigned int GetAnimationLayerCount() { return m_AnimationLayers.size(); }
			AnimationLayer* GetAnimationLayer(int id) { return m_AnimationLayers[id]; }

		private:
			void ComputeSkinDeformation(FbxAMatrix& pGlobalPosition, FbxMesh* pMesh, FbxTime& pTime, FbxVector4* pVertexArray, FbxPose* pPose);
 
			void ProcessNode(FbxNode* node, FbxAnimLayer* animationlayer = 0);
			void ProcessMesh(FbxNode* pNode, FbxAnimLayer* animationlayer = 0);
			void ProcessSkeleton(FbxNode* pNode, Skeleton* node, int parentindex/*, FbxAnimLayer* animationlayer = 0, AnimationLayer *layer = 0, bool LoadSkeleton = true*/);
			void InitializeSdkObjects(FbxManager*& pManager, FbxScene*& pScene);

			void ComputeDualQuaternionDeformation(FbxAMatrix& pGlobalPosition, FbxMesh* pMesh, FbxTime& pTime, FbxVector4* pVertexArray, FbxPose* pPose);
			void ComputeLinearDeformation(FbxAMatrix& pGlobalPosition, FbxMesh* pMesh, FbxTime& pTime, FbxVector4* pVertexArray, FbxPose* pPose);
			//void ReadRawStaticMesh(FbxMesh* pMesh, InterMediateMesh* rawstaticmesh);
			void ReadIntemediateMesh(FbxMesh* pMesh, InterMediateMesh* rawskinmesh);
			//void ReadTangent(FbxMesh* pMesh, int ctrlPointIndex, int vertexCounter, vec3& tangent);
			//void ReadNormal(FbxMesh* pMesh, int ctrlPointIndex, int vertexCounter, vec3& normal);
			void ReadPosition(FbxMesh* pMesh, int ctrlPointIndex, int vertexCount, vec3& pos);
			void ReadColor(FbxMesh* pMesh, int ctrlPointIndex, int vertexCount, float4& color);
			void ReadUV(FbxMesh* pMesh, int ctrlPointIndex, int vertexCount);

			void LoadNodeCurve(FbxAnimLayer* pAnimationLayer, AnimationLayer *layer, FbxNode* pNode);

			template<class T>
			void LoadNodeCurveKeyCollection(KeyValueNode<T> *keyvaluenode, FbxAnimCurve** curve, int count);
			void FillPoseArray(FbxScene* pScene, FbxArray<FbxPose*>& pPoseArray)
			{
				const int lPoseCount = pScene->GetPoseCount();

				for (int i = 0; i < lPoseCount; ++i)
				{
					pPoseArray.Add(pScene->GetPose(i));
				}
			}


			void AssociateSkeletonWithCtrlPoint(FbxSkin* pSkin, InterMediateMesh* rawskinmesh);
			void AssociateSkeletonWithCtrlPoint(FbxMesh* pMesh, InterMediateMesh* rawskinmesh);
			bool SetCurrentAnimStack(int pIndex);
			void LoadCacheRecursive(FbxNode * pNode, FbxAnimLayer * pAnimLayer, bool pSupportVBO);
			void LoadCacheRecursive(FbxScene * pScene, FbxAnimLayer * pAnimLayer, const char * pFbxFileName, bool pSupportVBO);

			mat4 ConvertFBXMatrix(FbxAMatrix& fbxmat);
			float4 ConvertFBXfloat4(FbxVector4& fbxvec);

			void LoadSkinData();
			void LoadAnimationData();
			int GetJointIndex(FbxString jointname);
			joint* GetJoint(int index);

			
			void PostProcess();


		private:
			//std::vector<FbxString*> mAnimStackNameArray;
			FbxManager * mSdkManager;
			std::vector<FbxPose*> mPoseArray;
			FbxScene * mScene;
			FbxImporter * mImporter;

			//std::vector<AnimationClip*> m_ClipAsset;
			std::vector<FbxAnimStack*> m_AnimStacks;
		
			std::vector<Skeleton*> m_SkeletalAsset;
			std::vector<SkeletonClip*> m_ClipAsset;
			std::vector<FbxTimeSpan> m_ClipInfos;

			std::vector<InterMediateMesh*> m_InterMeshArray;
			std::vector<FbxMesh*> m_FbxMeshProcessing;
			std::vector<AnimationLayer *> m_AnimationLayers;
			std::vector<FbxAnimLayer*> m_FBXAnimLayers;
			FBXMeshPostProcess *m_PostProcess;
			
		};
	}
}

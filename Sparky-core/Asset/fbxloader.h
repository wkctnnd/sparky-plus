#pragma once
#include "utils/fileutils.h"
#include "asset/rawmesh.h"
#include "asset/rawskinmesh.h"
#include "meshloader.h"
#include <fbxsdk.h>
#include <fbxsdk/fileio/fbxiosettings.h>
#include "maths/vec3.h"
#include "maths/vec4.h"
#include "maths/vec2.h"
#include "asset/skeleton.h"
#include "skeletalpose.h"
#include "map"
#include "list"
#include "animation/animationlayer.h"
#include <set>

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
			float3 Position;
			float4 Color;
			float3 Normal;
			float3 Tangent;

			std::vector<float2> Texcoord;
			 


			float BoneWeight[4];
			int BoneIndex[4];
			int CurrentIndex;
		};
		struct InterMediateMesh
		{
			
			std::map<unsigned int, std::list<unsigned int>> CtrlVertices;
			std::vector<InterVertexData> VertexArray;
			std::vector<unsigned short> Faces;
			std::set <std::string>  Bones;

			bool IsIndexed() { return Faces.size() > 0; }
 
		};

		class FBXMeshPostProcess
		{
		public:
			RawSkinMesh* GetRawSkinMesh(unsigned int id) { return m_SkinMeshAsset[id]; };
			unsigned int GetRawSkinMeshCount() { return m_MeshAsset.size(); };
			RawMesh* GetRawStaticMesh(unsigned int id) { return m_MeshAsset[id]; };
			unsigned int GetRawStaticMeshCount() { return m_MeshAsset.size(); };
		
			virtual void Process(std::vector<InterMediateMesh*>& intermediatemeharray, std::vector<Skeleton*>& skeletonasset) {};

			unsigned int GetSkeletonCount()
			{
				return m_RealUsedSkeletalAsset.size();
			}

			Skeleton* GetSkeleton(unsigned int id)
			{
				return m_RealUsedSkeletalAsset[id];
			}

		protected:
			std::vector<RawMesh*> m_MeshAsset;
			std::vector<RawSkinMesh*> m_SkinMeshAsset;
			void GenerateUsedSkeletonAsset(std::set <std::string>&  Bones, std::vector<Skeleton*>& skeletonasset);
			void ProcessSkeleton(joint* jt, joint* parent, std::set <std::string>&  Bones, Skeleton* skeleton);
			std::vector<Skeleton*> m_RealUsedSkeletalAsset;
		};


		class FBXEasyMeshPostProcess:public FBXMeshPostProcess
		{
		public:
			void Process(std::vector<InterMediateMesh*>& intermediatemeharray, std::vector<Skeleton*>& skeletonasset);


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
			//void ReadTangent(FbxMesh* pMesh, int ctrlPointIndex, int vertexCounter, float3& tangent);
			//void ReadNormal(FbxMesh* pMesh, int ctrlPointIndex, int vertexCounter, float3& normal);
			void ReadPosition(FbxMesh* pMesh, int ctrlPointIndex, int vertexCount, float3& pos);
			void ReadColor(FbxMesh* pMesh, int ctrlPointIndex, int vertexCount, float4& color);
			void ReadUV(FbxMesh* pMesh, int ctrlPointIndex, int uvIndex, int uvlayer, float2& uv);

			void LoadNodeCurve(FbxAnimLayer* pAnimationLayer, AnimationLayer *layer, FbxNode* pNode);

			void LoadNodeCurve(FbxNode* pNode);

			template<class T>
			void LoadNodeCurveKeyCollection(KeyValueNode<T> *keyvaluenode, FbxAnimCurve** curve, int count);

			//template<class T>
			//void LoadNodeCurveKeyCollection(KeyValueNode<T> *keyvaluenode, FbxAnimCurve** curve, int count);

			template<class T>
			void LoadNodeCurveKeyCollectionTest(FbxNode* pNode, KeyValueNode<T> *keyvaluenode, FbxAnimCurve** curve, int count);

			void LoadRotationCurve(KeyValueNode<Quaternion> *keyvaluenode, FbxPropertyT<FbxDouble3>& rotproperty, FbxAnimCurve* curve);
			void LoadRotationCurveTest(FbxNode* pNode, KeyValueNode<Quaternion> *keyvaluenode, FbxPropertyT<FbxDouble3>& rotproperty, FbxAnimCurve* curve);

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
			
			//std::vector<std::vector<std::string>> m_US

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

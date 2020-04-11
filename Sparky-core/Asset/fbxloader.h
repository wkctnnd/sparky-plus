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
#include "animation.h"
#include "map"
#include "list"

using namespace sparky::maths;
namespace sparky {
	namespace asset {

		struct InterVertexData
		{
			InterVertexData()
			{
				CurrentIndex = -1;
			}
			vec3 Position;
			vec4 Color;
			vec3 Normal;
			vec3 Tangent;
			float BoneWeight[4];
			int BoneIndex[4];
			int CurrentIndex;
		};
		struct InterMediateMesh
		{
			
			std::map<unsigned int, std::list<InterVertexData*>> CtrlVertices;
			std::vector<InterVertexData*> VertexArray;
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
		private:
			void ComputeSkinDeformation(FbxAMatrix& pGlobalPosition, FbxMesh* pMesh, FbxTime& pTime, FbxVector4* pVertexArray, FbxPose* pPose);
 
			void ProcessNode(FbxNode* node, FbxAnimLayer* animationlayer = 0);
			void ProcessMesh(FbxNode* pNode, FbxAnimLayer* animationlayer = 0);
			void ProcessSkeleton(FbxNode* pNode, Skeleton* node, int parentindex, FbxAnimLayer* animationlayer = 0, SkeletonPose** pose = 0);
			void InitializeSdkObjects(FbxManager*& pManager, FbxScene*& pScene);

			void ComputeDualQuaternionDeformation(FbxAMatrix& pGlobalPosition, FbxMesh* pMesh, FbxTime& pTime, FbxVector4* pVertexArray, FbxPose* pPose);
			void ComputeLinearDeformation(FbxAMatrix& pGlobalPosition, FbxMesh* pMesh, FbxTime& pTime, FbxVector4* pVertexArray, FbxPose* pPose);
			//void ReadRawStaticMesh(FbxMesh* pMesh, InterMediateMesh* rawstaticmesh);
			void ReadIntemediateMesh(FbxMesh* pMesh, InterMediateMesh* rawskinmesh);
			//void ReadTangent(FbxMesh* pMesh, int ctrlPointIndex, int vertexCounter, vec3& tangent);
			//void ReadNormal(FbxMesh* pMesh, int ctrlPointIndex, int vertexCounter, vec3& normal);
			void ReadPosition(FbxMesh* pMesh, int ctrlPointIndex, int vertexCount, vec3& pos);
			void ReadColor(FbxMesh* pMesh, int ctrlPointIndex, int vertexCount, vec4& color);
			void ReadUV(FbxMesh* pMesh, int ctrlPointIndex, int vertexCount);

			void LoadNodeCurve(FbxAnimLayer* pAnimationLayer, FbxNode* pNode);
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
			vec4 ConvertFBXVec4(FbxVector4& fbxvec);

			void LoadSkinData();
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
			std::vector<SkeletonPose*> m_ClipAsset;
			std::vector<FbxTimeSpan> m_ClipInfos;

			std::vector<InterMediateMesh*> m_InterMeshArray;
			std::vector<FbxMesh*> m_FbxMeshProcessing;

			FBXMeshPostProcess *m_PostProcess;
			
		};
	}
}

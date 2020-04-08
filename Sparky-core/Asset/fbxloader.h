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

using namespace sparky::maths;
namespace sparky {
	namespace asset {
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
			void ReadRawStaticMesh(FbxMesh* pMesh, RawMesh* rawstaticmesh);
			void ReadRawSkinMesh(FbxMesh* pMesh, RawSkinMesh* rawskinmesh);
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
			bool SetCurrentAnimStack(int pIndex);
			void LoadCacheRecursive(FbxNode * pNode, FbxAnimLayer * pAnimLayer, bool pSupportVBO);
			void LoadCacheRecursive(FbxScene * pScene, FbxAnimLayer * pAnimLayer, const char * pFbxFileName, bool pSupportVBO);

		private:
			//std::vector<FbxString*> mAnimStackNameArray;
			FbxManager * mSdkManager;
			std::vector<FbxPose*> mPoseArray;
			FbxScene * mScene;
			FbxImporter * mImporter;

			//std::vector<AnimationClip*> m_ClipAsset;
			std::vector<FbxAnimStack*> m_AnimStacks;
			std::vector<RawMesh*> m_MeshAsset;
			std::vector<RawSkinMesh*> m_SkinMeshAsset;
			std::vector<Skeleton*> m_SkeletalAsset;
			std::vector<SkeletonPose*> m_ClipAsset;
			std::vector<FbxTimeSpan> m_ClipInfos;
		};
	}
}

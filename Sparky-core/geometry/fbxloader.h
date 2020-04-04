#pragma once
#include "utils/fileutils.h"
#include "geometry/rawmesh.h"
#include "meshloader.h"
#include <fbxsdk.h>
#include <fbxsdk/fileio/fbxiosettings.h>
namespace sparky {
	namespace asset {
		class FBXLoader 
		{
		public:
			bool LoadFile(const char* file);
			bool LoadMesh(const char* file, RawMesh& rmesh);
			void Initialize();
		private:


			void InitializeSdkObjects(FbxManager*& pManager, FbxScene*& pScene);


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
			FbxArray<FbxString*> mAnimStackNameArray;
			FbxManager * mSdkManager;
			FbxArray<FbxPose*> mPoseArray;
			FbxScene * mScene;
			FbxImporter * mImporter;
		};
	}
}

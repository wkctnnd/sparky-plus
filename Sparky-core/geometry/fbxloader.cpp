#include "fbxloader.h"

using namespace sparky::maths;
namespace sparky {

	namespace asset {

		// Bake node attributes and materials under this node recursively.
  // Currently only mesh, light and material.
		void FBXLoader::LoadCacheRecursive(FbxNode * pNode, FbxAnimLayer * pAnimLayer, bool pSupportVBO)
		{
			// Bake material and hook as user data.

			FbxNodeAttribute* lNodeAttribute = pNode->GetNodeAttribute();
			if (lNodeAttribute)
			{
				// Bake mesh as VBO(vertex buffer object) into GPU.
				if (lNodeAttribute->GetAttributeType() == FbxNodeAttribute::eMesh)
				{
					FbxMesh * lMesh = pNode->GetMesh();
					if (pSupportVBO && lMesh && !lMesh->GetUserDataPtr())
					{
						//º”‘ÿmesh
						/*FbxAutoPtr<VBOMesh> lMeshCache(new VBOMesh);
						if (lMeshCache->Initialize(lMesh))
						{
							lMesh->SetUserDataPtr(lMeshCache.Release());
						}*/
					}
				}
			}

			const int lChildCount = pNode->GetChildCount();
			for (int lChildIndex = 0; lChildIndex < lChildCount; ++lChildIndex)
			{
				LoadCacheRecursive(pNode->GetChild(lChildIndex), pAnimLayer, pSupportVBO);
			}
		}

		void FBXLoader::LoadCacheRecursive(FbxScene * pScene, FbxAnimLayer * pAnimLayer, const char * pFbxFileName, bool pSupportVBO)
		{
			// Load the textures into GPU, only for file texture now
			const int lTextureCount = pScene->GetTextureCount();
			for (int lTextureIndex = 0; lTextureIndex < lTextureCount; ++lTextureIndex)
			{
				FbxTexture * lTexture = pScene->GetTexture(lTextureIndex);
				FbxFileTexture * lFileTexture = FbxCast<FbxFileTexture>(lTexture);
				if (lFileTexture && !lFileTexture->GetUserDataPtr())
				{
					// Try to load the texture from absolute path
					const FbxString lFileName = lFileTexture->GetFileName();

					// Only TGA textures are supported now.
					if (lFileName.Right(3).Upper() != "TGA")
					{
						FBXSDK_printf("Only TGA textures are supported now: %s\n", lFileName.Buffer());
						continue;
					}

		/*			GLuint lTextureObject = 0;
					bool lStatus = LoadTextureFromFile(lFileName, lTextureObject);*/

					const FbxString lAbsFbxFileName = FbxPathUtils::Resolve(pFbxFileName);
					const FbxString lAbsFolderName = FbxPathUtils::GetFolderName(lAbsFbxFileName);
					//if (!lStatus)
					//{
					//	// Load texture from relative file name (relative to FBX file)
					//	const FbxString lResolvedFileName = FbxPathUtils::Bind(lAbsFolderName, lFileTexture->GetRelativeFileName());
					//	lStatus = LoadTextureFromFile(lResolvedFileName, lTextureObject);
					//}

					//if (!lStatus)
					//{
					//	// Load texture from file name only (relative to FBX file)
					//	const FbxString lTextureFileName = FbxPathUtils::GetFileName(lFileName);
					//	const FbxString lResolvedFileName = FbxPathUtils::Bind(lAbsFolderName, lTextureFileName);
					//	lStatus = LoadTextureFromFile(lResolvedFileName, lTextureObject);
					//}

					//if (!lStatus)
					//{
					//	FBXSDK_printf("Failed to load texture file: %s\n", lFileName.Buffer());
					//	continue;
					//}

					//if (lStatus)
					//{
					//	GLuint * lTextureName = new GLuint(lTextureObject);
					//	lFileTexture->SetUserDataPtr(lTextureName);
					//}
				}
			}

			LoadCacheRecursive(pScene->GetRootNode(), pAnimLayer, pSupportVBO);
		}

		void FBXLoader::Initialize()
		{
			InitializeSdkObjects(mSdkManager, mScene);

			if (mSdkManager)
			{
				// Create the importer.
				int lFileFormat = -1;
				mImporter = FbxImporter::Create(mSdkManager, "");
				
			}
		}

		void FBXLoader::InitializeSdkObjects(FbxManager*& pManager, FbxScene*& pScene)
		{
			//The first thing to do is to create the FBX Manager which is the object allocator for almost all the classes in the SDK
			pManager = FbxManager::Create();
			if (!pManager)
			{
				FBXSDK_printf("Error: Unable to create FBX Manager!\n");
				exit(1);
			}
			else FBXSDK_printf("Autodesk FBX SDK version %s\n", pManager->GetVersion());

			//Create an IOSettings object. This object holds all import/export settings.
			FbxIOSettings* ios = FbxIOSettings::Create(pManager, IOSROOT);
			pManager->SetIOSettings(ios);

			//Load plugins from the executable directory (optional)
			FbxString lPath = FbxGetApplicationDirectory();
			pManager->LoadPluginsDirectory(lPath.Buffer());

			//Create an FBX scene. This object holds most objects imported/exported from/to files.
			pScene = FbxScene::Create(pManager, "My Scene");
			if (!pScene)
			{
				FBXSDK_printf("Error: Unable to create FBX scene!\n");
				exit(1);
			}
		}

		bool FBXLoader::LoadFile(const char* file)
		{
			return true;
		}

		bool FBXLoader::LoadMesh(const char* filename, RawMesh& rmesh)
		{
			FbxManager* lSdkManager = FbxManager::Create();

			// Create an IOSettings object.
			FbxIOSettings * ios = FbxIOSettings::Create(lSdkManager, IOSROOT);
			lSdkManager->SetIOSettings(ios);

			// ... Configure the FbxIOSettings object ...

			// Create an importer.
			FbxImporter* lImporter = FbxImporter::Create(lSdkManager, "");

			// Declare the path and filename of the file containing the scene.
			// In this case, we are assuming the file is in the same directory as the executable.
			//const char* lFilename = "file.fbx";

			// Initialize the importer.

			int lFileFormat;
			if (!mSdkManager->GetIOPluginRegistry()->DetectReaderFileFormat(filename, lFileFormat))
			{
				// Unrecognizable file format. Try to fall back to FbxImporter::eFBX_BINARY
				lFileFormat = mSdkManager->GetIOPluginRegistry()->FindReaderIDByDescription("FBX binary (*.fbx)");;
			}

			// Initialize the importer by providing a filename.
			if (mImporter->Initialize(filename, lFileFormat) == true)
			{
				// File format version numbers to be populated.
				int lFileMajor, lFileMinor, lFileRevision;

				// Populate the FBX file format version numbers with the import file.
				lImporter->GetFileVersion(lFileMajor, lFileMinor, lFileRevision);

				//FbxScene * mScene;
				bool lResult = false;
				lResult = lImporter->Import(mScene);

				FbxAxisSystem SceneAxisSystem = mScene->GetGlobalSettings().GetAxisSystem();
				FbxAxisSystem OurAxisSystem(FbxAxisSystem::eYAxis, FbxAxisSystem::eParityOdd, FbxAxisSystem::eRightHanded);
				if (SceneAxisSystem != OurAxisSystem)
				{
					OurAxisSystem.ConvertScene(mScene);
				}

				// Convert Unit System to what is used in this example, if needed
				FbxSystemUnit SceneSystemUnit = mScene->GetGlobalSettings().GetSystemUnit();
				if (SceneSystemUnit.GetScaleFactor() != 1.0)
				{
					//The unit in this example is centimeter.
					FbxSystemUnit::cm.ConvertScene(mScene);
				}

				// Get the list of all the animation stack.
				mScene->FillAnimStackNameArray(mAnimStackNameArray);


				// Convert mesh, NURBS and patch into triangle mesh
				FbxGeometryConverter lGeomConverter(mSdkManager);
				try {
					lGeomConverter.Triangulate(mScene, /*replace*/true);
				}
				catch (std::runtime_error) {
					FBXSDK_printf("Scene integrity verification failed.\n");
					return false;
				}

				FillPoseArray(mScene, mPoseArray);
			}
			else
			{
				return false;
			}

		}


		bool FBXLoader::SetCurrentAnimStack(int pIndex)
		{
			//const int lAnimStackCount = mAnimStackNameArray.GetCount();
			//if (!lAnimStackCount || pIndex >= lAnimStackCount)
			//{
			//	return false;
			//}

			//// select the base layer from the animation stack
			//FbxAnimStack * lCurrentAnimationStack = mScene->FindMember<FbxAnimStack>(mAnimStackNameArray[pIndex]->Buffer());
			//if (lCurrentAnimationStack == NULL)
			//{
			//	// this is a problem. The anim stack should be found in the scene!
			//	return false;
			//}

			//// we assume that the first animation layer connected to the animation stack is the base layer
			//// (this is the assumption made in the FBXSDK)
			//mCurrentAnimLayer = lCurrentAnimationStack->GetMember<FbxAnimLayer>();
			//mScene->SetCurrentAnimationStack(lCurrentAnimationStack);

			//FbxTakeInfo* lCurrentTakeInfo = mScene->GetTakeInfo(*(mAnimStackNameArray[pIndex]));
			//if (lCurrentTakeInfo)
			//{
			//	mStart = lCurrentTakeInfo->mLocalTimeSpan.GetStart();
			//	mStop = lCurrentTakeInfo->mLocalTimeSpan.GetStop();
			//}
			//else
			//{
			//	// Take the time line value
			//	FbxTimeSpan lTimeLineTimeSpan;
			//	mScene->GetGlobalSettings().GetTimelineDefaultTimeSpan(lTimeLineTimeSpan);

			//	mStart = lTimeLineTimeSpan.GetStart();
			//	mStop = lTimeLineTimeSpan.GetStop();
			//}

			//// check for smallest start with cache start
			//if (mCache_Start < mStart)
			//	mStart = mCache_Start;

			//// check for biggest stop with cache stop
			//if (mCache_Stop > mStop)
			//	mStop = mCache_Stop;

			//// move to beginning
			//mCurrentTime = mStart;

			//// Set the scene status flag to refresh 
			//// the scene in the next timer callback.
			//mStatus = MUST_BE_REFRESHED;

			return true;
		}
	}
}
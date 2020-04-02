#include "fbxloader.h"
#include <fbxsdk.h>
#include <fbxsdk/fileio/fbxiosettings.h>
using namespace sparky::maths;
namespace sparky {

	namespace geometry {

		void LoadCacheRecursive(FbxScene * pScene, FbxAnimLayer * pAnimLayer, const char * pFbxFileName, bool pSupportVBO)
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

					GLuint lTextureObject = 0;
					bool lStatus = LoadTextureFromFile(lFileName, lTextureObject);

					const FbxString lAbsFbxFileName = FbxPathUtils::Resolve(pFbxFileName);
					const FbxString lAbsFolderName = FbxPathUtils::GetFolderName(lAbsFbxFileName);
					if (!lStatus)
					{
						// Load texture from relative file name (relative to FBX file)
						const FbxString lResolvedFileName = FbxPathUtils::Bind(lAbsFolderName, lFileTexture->GetRelativeFileName());
						lStatus = LoadTextureFromFile(lResolvedFileName, lTextureObject);
					}

					if (!lStatus)
					{
						// Load texture from file name only (relative to FBX file)
						const FbxString lTextureFileName = FbxPathUtils::GetFileName(lFileName);
						const FbxString lResolvedFileName = FbxPathUtils::Bind(lAbsFolderName, lTextureFileName);
						lStatus = LoadTextureFromFile(lResolvedFileName, lTextureObject);
					}

					if (!lStatus)
					{
						FBXSDK_printf("Failed to load texture file: %s\n", lFileName.Buffer());
						continue;
					}

					if (lStatus)
					{
						GLuint * lTextureName = new GLuint(lTextureObject);
						lFileTexture->SetUserDataPtr(lTextureName);
					}
				}
			}

			LoadCacheRecursive(pScene->GetRootNode(), pAnimLayer, pSupportVBO);
		}


		bool fbxLoader::LoadMesh(const char* file, RawMesh& rmesh)
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
			bool lImportStatus = lImporter->Initialize(file, -1, lSdkManager->GetIOSettings());


			if (!lImportStatus) {
				printf("Call to FbxImporter::Initialize() failed.\n");
				printf("Error returned: %s\n\n", lImporter->GetStatus().GetErrorString());
				return false;
			}


			// File format version numbers to be populated.
			int lFileMajor, lFileMinor, lFileRevision;

			// Populate the FBX file format version numbers with the import file.
			lImporter->GetFileVersion(lFileMajor, lFileMinor, lFileRevision);


			FbxScene * mScene;
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

			// Bake the scene for one frame
			LoadCacheRecursive(mScene, mCurrentAnimLayer, mFileName, mSupportVBO);

			// Convert any .PC2 point cache data into the .MC format for 
			// vertex cache deformer playback.
			PreparePointCacheData(mScene, mCache_Start, mCache_Stop);

			// Get the list of pose in the scene
			FillPoseArray(mScene, mPoseArray);



		}
	}
}
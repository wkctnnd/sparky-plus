#include "fbxloader.h"
#include <fbxsdk.h>
#include <fbxfilesdk/fbxio/fbxiosettings.h>
using namespace sparky::maths;
namespace sparky {

	namespace geometry {
		void fbxLoader::LoadMesh(const char* file, RawMesh& rmesh)
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


			FbxClassId lShaderClassID = lSdkManager->FindFbxFileClass("Shader", "FlatShader");
			for (int i = 0; i < lNode->GetSrcObjectCount(lShaderClassID); i++) {
				FbxObject* lObject = lNode->GetSrcObject(lShaderClassID, i);
			}

		}
	}
}
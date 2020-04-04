#include "AssetLoader.h"
#include <algorithm>
#include "fbxloader.h"
namespace sparky {
	namespace asset {
		bool AssetLoader::Initialize()
		{
			m_FbxLoader = new class FBXLoader();

			m_FbxLoader->Initialize();

			return true;
		}
		void AssetLoader::LoadFile(std::string filename)
		{
			size_t pos = filename.find_last_of('.');
			std::string extension = filename.substr(pos + 1, filename.size() - pos + 1);
			transform(extension.begin(), extension.end(), extension.begin(), ::tolower);
			if (extension.compare("fbx"))
			{
				RawMesh mesh;
				m_FbxLoader->LoadMesh(filename.c_str(), mesh);
			}
		}
	
	}
}
#include "AssetLoader.h"
#include <algorithm>
#include "fbxloader.h"
#include "global.h"
#include <direct.h>
#include "utils/fileutils.h"
namespace sparky {
	namespace asset {

		AssetLoader* AssetLoader::m_Instance = 0;
		 AssetLoader* AssetLoader::INSTANCE()
		{
			if (!m_Instance)
			{
				 m_Instance = new AssetLoader();
			}
			return m_Instance;
		}
		bool AssetLoader::Initialize()
		{
 			m_FbxLoader = new FBXLoader();

			m_FbxLoader->Initialize();

			return true;
		}
		void AssetLoader::LoadFile(std::string filename)
		{
			std::string fullrelativepath = FileUtile::GetCurrentWorkingDirectory() + std::string(AssetFilePath) + filename;
			size_t pos = filename.find_last_of('.');
			std::string extension = filename.substr(pos + 1, filename.size() - pos + 1);
			transform(extension.begin(), extension.end(), extension.begin(), ::tolower);
			if (extension.compare("fbx") == 0)
			{
				//RawMesh mesh;
				m_FbxLoader->LoadFile(fullrelativepath.c_str());
				m_FbxLoader->LoadResources();
			}
		}

		RawSkinMesh* AssetLoader::GetRawSkinMesh(unsigned int id)
		{
			return m_FbxLoader->GetRawSkinMesh(id);
		}
		unsigned int AssetLoader::GetRawSkinMeshCount()
		{
			return m_FbxLoader->GetRawSkinMeshCount();
		}
		class RawMesh* AssetLoader::GetRawStaticMesh(unsigned int id)
		{
			return m_FbxLoader->GetRawStaticMesh(id);
		}
		unsigned int AssetLoader::GetRawStaticMeshCount()
		{
			return m_FbxLoader->GetRawStaticMeshCount();
		}

		Skeleton* AssetLoader::GetSkeleton(unsigned int id)
		{
			return m_FbxLoader->GetSkeleton(id);
		}
		unsigned int AssetLoader::GetSkeletonCount()
		{
			return m_FbxLoader->GetSkeletonCount();
		}

		unsigned int AssetLoader::GetClipCount()
		{
			return m_FbxLoader->GetClipCount();
		}

		class SkeletonClip* AssetLoader::GetClip(unsigned int id)
		{
			return m_FbxLoader->GetClip(id);
			
		}
	
		

		unsigned int AssetLoader::GetAnimationLayerCount()
		{
			return m_FbxLoader->GetAnimationLayerCount();
		}
 
		AnimationLayer* AssetLoader::GetAnimationLayer(unsigned int id)
		{
			return m_FbxLoader->GetAnimationLayer(id);
		}
	}
}

#include "AssetLoader.h"
#include <algorithm>
#include "fbxloader.h"
#include "global.h"
#include <direct.h>
#include "utils/fileutils.h"
#include "objloader.h"
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
 			//m_FbxLoader = new FBXLoader();

			//m_FbxLoader->Initialize();

			return true;
		}
		void AssetLoader::LoadFile(std::string filename)
		{
			std::string fullrelativepath = FileUtile::GetCurrentWorkingDirectory() + std::string(AssetFilePath);
			size_t pos = filename.find_last_of('.');
			std::string extension = filename.substr(pos + 1, filename.size() - pos + 1);
			transform(extension.begin(), extension.end(), extension.begin(), ::tolower);
			if (extension.compare("fbx") == 0)
			{
				m_MeshLoader =  new FBXLoader();
				m_MeshLoader->Initialize();
				//RawMesh mesh;
				m_MeshLoader->LoadFile(fullrelativepath, filename);
				m_MeshLoader->LoadResources();
			}
			else if (extension.compare("stl") == 0)
			{

			}
			else if (extension.compare("obj") == 0)
			{
				m_MeshLoader = new objLoader();
				m_MeshLoader->Initialize();
				//RawMesh mesh;
				m_MeshLoader->LoadFile(fullrelativepath, filename);
 				m_MeshLoader->LoadResources();
			}
			else if (extension.compare("bmp") || extension.compare("png") || extension.compare("jpg"))
			{
				//m_ImageLoader->
			}
		}

		RawSkinMesh* AssetLoader::GetRawSkinMesh(unsigned int id)
		{
			return m_MeshLoader->GetRawSkinMesh(id);
		}
		unsigned int AssetLoader::GetRawSkinMeshCount()
		{
			return m_MeshLoader->GetRawSkinMeshCount();
		}
		RawMesh* AssetLoader::GetRawStaticMesh(unsigned int id)
		{
			return m_MeshLoader->GetRawStaticMesh(id);
		}
		unsigned int AssetLoader::GetRawStaticMeshCount()
		{
			return m_MeshLoader->GetRawStaticMeshCount();
		}

		unsigned int AssetLoader::GetMaterialCount()
		{
			return m_MeshLoader->GetMaterialCount();
		}
		Material* AssetLoader::GetMaterial(unsigned int id)
		{
			return m_MeshLoader->GetMaterial(id);
		}

		Skeleton* AssetLoader::GetSkeleton(unsigned int id)
		{
			return m_MeshLoader->GetSkeleton(id);
		}
		unsigned int AssetLoader::GetSkeletonCount()
		{
			return m_MeshLoader->GetSkeletonCount();
		}

		unsigned int AssetLoader::GetClipCount()
		{
			return m_MeshLoader->GetClipCount();
		}

		class SkeletonClip* AssetLoader::GetClip(unsigned int id)
		{
			return m_MeshLoader->GetClip(id);
			
		}
	
		

		unsigned int AssetLoader::GetAnimationLayerCount()
		{
			return m_MeshLoader->GetAnimationLayerCount();
		}
 
		AnimationLayer* AssetLoader::GetAnimationLayer(unsigned int id)
		{
			return m_MeshLoader->GetAnimationLayer(id);
		}
	}
}

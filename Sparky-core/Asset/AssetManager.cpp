#include "AssetManager.h"
#include "AssetLoader.h"
#include "asset.h"
namespace sparky {
	namespace asset {
		void AssetManager::LoadAsset(std::string filepath)
		{
			AssetLoader loader;
			loader.LoadFile(filepath);

			for (int i=0;i<loader.GetRawStaticMeshCount();i++)
			{
				Asset* asset = (Asset*)(loader.GetRawStaticMesh(i));
				m_Assets.insert(std::make_pair(asset->GetVirtualPath(), asset));
			}

			for (int i=0;i<loader.GetMaterialCount();i++)
			{
				Asset* asset = (Asset*)(loader.GetMaterial(i));
				m_Assets.insert(std::make_pair(asset->GetVirtualPath(), asset));
			}
		}

		class Asset* AssetManager::GetAsset(std::string virtualpath)
		{
			if (m_Assets.find(virtualpath) != m_Assets.end())
				return m_Assets[virtualpath];
		}


		
	}
}

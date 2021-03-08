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
				m_AssetPools[asset->GetAssetType()].AddAsset(asset);
		/*		m_Assets.insert(std::make_pair(asset->GetVirtualPath(), asset));*/
			}

			for (int i=0;i<loader.GetMaterialCount();i++)
			{
				Asset* asset = (Asset*)(loader.GetMaterial(i));
				m_AssetPools[asset->GetAssetType()].AddAsset(asset);
			}
		}

		class Asset* AssetManager::GetAsset(AssetType type, std::string virtualpath)
		{
			AssetPool& pool = m_AssetPools[type];
			return pool.GetAsset(virtualpath);

	 
		}


		
	}
}

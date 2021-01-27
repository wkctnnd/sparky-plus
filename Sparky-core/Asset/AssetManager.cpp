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
				Asset* asset = (Asset*)loader.GetRawSkinMesh(i);
				m_Assets.insert(std::make_pair(asset->GetVirtualPath(), asset));
			}

		}
	}
}

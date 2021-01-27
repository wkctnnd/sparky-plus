#pragma once
#include <map>
namespace sparky {
	namespace asset {
		class AssetManager
		{
			void LoadAsset(std::string filepath);

			class Asset* GetAsset(std::string virtualpath);
		private:
			std::map<std::string, class Asset* > m_Assets;
		};
	}
}
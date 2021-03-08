#pragma once
#include <map>
#include "asset.h"
#include <vector>
#include <map>
namespace sparky {
	namespace asset {

		class VirtualPath
		{
		public:
			VirtualPath(std::string path)
			{

			}
			int GetIndex(std::string virtualpath)
			{

			}

		private:

			typedef std::map<std::string, int> RelativeIndexMap;
			static std::vector<RelativeIndexMap> m_RelativeIndexArray;

	 
		};

		class AssetPool
		{

		public:
			void AddAsset(Asset* asset)
			{
				m_Assets.insert(std::make_pair(asset->GetVirtualPath(), asset));
				//m_Assets.push_back(asset);
			}

			Asset* GetAsset(std::string virtualpath)
			{
				return m_Assets[virtualpath];
			}

		protected:

			//std::vector<Asset*> m_Assets;
			std::map<std::string, Asset*> m_Assets;
		};

		/*	template<class T>
			class AssetPool
			{
			public:
				void AddAsset(T* asset)
				{
					m_Assets.push_back(asset)
				}


			};*/




		class AssetManager
		{
		public:
			void LoadAsset(std::string filepath);


			Asset* GetAsset(AssetType type, std::string virtualpath);

			
			template<class T>
			T* GetAsset(std::string virtualpath);

	 
			class AssetPool& GetAssetPool(AssetType type)
			{
				return m_AssetPools[type];
			}
		private:
			AssetPool m_AssetPools[AssetType::AssetType_Num];
		};


		template<class T>
		T* AssetManager::GetAsset(std::string virtualpath)
		{

			return (T*)GetAsset(T::Type(), virtualpath);
		}


	}
}
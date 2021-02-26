#pragma once
#include <map>
#include "asset.h"
#include <vector>
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

		template<class T>
		class AssetPool
		{
		public:
			void AddAsset(T* asset)
			{
				m_AssetPool.push_back(asset)
			}

			T* GetAsset(int id)
			{
				return m_Assets[id];
			}

		private:
			
			std::vector<T*> m_Assets;
		};




		class AssetManager
		{
		public:
			void LoadAsset(std::string filepath);

			template<class T>
			T* GetAsset(int id)
			{
				AssetPool* pool = GetAssetPool<T>();
				if (pool)
				{
					return pool->GetAsset(id);
				}
				return 0;
			}

			class Asset* GetAsset(std::string virtualpath);

			template<class T>
			class AssetPool<T>* GetAssetPool()
			{
				return AssetPool<T>::
			}
		private:
			
		};
	}
}
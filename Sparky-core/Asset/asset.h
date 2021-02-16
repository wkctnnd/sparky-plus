#pragma once
#include <string>
namespace sparky
{
	namespace asset
	{
		enum AssetType
		{
			StaticMesh_Type,
			SkinMesh_Type,
			Skeleton_Type,
			Material_Type
		};

		class Asset
		{
		public:
			Asset(std::string path)
			{
				m_VirtualPath = path;
			}

			Asset(AssetType type)
			{
				static int meshid = 0;
				static int skinmeshid = 0;
				static int skeletonid = 0;
				switch (type)
				{
				case sparky::asset::StaticMesh_Type:
					//char* num = itoa(meshid);
					m_VirtualPath = "Content/Asset/StaticMesh/DefaultMesh" + std::to_string(meshid);
					meshid++;
					break;
				case sparky::asset::SkinMesh_Type:
					//char* num = itoa(meshid);
					m_VirtualPath = "Content/Asset/SkinMesh/DefaultSkinMesh" + std::to_string(skinmeshid);
					skinmeshid++;
					break;
				case sparky::asset::Skeleton_Type:
					m_VirtualPath = "Content/Asset/Skeleton/DefaultSkeleton" + std::to_string(skeletonid);
				default:
					break;
				}
			}

			std::string GetVirtualPath()
			{
				return m_VirtualPath;
			}

		protected:
			std::string m_AssetPath;
			std::string m_VirtualPath;
		};
	}
}

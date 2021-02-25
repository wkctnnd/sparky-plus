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
			Asset(std::string path, std::string name)
			{
				m_VirtualPath = path;
				m_Name = name;
			}

			Asset(AssetType type, std::string name)
			{
				m_Name = name;
				static int meshid = 0;
				static int skinmeshid = 0;
				static int skeletonid = 0;
				static int materialid = 0;
				switch (type)
				{
				case sparky::asset::StaticMesh_Type:
					//char* num = itoa(meshid);
					if (name.empty())
					{
						m_VirtualPath = "Content/Asset/StaticMesh/DefaultMesh" + std::to_string(meshid);
						meshid++;
					}
					else
						m_VirtualPath = "Content/Asset/StaticMesh/" + name;
					break;
				case sparky::asset::SkinMesh_Type:
					//char* num = itoa(meshid);
					if (name.empty())
					{
						m_VirtualPath = "Content/Asset/SkinMesh/DefaultSkinMesh" + std::to_string(skinmeshid);
						skinmeshid++;
					}
					else
					{
						m_VirtualPath = "Content/Asset/SkinMesh/" + name;
					}
					break;
				case sparky::asset::Skeleton_Type:
					if (name.empty())
					{
						m_VirtualPath = "Content/Asset/Skeleton/DefaultSkeleton" + std::to_string(skeletonid);
						skeletonid++;
					
					}
					else
					{
						m_VirtualPath = "Content/Asset/Skeleton" + name;
					}
					break;
				case sparky::asset::Material_Type:
					if (name.empty())
					{
						m_VirtualPath = "Content/Asset/Material/DefaultMaterial" + std::to_string(materialid);
						materialid++;

					}
					else
						m_VirtualPath = "Content/Asset/Material/DefaultMaterial" + name;
					break;
				default:
					break;
				}
			}

			std::string GetVirtualPath()
			{
				return m_VirtualPath;
			}

			void SetName(std::string name)
			{
				m_Name = name;
			}

			std::string GetName()
			{
				return m_Name;
			}
		protected:
			std::string m_AssetPath;
			std::string m_VirtualPath;

			std::string m_Name;
		};
	}
}

#pragma once
#include "Asset/meshloader.h"
#include <vector>
namespace sparky
{
	namespace asset
	{
		class Material;
		class RawMesh;
		class objLoader :public meshLoader
		{
		public:
			static bool LoadMesh(const char* file, class RawMesh& rmesh);


			//virtual bool LoadMesh(const char* file, class RawMesh& rmesh) { return false; }
			virtual void LoadResources() {};
			virtual bool LoadFile(std::string fileDir, std::string filename);

			void LoadMaterial(const char* file);
			//virtual class RawSkinMesh* GetRawSkinMesh(unsigned int id) { return 0; }
			//virtual unsigned int GetRawSkinMeshCount() { return 0; };
			virtual class RawMesh* GetRawStaticMesh(unsigned int id) { return m_Meshs[id]; }
			unsigned int GetRawStaticMeshCount() { return m_Meshs.size(); }
			unsigned  int GetMaterialCount();
			class Material* GetMaterial(unsigned int id);
			unsigned int GetClipCount() { return 0; }

			unsigned int GetSkeletonCount() { return 0; }

			class Skeleton* GetSkeleton(unsigned int id) { return 0; }

			class SkeletonClip* GetClip(unsigned int id) { return 0; }
			unsigned int GetAnimationLayerCount() { return 0; }
			class AnimationLayer* GetAnimationLayer(int id) { return 0; }

		private:

			std::vector<RawMesh*> m_Meshs;
			std::vector<Material*> m_Materials;
		};
	}
}

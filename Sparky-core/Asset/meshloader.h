#pragma once
#include <string>
namespace sparky {
	namespace asset {
		class meshLoader
		{
			public:

				virtual void Initialize() {};
				//virtual bool LoadMesh(const char* file, class RawMesh& rmesh) { return false; }
				virtual void LoadResources() {}
				virtual bool LoadFile(std::string fileDir, std::string filename) { return false; };
				virtual class RawSkinMesh* GetRawSkinMesh(unsigned int id) { return 0; }
				virtual unsigned int GetRawSkinMeshCount() { return 0; };
				virtual class RawMesh* GetRawStaticMesh(unsigned int id) { return 0; }
				virtual unsigned int GetRawStaticMeshCount() { return 0; }
				virtual unsigned  int GetMaterialCount() { return 0; }
				virtual class Material* GetMaterial(unsigned int id) { return 0; }
				virtual unsigned int GetClipCount() { return 0; }

				virtual unsigned int GetSkeletonCount() { return 0; }

				virtual class Skeleton* GetSkeleton(unsigned int id) { return 0; }

				class SkeletonClip* GetClip(unsigned int id) { return 0; }
				unsigned int GetAnimationLayerCount() { return 0; }
				class AnimationLayer* GetAnimationLayer(int id) { return 0; }
		};
	}
}
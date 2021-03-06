#pragma once
#include <string>

namespace sparky {
	namespace animation
	{
		class AnimationLayer;
	}
}

using namespace sparky::animation;
namespace sparky {
	namespace asset {
		class RawMesh;
		class AssetLoader
		{
		public:
			AssetLoader() {};
			bool Initialize();
			void LoadFile(std::string filename);
			static AssetLoader* INSTANCE();

			class RawSkinMesh* GetRawSkinMesh(unsigned int id);
		
			unsigned int GetRawSkinMeshCount();
			//"public: class sparky::asset::RawMesh * __cdecl sparky::asset::AssetLoader::GetRawStaticMesh(unsigned int)"
			RawMesh* GetRawStaticMesh(unsigned int id);
			unsigned int GetRawStaticMeshCount();

			class Skeleton* GetSkeleton(unsigned int id);
			unsigned int GetSkeletonCount();
			unsigned int GetClipCount();
			class Material* GetMaterial(unsigned int id);
			unsigned  int GetMaterialCount();
			unsigned int GetAnimationLayerCount();
			AnimationLayer* GetAnimationLayer(unsigned int id);
			class SkeletonClip* GetClip(unsigned int id);
		private:
			class objLoader *m_ObjLoader;
			class FBXLoader *m_FbxLoader;
			class stlLoader *m_StlLoader;
			class ImageLoader *m_ImageLoader;
			static AssetLoader* m_Instance;

			class meshLoader* m_MeshLoader;
		private:
			
		};

		
	}
}


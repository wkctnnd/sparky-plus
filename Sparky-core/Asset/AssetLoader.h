#pragma once
#include <string>

namespace sparky {
	namespace asset {
		class AssetLoader
		{
		public:
			bool Initialize();
			void LoadFile(std::string filename);
			static AssetLoader* INSTANCE();

			class RawSkinMesh* GetRawSkinMesh(unsigned int id);
		
			unsigned int GetRawSkinMeshCount();
			class RawMesh* GetRawStaticMesh(unsigned int id);
			unsigned int GetRawStaticMeshCount();


			unsigned int GetClipCount();

			class SkeletonClip* GetClip(unsigned int id);
		private:
			class objLoader *m_ObjLoader;
			class FBXLoader *m_FbxLoader;

			static AssetLoader* m_Instance;
		private:
			AssetLoader() {};
		};

		
	}
}


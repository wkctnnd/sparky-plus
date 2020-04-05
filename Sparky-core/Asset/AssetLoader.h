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
		private:
			class objLoader *m_ObjLoader;
			class FBXLoader *m_FbxLoader;

			static AssetLoader* m_Instance;
		private:
			AssetLoader() {};
		};
	}
}
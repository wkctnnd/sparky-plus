#pragma once
#include <string>
namespace sparky {
	namespace asset {
		class AssetLoader
		{
		public:
			bool Initialize();
			void LoadFile(std::string filename);
		private:
			class objLoader *m_ObjLoader;
			class FBXLoader *m_FbxLoader;
			 
		};
	}
}
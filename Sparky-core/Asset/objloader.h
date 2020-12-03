#pragma once
#include "Asset/meshloader.h"
namespace sparky {
	namespace asset {
		class objLoader 
		{
		public:
			static bool LoadMesh(const char* file, class RawMesh& rmesh);

		};
	}
}

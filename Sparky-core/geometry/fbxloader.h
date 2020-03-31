#pragma once
#include "utils/fileutils.h"
#include "geometry/rawmesh.h"
namespace sparky {
	namespace geometry {
		class fbxLoader
		{
		public:
			static bool LoadMesh(const char* file, RawMesh& rmesh);

		};
	}
}

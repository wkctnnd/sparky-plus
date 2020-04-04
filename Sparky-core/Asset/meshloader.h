#pragma once
namespace sparky {
	namespace asset {
		class meshLoader
		{
			public:
				virtual bool LoadMesh(const char* file, class RawMesh& rmesh) = 0;
		};
	}
}
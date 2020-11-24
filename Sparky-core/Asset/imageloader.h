#pragma once

#include <string>
namespace sparky
{
	namespace asset
	{
		class ImageLoader
		{
		public:
			bool LoadFile(const char* file);
			void LoadResources();
			void SaveToBmp(void* data, int width, int height, int component, std::string file);
		};
	}
}
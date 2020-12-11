#pragma once

#include <string>
namespace sparky
{
	namespace graphics
	{
		class Texture;
	}
	namespace asset
	{
		class ImageLoader
		{
		public:
			graphics::Texture* LoadFile(const char* file);
			void LoadResources();
			void SaveToBmp(void* data, int width, int height, int component, std::string file);
		};
	}
}
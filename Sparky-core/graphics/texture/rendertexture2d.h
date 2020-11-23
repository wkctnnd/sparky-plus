#pragma once
#include "rendertexture.h"
namespace sparky {
	namespace graphics {

		class RenderTexture2D:public RenderTexture
		{
		public:
			RenderTexture2D(int width, int height, Format format);

			void SaveToDisk(std::string file);

			void ReadPixel(int offsetx, int offsety, int width, int height, void* data);
		};

	}
}
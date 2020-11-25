#include "miniheader.h"
#include "imageloader.h"
#include "Asset/stb_image_write.h"

namespace sparky
{
	namespace asset
	{
		bool ImageLoader::LoadFile(const char* file)
		{

			return true;
		}


		void ImageLoader::SaveToBmp(void* data, int width, int height, int component, std::string file)
		{
			stbi_write_bmp(file.c_str(), width, height, component, data);
		}
	}
}
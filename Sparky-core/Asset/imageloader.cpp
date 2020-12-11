#include "miniheader.h"
#include "imageloader.h"
#include "Asset/stb_image_write.h"
#include "asset/stb_image.h"
#include "graphics/texture/texture2d.h"
using namespace sparky::graphics;
namespace sparky
{
	namespace asset
	{
		Texture* ImageLoader::LoadFile(const char* file)
		{
			int x, y, n;
			unsigned char *data = stbi_load("filename", &x, &y, &n, 0);
			// filename : �ļ���
			// x : ͼƬ�� 
			// y : ͼƬ��
			// n : ��ɫͨ������
			// ���һ��Ϊ�Լ����õ���ɫͨ�������������0�Ͱ��մ���ֵ��ȡͼ��
			// ����ֵ��NULL˵������ɹ�
			// Do Something
			stbi_image_free(data);
			switch (n)
			{
			case 3:
				return new Texture2D(x, y, Format::RGB, data);
			case 4:
				return new Texture2D(x, y, Format::RGBA, data);
			default:
				break;
			}
			return 0;
		}


		void ImageLoader::SaveToBmp(void* data, int width, int height, int component, std::string file)
		{
			stbi_write_bmp(file.c_str(), width, height, component, data);
		}
	}
}
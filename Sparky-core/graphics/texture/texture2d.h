#pragma once
#include "texture.h"
namespace sparky
{
	namespace graphics
	{
		class Texture2D:public Texture
		{
			Texture2D(int width, int height, Format format, void* data = 0);
		};
	}
}
#pragma once
#include "texture.h"
namespace sparky
{
	namespace graphics
	{
		class Texture2D:public Texture
		{
			Texture2D(int width, int height, Format format, void* data = 0);
			void SaveToDisk(std::string file);
			virtual void Bind()const;
			virtual void UnBind()const;
		};
	}
}
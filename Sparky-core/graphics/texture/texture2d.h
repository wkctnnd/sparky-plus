#pragma once
#include "texture.h"
#include "maths/vec3.h"
namespace sparky
{
	namespace graphics
	{
		class Texture2D:public Texture
		{
			Texture2D(int width, int height, Format format, void* data);
			void SaveToDisk(std::string file);
			virtual void Bind()const;
			virtual void UnBind()const;
			void LoadMipData(int miplevel, int3 offset, int3 rect, void* data);
		};
	}
}
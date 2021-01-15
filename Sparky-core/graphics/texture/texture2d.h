#pragma once
#include "texture.h"
#include "maths/vec3.h"
namespace sparky
{
	namespace graphics
	{
		class Texture2D :public Texture
		{
		public:
			Texture2D(int width, int height, Format format, void* data);
			void SaveToDisk(std::string file);
			virtual int Bind()const;
			virtual void UnBind()const;
			virtual void* Lock(unsigned int offset, unsigned int size) const { return 0; };
			virtual void unLock() const {};
			void LoadMipData(int miplevel, int3 offset, int3 rect, void* data);
		};
	}
}
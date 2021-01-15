#pragma once
#include <gl/glew.h>
#include <string>
#include "maths/vec3.h"
using namespace sparky::maths;
namespace sparky
{
	namespace graphics
	{

		enum Format
		{
			RGBA,
			RGB,
			DXT1,
			DXT2,
			DXT5,

			DEPTH32,
			DEPTH24,
			DEPTH24STENCILl8,
		};

		enum Type
		{
			UNSIGNED_BYTE,
			UNSIGNED_INT_24_8
		};

		enum WarpMode
		{
			RPEAT,
			CLAMP
		};
		class Texture
		{
		public:

			Texture(int w, int h, int depth, Format f);
			virtual int Bind() const = 0;
			virtual void UnBind() const = 0;
			GLuint GetRealId() 
			{ 

				return m_TexId; 
			}
			virtual void* Lock(unsigned int offset, unsigned int size) const = 0;
			virtual void unLock() const = 0;
			virtual void LoadMipData(int miplevel, int3 offset, int3 rect, void* data) = 0;

			virtual void SaveToDisk(std::string file) = 0;
			int Width() { return m_Width; }
			int Height() { return m_Height; }
			int Depth() { return m_Depth; }
			Format TexFormat() { return m_Formt; }
			Type TexType() { return m_Type; }
			int GetElementSize()
			{
				int size = 0;
				switch (m_Formt)
				{
				case sparky::graphics::RGBA:
					size = 4;
					break;
				case sparky::graphics::RGB:
					break;
				case sparky::graphics::DXT1:
					break;
				case sparky::graphics::DXT2:
					break;
				case sparky::graphics::DXT5:
					break;
				case sparky::graphics::DEPTH24:
					break;
				case sparky::graphics::DEPTH24STENCILl8:
					break;
				default:
					break;
				}

				return size;
			}
			unsigned int GetTextureID() { return m_TexId; }
		protected:
			unsigned int m_TexId;
			int m_Width;
			int m_Height;
			int m_Depth;
			Format m_Formt;
			Type m_Type;
			WarpMode m_WarpMode;

			int m_MipMap;
			int m_Border;

			//int m_BindIndex;
		};

	}
}
 
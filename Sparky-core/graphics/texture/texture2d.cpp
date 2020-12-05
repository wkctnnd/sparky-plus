#pragma once
#include "texture2d.h"
#include "maths/vec2.h"
using namespace sparky::maths;
namespace sparky
{
	namespace graphics
	{

		Texture2D::Texture2D(int width, int height, Format format, void* data = 0):Texture(width, height, 1,format)
		{
			glGenTextures(1, &m_TexId);
			Bind();
			GLenum texformat;
			GLenum textype;
			GLenum srctype;
			switch (format)
			{
			case sparky::graphics::RGBA:
				texformat = GL_RGBA;
				textype = GL_UNSIGNED_BYTE;
				srctype = GL_RGBA;
				m_Type = UNSIGNED_INT_24_8;
				break;
			case sparky::graphics::RGB:
				texformat = GL_RGB;
				textype = GL_UNSIGNED_BYTE;
				srctype = GL_RGB8;
				break;
			case sparky::graphics::DXT1:
				break;
			case sparky::graphics::DXT2:
				break;
			case sparky::graphics::DXT5:
				break;
			case sparky::graphics::DEPTH32:
				texformat = GL_DEPTH;
				textype = GL_RED_INTEGER;
				srctype = GL_DEPTH_COMPONENT32;
				break;
			case sparky::graphics::DEPTH24:
				texformat = GL_DEPTH;
				textype = GL_RED_INTEGER;
				srctype = GL_DEPTH_COMPONENT32;
				break;
			case sparky::graphics::DEPTH24STENCILl8:
				texformat = GL_DEPTH_STENCIL;
				textype = GL_UNSIGNED_INT_24_8;
				srctype = GL_DEPTH24_STENCIL8;
				m_Type = UNSIGNED_INT_24_8;
				break;
			default:
				break;
			}
			glTexImage2D(GL_TEXTURE_2D, 0, srctype, width, height, 0, texformat, textype, data);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
			UnBind();
			
		}
		void Texture2D::SaveToDisk(std::string file)
		{

		}


		void Texture2D::Bind()const
		{
			glBindTexture(GL_TEXTURE_2D, m_TexId);
		}
		void Texture2D::UnBind()const
		{
			glBindTexture(GL_TEXTURE_2D, 0);
		}

		void Texture2D::LoadMipData(int miplevel, int3 offset, int3 rect, void* data)
		{
			if (data)
			{
				glTexSubImage2D(GL_TEXTURE_2D, miplevel, offset.x, offset.y, rect.x, rect.y, GL_RGB, GL_UNSIGNED_BYTE, data);
			}
		}

	}
}
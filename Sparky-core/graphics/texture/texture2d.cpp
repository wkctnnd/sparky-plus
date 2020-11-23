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
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
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
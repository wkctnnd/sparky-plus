#pragma once

#include "rendertexture2d.h"
#include "maths/vec2.h"
#include "gl/glew.h"
#include "texture.h"
#include "Asset/imageloader.h"
#include "texture2d.h"
using namespace sparky::maths;
using namespace sparky::asset;
namespace sparky
{
	namespace graphics
	{

		RenderTexture2D::RenderTexture2D(int width, int height, Format format):RenderTexture(width,height,format)
		{
			m_Texture = new Texture2D(width, height, format, 0);
		}


		void RenderTexture2D::SaveToDisk(std::string file)
		{
			int width = m_Texture->Width();
			int height = m_Texture->Height();
			void *data = new char[m_Texture->Width()*m_Texture->Height()*m_Texture->GetElementSize()];
			ReadPixel(0, 0, m_Texture->Width(), m_Texture->Height(), data);
			if (m_Texture->TexFormat() == DEPTH24STENCILl8)
			{
				void* outputdata = new char[width*height * 4];
				ConvertDepthData(data, outputdata, width, height);
			}
			ImageLoader loader;
			loader.SaveToBmp(data, m_Texture->Width(), m_Texture->Height(), 4, file);
		}


		//gl代码和 抽象层代码混在一起，感觉需要rhi结构
		void RenderTexture2D::ReadPixel(int x, int y, int w, int h, void* data)
		{
			GLuint framebufferid;
			glGenFramebuffers(1, &framebufferid);
			glBindFramebuffer(GL_FRAMEBUFFER, framebufferid);
			m_Texture->Bind();
			glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, m_Texture->GetTextureID(), 0);
			glViewport(0, 0, w, h);
			glReadPixels(x, y, w, h, GL_RGBA, GL_UNSIGNED_BYTE, data);
			glBindFramebuffer(GL_FRAMEBUFFER, 0);
			m_Texture->UnBind();

			
		}


		void RenderTexture2D::ConvertDepthData(void* inputdata, void* outputdata, int width, int height)
		{
			float* data = (float*)inputdata;
			if (data)
			{
				for (int i=0;i<height;i++)
				{
					for (int  j = 0; j < width; j++)
					{
						float a = data[i*width+j];
						//a = a >> 8;

					}
				}

			}
		}
	}
}
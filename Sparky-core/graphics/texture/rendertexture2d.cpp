#pragma once

#include "rendertexture2d.h"
#include "maths/vec2.h"
#include "gl/glew.h"
#include "texture.h"
#include "Asset/imageloader.h"
#include "texture2d.h"
#include "../errorreport.h"
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
			void* savedata = data;
			ReadPixel(0, 0, m_Texture->Width(), m_Texture->Height(), data);



 			if (m_Texture->TexFormat() == DEPTH24STENCILl8)
			{
				void* outputdata = new char[width*height * 4];
				ConvertDepthData(data, outputdata, width, height);
				savedata = outputdata;
			}


			//revert image
			{
				void* outputdata = new char[width*height * 4];
				ReverseImage(savedata, outputdata, width, height);
				savedata = outputdata;
			}


			ImageLoader loader;
			ErrorCode code = ErrorReport::GetError();
			if (code != NO_ERROR)
			{
				int a = 1;
			}
			//memset(savedata, 0, width*height * 3);
			loader.SaveToBmp(savedata, m_Texture->Width(), m_Texture->Height(), 4, file);
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
			GLenum datatype;
			GLenum dataformat;
			switch (m_Texture->TexFormat())
			{
				case RGBA:
				{
					datatype = GL_UNSIGNED_BYTE;
					dataformat = GL_RGBA;
					break;
				}
				case DEPTH24STENCILl8:
				{
					datatype = GL_UNSIGNED_INT_24_8;
					dataformat = GL_DEPTH_STENCIL;
					break;
				}
			}
			glReadPixels(x, y, w, h, dataformat, datatype, data);
			glBindFramebuffer(GL_FRAMEBUFFER, 0);
			m_Texture->UnBind();

			ErrorCode error = ErrorReport::GetError();
			if (error != GL_NO_ERROR)
			{
				int a = 1;
			}
		}


		void RenderTexture2D::ConvertDepthData(void* inputdata, void* outputdata, int width, int height)
		{
			unsigned int* data = (unsigned int*)inputdata;
			char *odata = (char*)outputdata;
			if (data)
			{
				for (int i=0;i<height;i++)
				{
					for (int  j = 0; j < width; j++)
					{
					int index = i * width + j;
					/*		unsigned int a = data[index];
						a = a >> 8;
						int temp = (int)((float)(a) / 16777216.0f * 255);*/
						odata[4 * index] = 0;
						odata[4*index +1] = 0;
						odata[4 * index + 2] = 0;
						odata[4 * index + 3] = 0;
					}
				}

			}
		}

		void RenderTexture2D::ReverseImage(void* inputdata, void* outputdata, int width, int height)
		{
			unsigned int* data = (unsigned int*)inputdata;
			char *odata = (char*)outputdata;
			if (data)
			{
				for (int i = 0; i<height; i++)
				{
					for (int j = 0; j < width; j++)
					{
						int index = i * width + j;
						int index2 = (height - i)*width + j;
						/*		unsigned int a = data[index];
						a = a >> 8;
						int temp = (int)((float)(a) / 16777216.0f * 255);*/
						odata[4 * index] = ((char*)(inputdata))[4 * index2];
						odata[4 * index + 1] = ((char*)(inputdata))[4 * index2 + 1];
						odata[4 * index + 2] = ((char*)(inputdata))[4 * index2 + 2];
						odata[4 * index + 3] = ((char*)(inputdata))[4 * index2 + 3];
					}
				}

			}
		}
	}
}
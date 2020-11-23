#pragma once
#include <gl/glew.h>
#include <string>
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

			DEPTH24,
			DEPTH24STENCILl8,
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
			virtual void Bind() const;
			virtual void UnBind() const;
			 
			virtual void* Lock(unsigned int offset, unsigned int size) const;
			virtual void unLock() const;
			virtual void LoadMipData(int miplevel, int3 offset, int3 rect, void* data);

			void SaveToDisk(std::string file);

			unsigned int GetTextureID() { return m_TexId; }
		protected:
			unsigned int m_TexId;
			int m_Width;
			int m_Height;
			int m_Depth;
			Format m_Formt;
			WarpMode m_WarpMode;

			int m_MipMap;
			int m_Border;
		};

	}
}
 
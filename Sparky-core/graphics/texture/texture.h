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
			DXT5
		};



		enum WarpMode
		{
			RPEAT,
			CLAMP
		};
		class Texture
		{
		public:

		 
			virtual void Bind() const;
			virtual void UnBind() const;
			 
			virtual void* Lock(unsigned int offset, unsigned int size) const;
			virtual void unLock() const;

			void SaveToDisk(std::string file);
		protected:
			int m_TexId;
			int m_Width;
			int m_Height;
			int m_Depth;
		};

	}
}
 
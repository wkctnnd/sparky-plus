#pragma once
#include <gl/glew.h>
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
		class Texture
		{
		public:

		 
			void Bind() const;
			void unBind() const;
			 
			virtual void* Lock(unsigned int offset, unsigned int size) const;
			virtual void unLock() const;

		protected:
			int m_TexId;
			int m_Width;
			int m_Height;
			int m_Depth;
		};

	}
}
 
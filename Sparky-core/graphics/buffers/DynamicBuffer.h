#pragma once
#include <gl/glew.h>
#include "buffer.h"
namespace sparky
{
	namespace graphics
	{
		class DynamicBuffer :public Buffer
		{

		public:
			DynamicBuffer(GLfloat* data, GLsizei count, GLuint componentCount);

			void* Lock(unsigned int offset, unsigned int size) const;
			void unLock() const;

		};
	}
}
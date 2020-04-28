#include "staticbuffer.h"

namespace sparky
{
	namespace graphics
	{
		StaticBuffer::StaticBuffer(void* data, int count, unsigned int componentCount)
		{
			m_ComponentCount = componentCount;
			glGenBuffers(1, &m_BufferID);
			glBindBuffer(GL_ARRAY_BUFFER, m_BufferID);
			glBufferData(GL_ARRAY_BUFFER, count * sizeof(GLfloat), data, GL_STATIC_DRAW);
			glBindBuffer(GL_ARRAY_BUFFER, 0);
		}


	}
}
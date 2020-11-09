#include "DynamicBuffer.h"

namespace sparky
{
	namespace graphics
	{
		DynamicBuffer::DynamicBuffer(GLfloat* data, GLsizei count, GLuint componentCount)
		{
			m_Count = count/ componentCount;
			m_ComponentCount = componentCount;
			glGenBuffers(1, &m_BufferID);
			glBindBuffer(GL_ARRAY_BUFFER, m_BufferID);
			glBufferData(GL_ARRAY_BUFFER, count * sizeof(GLfloat), data, GL_DYNAMIC_DRAW);
			glBindBuffer(GL_ARRAY_BUFFER, 0);
		}


		void* DynamicBuffer::Lock(unsigned int offset, unsigned int size)const
		{
			bind();
			void *data = glMapBufferRange(GL_ARRAY_BUFFER, offset, size, GL_MAP_WRITE_BIT);
			unBind();
			return data;
		}

		void DynamicBuffer::unLock() const
		{
			bind();
			glUnmapBuffer(GL_ARRAY_BUFFER);
			unBind();
		}
	}
}
#include "uniformbuffer.h"

namespace sparky
{
	namespace graphics
	{
		UniformBuffer::UniformBuffer(GLfloat* data, GLsizei datasize, bool dynamic)
		{
			m_Count = count;
			glGenBuffers(1, &m_BufferID);
			glBindBuffer(GL_UNIFORM_BUFFER, m_BufferID);
			glBufferData(GL_UNIFORM_BUFFER, datasize, data, dynamic? GL_DYNAMIC_DRAW:GL_STATIC_DRAW);
			glBindBuffer(GL_UNIFORM_BUFFER, 0);

		}

		void UniformBuffer::bind() const
		{
			glBindBuffer(GL_UNIFORM_BUFFER, m_BufferID);
		}

		void UniformBuffer::unBind() const
		{
			glBindBuffer(GL_UNIFORM_BUFFER, 0);
		}

		unsigned int UniformBuffer::count() const
		{
			return m_Count;
		}
	}
}
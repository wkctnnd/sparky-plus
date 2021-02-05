#include "uniformbuffer.h"

namespace sparky
{
	namespace graphics
	{

		void UniformBufferParameter::AddElement(float4 value)
		{
			ElementLayout elementlayout;
			if (m_Layout.size() > 0)
				elementlayout.offset = m_Layout[m_Layout.size() - 1].offset + m_Layout[m_Layout.size() - 1].bytecount;
			elementlayout.bytecount = 4;
			elementlayout.realbytecount = 4;
			m_Layout.push_back(elementlayout);
		}	


		void UniformBufferParameter::AddElement(float value)
		{
			ElementLayout elementlayout;
			if (m_Layout.size() > 0)
				elementlayout.offset = m_Layout[m_Layout.size() - 1].offset + m_Layout[m_Layout.size() - 1].bytecount;
			elementlayout.bytecount = 1;
			elementlayout.realbytecount = 4;
			m_Layout.push_back(elementlayout);
		}

		void UniformBufferParameter::AddElement(float3 value)
		{
			ElementLayout elementlayout;
			if (m_Layout.size() > 0)
				elementlayout.offset = m_Layout[m_Layout.size() - 1].offset + m_Layout[m_Layout.size() - 1].bytecount;
			elementlayout.bytecount = 3;
			elementlayout.realbytecount = 4;
			m_Layout.push_back(elementlayout);
		}

		//void UniformBufferParameter::AddElement(Texture2D)

		UniformBuffer::UniformBuffer(GLfloat* data, GLsizei datasize, bool dynamic)
		{
			//m_Count = count;
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

		//unsigned int UniformBuffer::count()
		//{
		//	return m_Count;
		//}
	}
}
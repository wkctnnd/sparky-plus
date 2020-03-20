#pragma once

#include <gl/glew.h>
namespace sparky
{
	namespace graphics
	{
		class Buffer
		{
		protected:
			GLuint m_BufferID;
			GLuint m_ComponentCount;
		public:
			//Buffer(GLfloat* data, GLsizei count, GLuint componentCount);

			GLuint GetComponentCount() const;
			void bind() const;
			void unBind() const;

			virtual void* Lock(unsigned int offset, unsigned int size) const;
			virtual void unLock() const;

		};
	}
}

#pragma once
#include <gl/glew.h>
#include "maths/mat4.h"
#include "maths/vec2.h"
#include "maths/vec3.h"
#include "maths/vec4.h"

#include "glm/gtc/matrix_transform.hpp"
using namespace sparky::maths;
namespace sparky {
	namespace graphics {
		class UniformBuffer
		{



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
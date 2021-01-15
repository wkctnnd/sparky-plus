#pragma once

#include <gl/glew.h>
#include "maths/mat4.h"
#include "maths/vec2.h"
#include "maths/vec3.h"
#include "maths/vec4.h"
#include "computebuffer.h"
#include "glm/gtc/matrix_transform.hpp"
#include <vector>
using namespace sparky::maths;
namespace sparky {
	namespace graphics {
		class ShaderBindingLayout
		{

		};

		class ShaderBinding
		{
		public:
			ShaderBinding() {}

	
			
			std::vector<ShaderBindingLayout> m_ShaderBindingLayouts;
		};
	}
}
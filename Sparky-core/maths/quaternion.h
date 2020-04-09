#pragma once
 
#include "vec4.h"
namespace sparky {
	namespace maths {
		class Quaternion
		{
		public:
			Quaternion() { m_Element.x = 0; m_Element.y = 0; m_Element.z = 0; m_Element.w = 0; };
			Quaternion(float x, float y, float z, float w) {}

		private:
			vec4 m_Element;
		};

	}
}
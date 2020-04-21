#pragma once
 
#include "vec4.h"
#include "mat4.h"
namespace sparky {
	namespace maths {
		class Quaternion
		{
		public:
			Quaternion() { m_Element.x = 0; m_Element.y = 0; m_Element.z = 0; m_Element.w = 0; };
			Quaternion(float x, float y, float z, float w) {}
			inline float X() { return m_Element.x; }
			inline float Y() { return m_Element.y; }
			inline float Z() { return m_Element.z; }
			inline float W() { return m_Element.w; }
			mat4 GetMatrix();
			Quaternion& operator +=(Quaternion left);
			friend Quaternion operator*(Quaternion left, float scale);
		private:
			vec4 m_Element;
		};

	}
}
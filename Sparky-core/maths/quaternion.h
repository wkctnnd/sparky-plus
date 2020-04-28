#pragma once
 
#include "vec4.h"
#include "mat4.h"
namespace sparky {
	namespace maths {
		class Quaternion
		{
		public:
			Quaternion() { x = 0; y = 0; z = 0; w = 0; };
			Quaternion(float x, float y, float z, float w) { this->x = x; this->y = y; this->z = z; this->w = w; }
			/*inline float X() { return m_Element.x; }
			inline float Y() { return m_Element.y; }
			inline float Z() { return m_Element.z; }
			inline float W() { return m_Element.w; }*/
			mat4 GetMatrix();
			Quaternion& operator +=(Quaternion left);
			static Quaternion FromEulerXYZ(float x, float y, float z);
			friend Quaternion operator*(Quaternion left, float scale);
		 
			void SetElement(unsigned int i, float value);

			float x;
			float y;
			float z;
			float w;
		};

	}
}
#include "quaternion.h"

namespace sparky {
	namespace maths {

		mat4 Quaternion::GetMatrix()
		{
			mat4 result;

			return result;
		}
	
		Quaternion& Quaternion::operator +=(Quaternion left)
		{
			return *this;
		}

		Quaternion operator*(Quaternion left, float scale)
		{
			Quaternion result;

			return result;
		}

		void Quaternion::SetElement(unsigned int i, float value)
		{
			float *v = &x;
			*(v + i) = value;
		}
	}
}
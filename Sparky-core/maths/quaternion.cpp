#include "quaternion.h"
#include "maths/util.h"

using namespace sparky::maths;
namespace sparky {
	namespace maths {

		Quaternion Quaternion::FromEulerXYZ(float x, float y, float z)
		{
			float sy = Util::Sin(y / 2);
			float sz = Util::Sin(z / 2);
			float sx = Util::Sin(x / 2);

			float cx = Util::Cos(x / 2);
			float cy = Util::Cos(y / 2);
			float cz = Util::Cos(z / 2);


			float a = sy * sz*cx + cy * cz*sx;
			float b = sy * cz*cx + cy * sz*sx;
			float c = cy * sz*cx - sy * cz*sx;
			float d = cy * cz*cx - sy * sz*sx;

			return Quaternion(a, b, c, d);
		}

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
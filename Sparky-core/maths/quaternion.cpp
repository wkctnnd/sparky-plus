#include "quaternion.h"
#include "maths/util.h"

using namespace sparky::maths;
namespace sparky {
	namespace maths {

		//https://zhuanlan.zhihu.com/p/45404840
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
			x += left.x;
			y += left.y;
			z += left.z;
			w += left.w;
			return *this;
		}


		//ÓÐÎÊÌâ
		Quaternion operator*(Quaternion left, float scale)
		{
			Quaternion result;
			result.x = left.x * scale;
			result.y = left.y * scale;
			result.z = left.z * scale;
			result.w = left.w * scale;
			return result;
		}

		void Quaternion::SetElement(unsigned int i, float value)
		{
			float *v = &x;
			*(v + i) = value;
		}
	 
		//https://blog.csdn.net/shenshen211/article/details/78492055
		Quaternion& Quaternion::operator *=(Quaternion& other)
		{
			 this->w = this->w*other.w-this->x*other.x-this->y*other.y-this->z*other.z;
			 this->x= this->w*other.w + this->x*other.x + this->y*other.y - this->z*other.z;
			 this->y = this->w*other.w - this->x*other.x + this->y*other.y + this->z*other.z;
			 this->z = this->w*other.w + this->x*other.x - this->y*other.y + this->z*other.z;

			 return *this;
			/*q1 * q2 =
				(w1*w2 - x1 * x2 - y1 * y2 - z1 * z2) +
				(w1*x2 + x1 * w2 + y1 * z2 - z1 * y2) i +
				(w1*y2 - x1 * z2 + y1 * w2 + z1 * x2) j +
				(w1*z2 + x1 * y2 - y1 * x2 + z1 * w2) k*/
		}
	}
}
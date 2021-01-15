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

		//https://www.cnblogs.com/hjlweilong/p/6018213.html
		//q=((x,y,z)sin¦È2, cos¦È2) 
		Quaternion Quaternion::FromEulerAnyAxis(float angle, float3 Axis)
		{
			float x = Axis.x * maths::Util::Sin(angle);
			float y = Axis.y * maths::Util::Sin(angle);
			float z = Axis.z * maths::Util::Sin(angle);
			float w = maths::Util::Cos(angle);
			return Quaternion(x, y, z, w);
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
			 this->w = w * other.w - x*other.x - y*other.y - z*other.z;
			 this->x = w * other.x + x*other.w + y*other.z - z*other.y;
			 this->y = w * other.y - x*other.z + y*other.w + z*other.x;
			 this->z = w * other.z + x*other.y - y*other.x + z*other.w;

			 return *this;
			/*q1 * q2 =
				(w1*w2 - x1 * x2 - y1 * y2 - z1 * z2) +
				(w1*x2 + x1 * w2 + y1 * z2 - z1 * y2) i +
				(w1*y2 - x1 * z2 + y1 * w2 + z1 * x2) j +
				(w1*z2 + x1 * y2 - y1 * x2 + z1 * w2) k*/
		}
	}
}
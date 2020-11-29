#pragma once
 
#include "vec4.h"
#include "mat4.h"
#include "global.h"

namespace sparky {
	namespace maths {
		class Quaternion
		{
		public:
			Quaternion() { x = 0; y = 0; z = 0; w = 0; }
			Quaternion(float x, float y, float z, float w) { this->x = x; this->y = y; this->z = z; this->w = w; }
	 
			mat4 GetMatrix();
			Quaternion& operator +=(Quaternion left);
			static Quaternion FromEulerXYZ(float x, float y, float z);
			friend Quaternion operator*(Quaternion left, float scale);

			Quaternion& operator *=(Quaternion& left);
			void NormalizeSelf() { float len = Length(); x /= len; y /= len; z /= len; w /= len; };
			float Length() { return sqrt(x * x + y * y + z * z + w * w); }
			void SetElement(unsigned int i, float value);

			float3 ToEulerAngles(Quaternion q) {
				float3 angles;

				// roll (x-axis rotation)
				float sinr_cosp = 2 * (q.w * q.x + q.y * q.z);
				float cosr_cosp = 1 - 2 * (q.x * q.x + q.y * q.y);
				angles.x = std::atan2(sinr_cosp, cosr_cosp);

				// pitch (y-axis rotation)
				float sinp = 2 * (q.w * q.y - q.z * q.x);
				if (std::abs(sinp) >= 1)
					angles.y = std::copysign(M_PI / 2, sinp); // use 90 degrees if out of range
				else
					angles.y = std::asin(sinp);

				// yaw (z-axis rotation)
				float siny_cosp = 2 * (q.w * q.z + q.x * q.y);
				float cosy_cosp = 1 - 2 * (q.y * q.y + q.z * q.z);
				angles.z = std::atan2(siny_cosp, cosy_cosp);

				return angles;
			}

			//friend Quaternion& operator*=(Quaternion& left, const Quaternion& right);

			float x;
			float y;
			float z;
			float w;
		};

	}
}
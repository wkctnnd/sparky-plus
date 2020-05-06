#pragma once
#include "vec3.h"
namespace sparky {
	namespace maths {
		struct mat4
		{
			float elements[4 * 4];

			mat4();
			mat4(float diagnal);

			static mat4 identity();
			mat4& multiply(const mat4& others);

			static mat4 orthographic(float left, float right, float top, float bottom, float near, float far);
			static mat4 perspective(float fov, float aspectRatio, float near, float far);
			static mat4 LookAt(const float3& camera, const float3& object, const float3& up);
			//static mat4 translation(const float3& translation);
			static mat4 rotation(float angle, const float3& axis);
			static mat4 rotation(class Quaternion& q);
			static mat4 scale(const float3& scale);

			static mat4 Translate(const float3& translation);

			friend mat4 operator*(mat4 left, const mat4& right);
		};
		
	}
}
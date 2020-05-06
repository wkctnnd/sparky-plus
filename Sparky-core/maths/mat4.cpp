#include "mat4.h"
#include <string>
#include "quaternion.h"
namespace sparky {
	namespace maths {
		mat4::mat4()
		{
			for (int i = 0; i < 4 * 4; i++)
			{
				elements[i] = 0;
			}
		}

		mat4::mat4(float diagnal)
		{
			for (int i = 0; i < 4 * 4; i++)
			{
				elements[i] = 0;
			}

			elements[0 + 0 * 4] = diagnal;
			elements[1 + 1 * 4] = diagnal;
			elements[2 + 2 * 4] = diagnal;
			elements[3 + 3 * 4] = diagnal;
		}

		mat4 mat4::identity()
		{
			return mat4(1);
		}

		mat4& mat4::multiply(const mat4& others)
		{
			/*mat4 result;
			for (int y = 0; y < 4; y++)
			{
				for (int x = 0; x < 4; x++)
				{
					for (int e = 0; e < 4; e++)
					{
						result.elements[4*x+y] = elements[4 * e + y] * others.elements[x+4*e];
					}
				
					
				}
					
			}
			memcpy(&elements, &(result.elements), 16 * 4);
			return *this;*/


			float data[16];
			for (int row = 0; row < 4; row++)
			{
				for (int col = 0; col < 4; col++)
				{
					float sum = 0.0f;
					for (int e = 0; e < 4; e++)
					{
						/*sum += elements[e + row * 4] * others.elements[col + e * 4];*/
						sum += elements[e * 4 + col] * others.elements[row * 4 + e ];
					}
					data[col + row * 4] = sum;
				}
			}
			memcpy(elements, data, 4 * 4 * sizeof(float));
			return *this;
		}

		mat4 mat4::perspective(float fov, float aspectRatio, float near, float far)
		{
			mat4 result(1.0f);

			float q = 1.0f / tan(3.14*(0.5f * fov) / 180.0);
			float a = q / aspectRatio;

			float b = (near + far) / (near - far);
			float c = (2.0f * near * far) / (near - far);

			result.elements[0 + 0 * 4] = a;
			result.elements[1 + 1 * 4] = q;
			result.elements[2 + 2 * 4] = b;
			result.elements[2 + 3 * 4] = -1.0f;
			result.elements[3 + 2 * 4] = c;

			return result;
		}

		mat4 mat4::orthographic(float left, float right, float top, float bottom, float near, float far)
		{
			mat4 result(1.0f);

			result.elements[0 + 0 * 4] = 2.0f / (right - left);

			result.elements[1 + 1 * 4] = 2.0f / (top - bottom);

			result.elements[2 + 2 * 4] = 2.0f / (near - far);

			result.elements[3 + 0 * 4] = (left + right) / (left - right);
			result.elements[3 + 1 * 4] = (bottom + top) / (bottom - top);
			result.elements[3 + 2 * 4] = (far + near) / (far - near);

			return result;
		}


		mat4 mat4::LookAt(const float3& camera, const float3& object, const float3& up)
		{
			mat4 result = identity();
			float3 f = (object-camera).Normalize();
			float3 s = f.Cross(up.Normalize());
			float3 u = s.Cross(f);

			result.elements[0 + 0 * 4] = s.x;
			result.elements[0 + 1 * 4] = s.y;
			result.elements[0 + 2 * 4] = s.z;

			result.elements[1 + 0 * 4] = u.x;
			result.elements[1 + 1 * 4] = u.y;
			result.elements[1 + 2 * 4] = u.z;

			result.elements[2 + 0 * 4] = -f.x;
			result.elements[2 + 1 * 4] = -f.y;
			result.elements[2 + 2 * 4] = -f.z;

			return result * Translate(float3(-camera.x, -camera.y, -camera.z));
		}

		mat4 mat4::rotation(class Quaternion& q)
		{
			mat4 result(0.0f);

			result.elements[0] = 2 * q.x*q.x + 2 * q.w*q.w - 1;
			result.elements[4] = 2 * q.x*q.y - 2 * q.w*q.z;
			result.elements[8] = 2 * q.x*q.z + 2 * q.w*q.y;
			//result.elements[3] = 0;
			result.elements[1] = 2 * q.x*q.y + 2 * q.w*q.z;
			result.elements[5] = 2 * q.y*q.y + 2 * q.w*q.w - 1;
			result.elements[9] = 2 * q.y*q.z - 2 * q.w*q.x;
			//result.elements[7] = 0;
			result.elements[2] = 2 * q.x*q.z - 2 * q.w*q.y;
			result.elements[6] = 2 * q.y*q.z + 2 * q.w*q.x;
			result.elements[10] = 2 * q.z*q.z + 2 * q.w*q.w - 1;
			//result.elements[11] = 0;
			result.elements[15] = 1;
			return result;
		}
		mat4 mat4::Translate(const float3& translation)
		{
			mat4 result(0.0f);

			result.elements[0] = 1;
			result.elements[5] = 1;
			result.elements[10] = 1;
			result.elements[15] = 1;
			result.elements[12] = translation.x;
			result.elements[13] = translation.y;
			result.elements[14] = translation.z;

			return result;
		}
		
		mat4 mat4::scale(const float3& scale)
		{
			mat4 result(0.0);

			result.elements[0] = scale.x;
			result.elements[5] = scale.y;
			result.elements[10] = scale.z;

			result.elements[15] = 1;

			return result;
		}
		mat4 operator*(mat4 left, const mat4& right)
		{
			return left.multiply(right);
		}

	}
}
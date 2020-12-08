#pragma once

#include <iostream>
namespace sparky {
	namespace maths {
		template<class T>
		struct vec3
		{
			float x, y ,z;

			vec3();
			vec3(const float& x, const float& y, const float& z);

			vec3<T>& add(const vec3<T>& other);
			vec3<T>& subtract(const vec3<T>& other);
			vec3<T>& multipy(const vec3<T>& other);
			vec3<T>& divide(const vec3<T>& other);
			vec3<T>& divide(float scale);
			vec3 Cross(const vec3<T>& other) const;
			float Dot(const vec3<T>& other) const;
			vec3<T> Normalize()const;
			float length() const;
			void SetElement(unsigned int i, float value);
			vec3<T>& NormalizeSelf();
			friend std::ostream& operator<<(std::ostream& stream, const vec3<T>& vector);

			vec3<T>& operator +=(const vec3<T>& left);

			friend vec3<T> operator+(vec3<T> left, const vec3<T>& right)
			{
				return left.add(right);
			}
			friend vec3<T> operator-(vec3<T> left, const vec3<T>& right)
			{
				return left.subtract(right);
			}
			friend vec3<T> operator*(vec3<T> left, const vec3<T>& right)
			{
				return left.multipy(right);
			}
			friend vec3<T> operator/(vec3<T> left, float right)
			{
				return left.divide(right);

			}
			friend vec3<T> operator*(vec3<T> left, const float right)
			{
				left.x *= right;
				left.y *= right;
				left.z *= right;
				return left;
			}

			
		};

	

		typedef vec3<float> float3;
		typedef vec3<int>   int3;
	}
}
#include "vec3.inl"
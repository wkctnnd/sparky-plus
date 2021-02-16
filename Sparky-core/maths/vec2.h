#pragma once
#include <iostream>
namespace sparky {
	namespace maths {
		template<class T>
		struct vec2
		{
			T x, y;

			vec2();
			vec2(const float& x, const float& y);

			vec2<T>& add(const vec2<T>& other);
			vec2<T>& subtract(const vec2<T>& other);
			vec2<T>& multipy(const vec2<T>& other);
			vec2<T>& divide(const vec2<T>& other);
			vec2<T>& divide(const float scale);
			void NormalizeSelf() {};
			void SetElement(unsigned int i, T value);

			friend std::ostream& operator<<(std::ostream& stream, const vec2<T>& vector);
			friend vec2<T> operator/(vec2<T> left, float right)
			{
				return left.divide(right);

			}

			friend vec2<T> operator-(vec2<T> left, const vec2<T>& right)
			{
				return left.subtract(right);
			}

			friend vec2<T> operator+(vec2<T> left, const vec2<T>& right)
			{
				return left.add(right);
			}
		};

		typedef vec2<float> float2;
		typedef vec2<int>   int2;
	}
}
#include "vec2.inl"
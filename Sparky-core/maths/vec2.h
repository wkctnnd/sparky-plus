#pragma once
#include <iostream>
namespace sparky {
	namespace maths {

		template<class T>
		struct vec2
		{
			float x, y;

			vec2() {};
			vec2(const float& x, const float& y) { this->x = x; this->y = y; };

			vec2<T>& add(const vec2& other);
			vec2<T>& subtract(const vec2& other);
			vec2<T>& multipy(const vec2& other);
			vec2<T>& divide(const vec2& other);
			void NormalizeSelf() {};
			void SetElement(unsigned int i, float value);

			friend std::ostream& operator<<(std::ostream& stream, const vec2<T>& vector);
			


		};

		typedef vec2<float> float2;
		typedef vec2<int>   int2;
	}
}
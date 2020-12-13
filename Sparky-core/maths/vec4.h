#pragma once

#include <iostream>
namespace sparky {
	namespace maths {

		template<class T>
		struct vec4
		{
			T x, y, z, w;

			vec4();
			vec4(const T& x, const T& y, const T& z, const T& w);

			vec4<T>& add(const vec4<T>& other);
			vec4<T>& subtract(const vec4<T>& other);
			vec4<T>& multipy(const vec4<T>& other);
			vec4<T>& divide(const vec4<T>& other);
			void NormalizeSelf() {};
			float Dot(const vec4<T>& other) const;
			friend std::ostream& operator<<(std::ostream& stream, const vec4<T>& vector);

		};

		typedef vec4<float> float4;
		typedef vec4<int>   int4;
	}
}

#include "vec4.inl"
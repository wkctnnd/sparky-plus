#include "vec2.h"

namespace sparky {
	namespace maths {
		template<class T>
		vec2<T>::vec2()
		{
			x = 0;
			y = 0;
		}
		template<class T>
		vec2<T>::vec2(const float& x, const float& y)
		{
			this->x = x;
			this->y = y;
		}
		template<class T>
		vec2<T>& vec2<T>::add(const vec2<T>& other)
		{
			x += other.x;
			y += other.y;

			return *this;
		}
		template<class T>
		vec2<T>& vec2<T>::subtract(const vec2<T>& other)
		{
			x -= other.x;
			y -= other.y;

			return *this;
		}
		template<class T>
		vec2<T>& vec2<T>::multipy(const vec2<T>& other)
		{
			x *= other.x;
			y *= other.y;

			return *this;
		}
		template<class T>
		vec2<T>& vec2<T>::divide(const vec2<T>& other)
		{
			x /= other.x;
			y /= other.y;

			return *this;
		}

		template<class T>
		vec2<T>& vec2<T>::divide(const float scale)
		{
			x /= scale;
			y /= scale;

			return *this;
		}

		template<class T>
		void vec2<T>::SetElement(unsigned int i, T value)
		{
			T *v = &x;
			*(v + i) = value;
		}
		template<class T>
		std::ostream& operator<<(std::ostream& stream, const vec2<T>& vector)
		{
			stream << "vec2: (" << vector.x << "," << vector.y << ")";
			return stream;
		}
	}
}
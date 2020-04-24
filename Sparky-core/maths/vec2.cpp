#include "vec2.h"

namespace sparky {
	namespace maths {

		vec2::vec2()
		{
			x = 0;
			y = 0;
		}

		vec2::vec2(const float& x, const float& y)
		{
			this->x = x;
			this->y = y;
		}

		vec2& vec2::add(const vec2& other)
		{
			x += other.x;
			y += other.y;

			return *this;
		}
		vec2& vec2::subtract(const vec2& other)
		{
			x -= other.x;
			y -= other.y;

			return *this;
		}

		vec2& vec2::multipy(const vec2& other)
		{
			x *= other.x;
			y *= other.y;

			return *this;
		}

		vec2& vec2::divide(const vec2& other)
		{
			x /= other.x;
			y /= other.y;

			return *this;
		}

		void vec2::SetElement(unsigned int i, float value)
		{
			float *v = &x;
			*(v + i) = value;
		}

		std::ostream& operator<<(std::ostream& stream, const vec2& vector)
		{
			stream << "vec2: (" << vector.x << "," << vector.y << ")";
			return stream;
		}
	}
}
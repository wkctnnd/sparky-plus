namespace sparky {
	namespace maths {
		template<class T>
		vec4<T>::vec4()
		{
			x = 0;
			y = 0;
			z = 0;
			w = 0;
		}
		template<class T>
		vec4<T>::vec4(const T& x, const T& y, const T& z, const T& w)
		{
			this->x = x;
			this->y = y;
			this->z = z;
			this->w = w;
		}
		template<class T>
		vec4<T>& vec4<T>::add(const vec4<T>& other)
		{
			x += other.x;
			y += other.y;
			z += other.z;
			w += other.w;
			return *this;
		}
		template<class T>
		vec4<T>& vec4<T>::subtract(const vec4<T>& other)
		{
			x -= other.x;
			y -= other.y;
			z -= other.z;
			w -= other.z;
			return *this;
		}
		template<class T>
		vec4<T>& vec4<T>::multipy(const vec4<T>& other)
		{
			x *= other.x;
			y *= other.y;
			z *= other.z;
			w *= other.w;
			return *this;
		}

		template<class T>
		vec4<T>& vec4<T>::divide(const vec4<T>& other)
		{
			x /= other.x;
			y /= other.y;
			z /= other.z;
			w /= other.w;
			return *this;
		}

		template<class T>
		std::ostream& operator<<(std::ostream& stream, const vec4<T>& vector)
		{
			stream << "vec4: (" << vector.x << "," << vector.y << "," << vector.z << vector<<")";
			return stream;
		}


		template<class T>
		float vec4<T>::Dot(const vec4& other) const
		{
			return x * other.x + y * other.y + z * other.z+w*other.w;
		}
	}
}
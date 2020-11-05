namespace sparky {
	namespace maths {
		template<class T>
		vec3<T>::vec3()
		{
			x = 0;
			y = 0;
			z = 0;
		}

		template<class T>
		vec3<T>::vec3(const float& x, const float& y, const float& z)
		{
			this->x = x;
			this->y = y;
			this->z = z;
		}

		template<class T>
		vec3<T>& vec3<T>::add(const vec3<T>& other)
		{
			x += other.x;
			y += other.y;
			z += other.z;
			return *this;
		}

		template<class T>
		vec3<T>& vec3<T>::subtract(const vec3& other)
		{
			x -= other.x;
			y -= other.y;
			z -= other.z;
			return *this;
		}

		template<class T>
		vec3<T>& vec3<T>::multipy(const vec3& other)
		{
			x *= other.x;
			y *= other.y;
			z *= other.z;
			return *this;
		}

		template<class T>
		vec3<T>& vec3<T>::divide(const vec3& other)
		{
			x /= other.x;
			y /= other.y;
			z /= other.z;

			return *this;
		}

		template<class T>
		vec3<T> vec3<T>::Cross(const vec3& other) const
		{
			return vec3(y * other.z - z * other.y, z * other.x - x * other.z, x * other.y - y * other.x);
		}

		template<class T>
		float vec3<T>::Dot(const vec3& other) const
		{
			return x * other.x + y * other.y + z * other.z;
		}

		template<class T>
		vec3<T> vec3<T>::Normalize()const
		{
			float length = sqrt(x * x + y * y + z * z);
			return vec3(x / length, y / length, z / length);
		}

		template<class T>
		void vec3<T>::NormalizeSelf()
		{
			float length = sqrt(x * x + y * y + z * z);
			x /= length;
			y /= length;
			z /= length;
 
		}

		template<class T>
		float vec3<T>::length()const
		{
			return sqrt(x * x + y * y + z * z);
		}

		//给模板设值使用
		template<class T>
		void vec3<T>::SetElement(unsigned int i, float value)
		{
			float *v = &x;
			*(v + i) = value;
		}

		template<class T>
		vec3<T>& vec3<T>:: operator+=(const vec3& left)
		{
			x += left.x;
			y += left.y;
			z += left.z;
			return *this;
		}

		template<class T>
		std::ostream& operator<<(std::ostream& stream, const vec3<T>& vector)
		{
			stream << "vec3: (" << vector.x << "," << vector.y << "," << vector.z << ")";
			return stream;
		}

	/*	template<class T>
		vec3<T> operator+(vec3<T> left, const vec3<T>& right)
		{
			return left.add(right);
		}

		template<class T>
		vec3<T> operator-(vec3<T> left, const vec3<T>& right)
		{
			return left.subtract(right);
		}

		template<class T>
		vec3<T> operator*(vec3<T> left, const vec3<T>& right)
		{
			return left.multipy(right);
		}

		template<class T>
		vec3<T> operator*(vec3<T> left, const float right)
		{
			left.x *= right;
			left.y *= right;
			left.z *= right;
			return left;
		}*/
	}
}
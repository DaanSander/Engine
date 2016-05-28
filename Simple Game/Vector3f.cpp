#include "Vector3f.h"

namespace engine {
	namespace math {

		Vector3f::Vector3f() {
			this->x = 0.0f;
			this->y = 0.0f;
			this->z = 0.0f;
		}

		Vector3f::Vector3f(float x, float y, float z) {
			this->x = x;
			this->y = y;
			this->z = z;
		}

		Vector3f& Vector3f::add(const Vector3f& other) {
			this->x += other.x;
			this->y += other.y;
			this->z += other.z;
			return *this;
		}

		Vector3f& Vector3f::subtract(const Vector3f& other) {
			this->x -= other.x;
			this->y -= other.y;
			this->z -= other.z;
			return *this;
		}

		Vector3f& Vector3f::devide(const Vector3f& other) {
			this->x /= other.x;
			this->y /= other.y;
			this->z /= other.z;
			return *this;
		}

		Vector3f& Vector3f::multiply(const Vector3f& other) {
			this->x *= other.x;
			this->y *= other.y;
			this->z *= other.z;
			return *this;
		}

		Vector3f& operator+(Vector3f& left, const Vector3f& right) {
			return left.add(right);
		}

		Vector3f& operator-(Vector3f& left, const Vector3f& right) {
			return left.subtract(right);
		}

		Vector3f& operator/(Vector3f& left, const Vector3f& right) {
			return left.devide(right);
		}

		Vector3f& operator*(Vector3f& left, const Vector3f& right) {
			return left.multiply(right);
		}

		std::ostream& operator<<(std::ostream& stream, const Vector3f& vector) {
			stream << "Vector3f[" << vector.x << "," << vector.y << "," << vector.z << "]";
			return stream;
		}
	}
}
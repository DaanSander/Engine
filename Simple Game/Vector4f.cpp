#include "Vector4f.h"

namespace engine {
	namespace math {

		Vector4f::Vector4f() {
			this->x = 0.0f;
			this->y = 0.0f;
			this->z = 0.0f;
			this->w = 0.0f;
		}

		Vector4f::Vector4f(float x, float y, float z, float w) {
			this->x = x;
			this->y = y;
			this->z = z;
			this->w = w;
		}

		Vector4f& Vector4f::add(const Vector4f& other) {
			this->x += other.x;
			this->y += other.y;
			this->z += other.z;
			this->w += other.w;
			return *this;
		}

		Vector4f& Vector4f::subtract(const Vector4f& other) {
			this->x -= other.x;
			this->y -= other.y;
			this->z -= other.z;
			this->w -= other.w;
			return *this;
		}

		Vector4f& Vector4f::devide(const Vector4f& other) {
			this->x /= other.x;
			this->y /= other.y;
			this->z /= other.z;
			this->w /= other.w;
			return *this;
		}

		Vector4f& Vector4f::multiply(const Vector4f& other) {
			this->x *= other.x;
			this->y *= other.y;
			this->z *= other.z;
			this->w *= other.w;
			return *this;
		}

		Vector4f& operator+(Vector4f& left, const Vector4f& right) {
			return left.add(right);
		}

		Vector4f& operator-(Vector4f& left, const Vector4f& right) {
			return left.subtract(right);
		}

		Vector4f& operator/(Vector4f& left, const Vector4f& right) {
			return left.devide(right);
		}

		Vector4f& operator*(Vector4f& left, const Vector4f& right) {
			return left.multiply(right);
		}

		std::ostream& operator<<(std::ostream& stream, const Vector4f& vector) {
			stream << "Vector3f[" << vector.x << "," << vector.y << "," << vector.z << "," << vector.w << "]";
			return stream;
		}
	}
}
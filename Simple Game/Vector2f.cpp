#include "Vector2f.h"

namespace engine {
	namespace math {
		Vector2f::Vector2f() {
			this->x = 0.0f;
			this->y = 0.0f;
		}

		Vector2f::Vector2f(float x, float y) {
			this->x = x;
			this->y = y;
		}

		Vector2f& Vector2f::add(const Vector2f& other) {
			this->x += other.x;
			this->y += other.y;
			return *this;
		}

		Vector2f& Vector2f::subtract(const Vector2f& other) {
			this->x -= other.x;
			this->y -= other.y;
			return *this;
		}

		Vector2f& Vector2f::devide(const Vector2f& other) {
			this->x /= other.x;
			this->y /= other.y;
			return *this;
		}

		Vector2f& Vector2f::multiply(const Vector2f& other) {
			this->x *= other.x;
			this->y *= other.y;
			return *this;
		}
		
		Vector2f& operator+(Vector2f& left, const Vector2f& right) {
			return left.add(right);
		}

		Vector2f& operator-(Vector2f& left, const Vector2f& right) {
			return left.subtract(right);
		}

		Vector2f& operator/(Vector2f& left, const Vector2f& right) {
			return left.devide(right);
		}
		
		Vector2f& operator*(Vector2f& left, const Vector2f& right) {
			return left.multiply(right);
		}

		std::ostream& operator<<(std::ostream& stream, const Vector2f& vector) {
			stream << "Vector2f[" << vector.x << "," << vector.y << "]";
			return stream;
		}
	}
}


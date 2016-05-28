#pragma once

#include <iostream>

namespace engine {
	namespace math {
		struct Vector2f {
			float x, y;

			Vector2f();

			Vector2f(float x, float y);

			Vector2f& add(const Vector2f& other);
			Vector2f& subtract(const Vector2f& other);
			Vector2f& devide(const Vector2f& other);
			Vector2f& multiply(const Vector2f& other);

			friend Vector2f& operator+(Vector2f& left, const Vector2f& right);
			friend Vector2f& operator-(Vector2f& left, const Vector2f& right);
			friend Vector2f& operator/(Vector2f& left, const Vector2f& right);
			friend Vector2f& operator*(Vector2f& left, const Vector2f& right);


			friend std::ostream& operator<<(std::ostream& stream, const Vector2f& vector);
		};
	}
}
#pragma once

#include <iostream>

namespace engine {
	namespace math {

		struct Vector4f {
			float x, y, z, w;

			Vector4f();

			Vector4f(float x, float y, float z, float w);

			Vector4f& add(const Vector4f& other);
			Vector4f& subtract(const Vector4f& other);
			Vector4f& devide(const Vector4f& other);
			Vector4f& multiply(const Vector4f& other);

			friend Vector4f& operator+(Vector4f& left, const Vector4f& right);
			friend Vector4f& operator-(Vector4f& left, const Vector4f& right);
			friend Vector4f& operator/(Vector4f& left, const Vector4f& right);
			friend Vector4f& operator*(Vector4f& left, const Vector4f& right);

			friend std::ostream& operator<<(std::ostream& stream, const Vector4f& vector);
		};
	}
}
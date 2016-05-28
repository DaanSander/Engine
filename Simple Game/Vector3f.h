#pragma once

#include <iostream>
namespace engine {
	namespace math {
		
		struct Vector3f {
			float x, y, z;

			Vector3f();

			Vector3f(float x, float y, float z);

			Vector3f& add(const Vector3f& other);
			Vector3f& subtract(const Vector3f& other);
			Vector3f& devide(const Vector3f& other);
			Vector3f& multiply(const Vector3f& other);

			friend Vector3f& operator+(Vector3f& left, const Vector3f& right);
			friend Vector3f& operator-(Vector3f& left, const Vector3f& right);
			friend Vector3f& operator/(Vector3f& left, const Vector3f& right);
			friend Vector3f& operator*(Vector3f& left, const Vector3f& right);

			friend std::ostream& operator<<(std::ostream& stream, const Vector3f& vector);
		};
	}
}
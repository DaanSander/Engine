#pragma once

#include "Maths_Func.h"
#include "Vector3f.h"

namespace engine {
	namespace math {
		
		float toRadians(float degrees);

		struct Matrix4f {
			
			float elements[4 * 4];

			Matrix4f();

			Matrix4f(float angle);

			static Matrix4f identity();
			Matrix4f& empty();

			Matrix4f& multiply(const Matrix4f& other);

			Matrix4f& translate(const Vector3f& position);

			static Matrix4f orthographic(float left, float right, float bottom, float top, float near, float far);
			static Matrix4f perspective(float fov, float aspectRatio, float near, float far);

			static Matrix4f translation(Vector3f position);
			static Matrix4f rotation(const float& angle, const Vector3f& axis);
			static Matrix4f scale(Vector3f scale);

		};
	}
}
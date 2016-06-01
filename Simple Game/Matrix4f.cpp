#include "Matrix4f.h"

namespace engine {
	namespace math {

		Matrix4f::Matrix4f() {
			empty();
		}

		Matrix4f::Matrix4f(float diagonal) {
			for (int i = 0; i < 4 * 4; i++)
				elements[i] = 0.0f;

			elements[0 + 0 * 4] = diagonal;
			elements[1 + 1 * 4] = diagonal;
			elements[2 + 2 * 4] = diagonal;
			elements[3 + 3 * 4] = diagonal;
		}


		Matrix4f Matrix4f::orthographic(float left, float right, float bottom, float top, float near, float far) {
			Matrix4f result(1.0f);

			result.elements[0 + 0 * 4] = 2.0f / (right - left);
			result.elements[1 + 1 * 4] = 2.0f / (top - bottom);
			result.elements[2 + 2 * 4] = -2.0f / (far - near);

			result.elements[3 + 0 * 4] = (right + left) / (right - left);
			result.elements[3 + 0 * 4] = (top + bottom) / (top - bottom);
			result.elements[3 + 0 * 4] = (far + near) / (far - near);

			return result;
		}

		Matrix4f Matrix4f::perspective(float fov, float aspectRatio, float near, float far) {
			Matrix4f result(0.0f);

			std::cout << "1,1 " << (float) 1.0f / (float)(aspectRatio * tan(toRadians((float)fov / 2.0f))) << std::endl;

			result.elements[0 + 0 * 4] = (float) 1.0f / (float) (aspectRatio * tan(toRadians((float)fov / 2.0f)));
			result.elements[1 + 1 * 4] = (float) (1.0f / (float)(tan(toRadians(fov / 2.0f))));
			result.elements[2 + 2 * 4] = -((far + near) / (far - near));
			result.elements[2 + 3 * 4] = -1;
			result.elements[3 + 2 * 4] = -((2 * far * near) / (far - near));
			return result;
		}

		Matrix4f Matrix4f::identity() {
			return Matrix4f(1.0f);
		}

		Matrix4f& Matrix4f::empty() {
			for (int i = 0; i < 4 * 4; i++)
				elements[i] = 0.0f;
			return *this;
		}

		Matrix4f& Matrix4f::multiply(const Matrix4f& other) {
			for (int y = 0; y < 4; y++) {
				for (int x = 0; x < 4; x++) {
					this->elements[x + y * 4] = this->elements[x + y * 4] * other.elements[y + x * 4];
				}
			}
			return *this;
		}
	}
}
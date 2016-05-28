#include "Matrix4f.h"

namespace engine {
	namespace math {

		Matrix4f::Matrix4f() {
			empty();
		}

		Matrix4f& Matrix4f::identity(){
			for (int i = 0; i < 4 * 4; i++)
				elements[i] = 0.0f;

			elements[0 + 0 * 4] = 1.0f;
			elements[1 + 1 * 4] = 1.0f;
			elements[2 + 2 * 4] = 1.0f;
			elements[3 + 3 * 4] = 1.0f;
		}

		Matrix4f& Matrix4f::empty() {
			for (int i = 0; i < 4 * 4; i++)
				elements[i] = 0.0f;
		}
	}
}
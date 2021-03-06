#pragma once

#include <GL\glew.h>
#include "Maths.h"

namespace engine {
	namespace graphics {

		class Shader {
			const char *vertexPath, *fragmentPath;

			GLuint vertexShader, fragmentShader;
			GLuint programID;

		public:
			Shader(const char* vertexPath, const char* fragmentPath);

			~Shader();

			GLuint getUniformLocation(const GLchar* name);

			void loadVector2f(const int& location, const math::Vector2f& vector);

			void loadVector3f(const int& location, const math::Vector3f& vector);

			void loadVector4f(const int& location, const math::Vector4f& vector);

			void loadMatrix4f(const int& location, const math::Matrix4f& vector);

			void enable();

			void disable();

		private:


			GLuint loadShader(const std::string& shaderPath, const GLenum& type);
		};
	}
}
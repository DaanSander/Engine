#pragma once

#include <GL\glew.h>
#include <iostream>
#include <string>
#include "Maths.h"

namespace engine {
	namespace graphics {

		class Shader {
			const char *vertexPath, *fragmentPath;

			//

			const GLuint *vertexShader, *fragmentShader;
			const GLuint programID;

			Shader(const char* vertexPath, const char* fragmentPath);

			virtual void bindAttributes();

			void bindAttribute(const GLuint& index, const GLchar* name);

			GLuint getUniformLocation(const GLchar* name);

			void loadVector2f(const math::Vector2f& vector);

			void loadVector3f(const math::Vector3f& vector);

			void loadVector4f(const math::Vector4f& vector);

			void loadMat4f(const math::Matrix4f& vector);

			GLuint loadShader(const std::string& shaderPath, const GLenum& type);
		};
	}
}
#include <vector>
#include "Shader.h"
#include "FileUtils.h"

namespace engine {
	namespace graphics {

		Shader::Shader(const char* vertexPath, const char* fragmentPath) {
			this->vertexPath = vertexPath;
			this->fragmentPath = fragmentPath;
			this->vertexShader = (const GLuint *)loadShader(vertexPath, GL_VERTEX_SHADER);
			this->fragmentShader = (const GLuint *)loadShader(fragmentPath, GL_FRAGMENT_SHADER);
			
			//

			GLuint program = glCreateProgram();
		}

		GLuint Shader::loadShader(const std::string& shaderPath, const GLenum& type) {
			std::string shaderSource = read_file(shaderPath.c_str());

			GLuint shader = glCreateShader(type);

			const GLchar* source = (const GLchar *)shaderSource.c_str();
			glShaderSource(shader, 1, &source, 0);

			GLint isCompiled = 0;

			glGetShaderiv(shader, GL_COMPILE_STATUS, &isCompiled);

			if (isCompiled == GL_FALSE) {
				std::cout << "Failed to compile shader!" << std::endl;

				GLint maxLength = 0;

				glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &maxLength);

				std::vector<GLchar> errorLog(maxLength);

				glGetShaderInfoLog(shader, maxLength, &maxLength, &errorLog[0]);

				std::cout << errorLog[0] << std::endl;

				glDeleteShader(shader);
			}

			return shader;
		}
	}
}

#include <vector>
#include <string>
#include "Shader.h"
#include "FileUtils.h"

namespace engine {
	namespace graphics {

		Shader::Shader(const char* vertexPath, const char* fragmentPath) {
			this->vertexPath = vertexPath;
			this->fragmentPath = fragmentPath;
			this->vertexShader = loadShader(vertexPath, GL_VERTEX_SHADER);
			this->fragmentShader = loadShader(fragmentPath, GL_FRAGMENT_SHADER);
			this->programID = glCreateProgram();
			glAttachShader(programID, vertexShader);
			glAttachShader(programID, fragmentShader);
			glLinkProgram(programID);
			glValidateProgram(programID);
		}

		Shader::~Shader() {
			glDetachShader(programID, vertexShader);
			glDetachShader(programID, fragmentShader);

			glDeleteShader(vertexShader);
			glDeleteShader(fragmentShader);

			glDeleteProgram(programID);
		}

		GLuint Shader::getUniformLocation(const GLchar* name) {
			return glGetUniformLocation(programID, name);
		}

		GLuint Shader::loadShader(const std::string& shaderPath, const GLenum& type) {
			std::string shaderSource = FileUtils::read_file(shaderPath.c_str());

			std::cout << shaderSource << std::endl;

			GLuint shader = glCreateShader(type);

			const GLchar* source = (const GLchar *)shaderSource.c_str();
			glShaderSource(shader, 1, &source, 0);

			glCompileShader(shader);

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
				return 0;
			}
			
			return shader;
		}

		void Shader::enable() {
			glUseProgram(programID);
		}

		void Shader::disable() {
			glUseProgram(0);
		}
	}
}

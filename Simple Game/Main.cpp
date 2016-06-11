#include <iostream>
#include <string>
#include "Window.h"
#include "Shader.h"

int main() {
	using namespace engine;
	using namespace graphics;
	using namespace math;

	Window window("Engine", 800, 600);

	Matrix4f matrix = Matrix4f::perspective(70, 800 / 600, 0.3f, 500.0f);

	GLfloat vertices[] = {
		-0.5f, -0.5f, 0.0f,
		-0.5f,  0.5f, 0.0f,
		 0.5f,  0.5f, 0.0f,
		 0.5f,  0.5f, 0.0f,
		 0.5f,  -0.5f, 0.0f,
		-0.5f,  -0.5f, 0.0f

	};

	GLuint vbo;

	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);

	Shader shader("assets/shaders/basic.vert", "assets/shaders/basic.frag");
	shader.enable();

	glClearColor(0.4f, 0.3f, 0.6f, 1.0f);

	Vector2f vector(10, 1);

	Vector2f vector2(101, 1);

	while (!window.closed()) {
		window.clear();
		glDrawArrays(GL_TRIANGLES, 0, 6);
		window.tick();
		window.render();
	}

	shader.disable();
	glDisableVertexAttribArray(0);
	glDeleteBuffers(1, &vbo);

	return 0;
}
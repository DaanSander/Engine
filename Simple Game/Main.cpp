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

	Shader shader("graphics/shaders/basic.vert", "graphics/shaders/basic.frag");

	glClearColor(0.4f, 0.3f, 0.6f, 1.0f);

	Vector2f vector(10, 1);

	Vector2f vector2(101, 1);

	while (!window.closed()) {
		window.clear();
		window.tick();
		window.render();
	}

	return 0;
}
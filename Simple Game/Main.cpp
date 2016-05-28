#include <iostream>
#include "Window.h"
#include "Vector2f.h"

int main() {
	using namespace engine;
	using namespace graphics;
	using namespace math;

	Window window("Sparky", 800, 600);

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
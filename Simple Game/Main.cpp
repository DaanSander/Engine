#include <iostream>
#include <string>
#include "Window.h"
#include "Maths.h"
#include "FileUtils.h"

int main() {
	using namespace engine;
	using namespace graphics;
	using namespace math;

	std::string file = read_file("C:/Users/Daan/Desktop/Crosshair.txt");
	std::cout << file << std::endl;
	system("PAUSE");
	return 0;
	Window window("Sparky", 800, 600);

	Matrix4f matrix = Matrix4f::perspective(70, 800 / 600, 0.3f, 500.0f);

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
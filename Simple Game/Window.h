#pragma once

#include <GL\glew.h>
#include <GLFW\glfw3.h>

namespace engine {namespace graphics {

#define MAX_KEYS 1024
#define MAX_BUTTONS 12

	class Window {

	private:
		const char *m_Name;
		int m_Width, m_Height;
		GLFWwindow *m_Window;
		bool m_Closed;
		bool m_Keys[MAX_KEYS];
		bool m_Buttons[MAX_BUTTONS];
	public:
		Window(const char *name, int width, int height);
		~Window();
		void render() const;
		void tick();
		void clear() const;
		bool closed() const;
		bool keyDown(unsigned int key) const;
		bool buttonDown(unsigned int button) const;
		inline int getWidth() const { return m_Width; };
		inline int getHeight() const { return m_Height; };
	private:
		bool init();

		friend void key_Callback(GLFWwindow* window, int key, int scancode, int action, int mods);
		friend void mouse_ButtonCallback(GLFWwindow* window, int button, int action, int mods);
		friend void mouse_ScrollCallback(GLFWwindow* window, double xoffset, double yoffset);
	}; 


}}
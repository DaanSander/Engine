#include <iostream>
#include "Window.h"

namespace engine {
	namespace graphics {

		void window_ResizeCallback(GLFWwindow *window, int width, int height);

		void key_Callback(GLFWwindow* window, int key, int scancode, int action, int mods);
		void mouse_ButtonCallback(GLFWwindow* window, int button, int action, int mods);
	
		Window::Window(const char *name, int width, int height) {
			m_Name = name;
			m_Width = width;
			m_Height = height;
			if (!init())
				glfwTerminate();

			for (int i = 0; i < MAX_KEYS; i++)
				m_Keys[i] = false;

			for (int i = 0; i < MAX_BUTTONS; i++)
				m_Buttons[i] = false;

		}

		Window::~Window() {
			glfwTerminate();
		}

		bool Window::closed() const {
			return glfwWindowShouldClose(m_Window) == 1;
		}

		void Window::render() const {
			glfwSwapBuffers(m_Window);
		}

		void Window::tick() {
			glfwPollEvents();
		}

		void Window::clear() const {
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}

		bool Window::init() {
			if (!glfwInit()) {
				std::cout << "Failed to initialize GLFW!" << std::endl;
				return false;
			}

			m_Window = glfwCreateWindow(m_Width, m_Height, m_Name, NULL, NULL);

			if (!m_Window) {
				std::cout << "Failed to create window: " << m_Name << " !" << std::endl;
				glfwTerminate();
				return false;
			}

			glfwMakeContextCurrent(m_Window);
			glfwSetWindowSizeCallback(m_Window, window_ResizeCallback);
			glfwSetWindowUserPointer(m_Window, this);
			glfwSetKeyCallback(m_Window, key_Callback);
			glfwSetMouseButtonCallback(m_Window, mouse_ButtonCallback);
		

			if (glewInit() != GLEW_OK) {
				std::cout << "Failed to initialize GLEW!" << std::endl;
				return false;
			}

			std::cout << "OpenGL " << glGetString(GL_VERSION) << std::endl;

			return true;
		}

		bool Window::keyDown(unsigned int key) const {
			if (key > MAX_KEYS)
				return false;
			return m_Keys[key];
		}

		bool Window::buttonDown(unsigned int button) const {
			if (button > MAX_BUTTONS)
				return false;
			return m_Buttons[button];
		}

		void window_ResizeCallback(GLFWwindow *window, int width, int height) {
			glViewport(0, 0, width, height);
		}

		void key_Callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
			Window* windowPointer = (Window*)glfwGetWindowUserPointer(window);
			if (key > MAX_KEYS) return;
			if (action == GLFW_PRESS)
				windowPointer->m_Keys[key] = true;
			else if (action == GLFW_RELEASE)
				windowPointer->m_Keys[key] = false;
		}

		void mouse_ButtonCallback(GLFWwindow* window, int button, int action, int mods) {
			Window* windowPointer = (Window*)glfwGetWindowUserPointer(window);
			if (button > MAX_BUTTONS) return;
			if (action == GLFW_PRESS)
				windowPointer->m_Buttons[button] = true;
			else if (action == GLFW_RELEASE)
				windowPointer->m_Buttons[button] = false;
		}
	}
}
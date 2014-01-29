#include <glfw-c++/Window.hpp>

namespace glfw
{
	void Window::DefaultHints(){glfwDefaultWindowHints();}
	void Window::Hint(int target, int hint){glfwWindowHint(target,hint);}

	void Window::Create(int width, int height, const std::string &title, const Monitor &monitor, const Window &share)
	{
		m_window = glfwCreateWindow(width, height, title.c_str(), Monitor.GetRawPointerData(), Window.GetRawPointerData());
	}

	GLFWwindow* Window::GetRawPointerData()
}
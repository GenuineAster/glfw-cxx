#include <glfw-c++/Context.hpp>
#include <glfw-c++/Window.hpp>

namespace glfw
{
	namespace Context
	{
		void MakeContextCurrent(Window &window)
		{
			glfwMakeContextCurrent(window.GetRawPointerData());
		}

		Window GetCurrentContext()
		{
			return Window{glfwGetCurrentContext()};
		}

		void SwapInterval(int interval)
		{
			glfwSwapInterval(interval);
		}

		int ExtensionSupported(std::string extension)
		{
			return glfwExtensionSupported(extension.c_str());
		}

		glproc GetProcAddress(std::string procname)
		{
			return glfwGetProcAddress(procname.c_str());
		}
	}
}
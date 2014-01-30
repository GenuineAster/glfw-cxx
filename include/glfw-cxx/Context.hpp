#pragma once
#include <GLFW/glfw3.h>
#include <string>

namespace glfw
{

	using glproc = GLFWglproc;

	class Window;

	namespace Context
	{
		void MakeContextCurrent(Window &window);
		Window GetCurrentContext();
		void SwapInterval(int interval);
		int ExtensionSupported(std::string extension);
		glproc GetProcAddress(std::string procname);
	}
}

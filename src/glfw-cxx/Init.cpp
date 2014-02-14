#include <GLFW/glfw3.h>
#include <glfw-cxx/Init.hpp>
#include <cstdlib>

namespace glfw
{
	bool IsActive = glfwInit();
	bool WillTerminateOnExit = atexit(glfwTerminate);

	bool GetInit()
	{
		return IsActive;
	}

	bool GetWillTerminateOnExit()
	{
		return WillTerminateOnExit;
	}
}

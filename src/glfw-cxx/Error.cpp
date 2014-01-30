#include <glfw-cxx/Error.hpp>

namespace glfw
{
	errorfun SetErrorCallback(errorfun cbfun)
	{
		glfwSetErrorCallback(cbfun);
	}
}

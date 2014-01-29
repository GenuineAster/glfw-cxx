#include <glfw-c++/Error.hpp>

namespace glfw
{
	errorfun SetErrorCallback(errorfun cbfun)
	{
		glfwSetErrorCallback(cbfun);
	}
}
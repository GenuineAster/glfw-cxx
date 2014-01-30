#include <GLFW/glfw3.h>

namespace glfw
{
	using errorfun = GLFWerrorfun;

	errorfun SetErrorCallback(errorfun cbfun);
}

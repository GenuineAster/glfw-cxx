#pragma once
#include <GLFW/glfw3.h>

namespace glfw
{
	enum Error
	{
		NotInitialized = 0x00010001,
		NoCurrentContext,
		InvalidEnum,
		InvalidValue,
		OutOfMemory,
		ApiUnavailable,
		VersionUnavailable,
		PlatformError,
		FormatUnavailable
	};

	using errorfun = GLFWerrorfun;

	errorfun SetErrorCallback(errorfun cbfun);

}

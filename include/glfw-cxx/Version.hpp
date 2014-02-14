#pragma once
#include <GLFW/glfw3.h>
#include <string>

namespace glfw
{
	namespace VersionInfo
	{
		int major;
		int minor;
		int rev;
		void Get();
		std::string GetString();
	}
}

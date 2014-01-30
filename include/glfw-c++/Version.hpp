#include <GLFW/glfw3.h>
#include <string>
#include <cstdlib>

namespace glfw
{
	bool __temp__ = atexit(glfwTerminate);
	bool IsActive = glfwInit();

	namespace VersionInfo
	{
		int major;
		int minor;
		int rev;
		void Get();
		std::string GetString();
	}
}

#include <glfw-c++/Version.hpp>

namespace glfw
{
	namespace VersionInfo
	{
		void Get()
		{
			glfwGetVersion(&major, &minor, &rev);
		}

		std::string GetString()
		{
			return std::string{glfwGetVersionString()};
		}
	}
}
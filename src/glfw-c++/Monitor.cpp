#include <glfw-c++/Monitor.hpp>

namespace glfw
{
	static Monitor GetPrimaryMonitor(){return Monitor(glfwGetPrimaryMonitor());}

	Monitor::Monitor(GLFWmonitor* monitor_) : monitor{monitor_} {}
}
#pragma once
#include <GLFW/glfw3.h>

namespace glfw
{
	class Time
	{
	public:
		static double Get();
		static void Set(double time_);
	};
}

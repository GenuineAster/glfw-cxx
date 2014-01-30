#include <glfw-c++/Monitor.hpp>

namespace glfw
{
	const std::list<Monitor> Monitor::GetMonitors()
	{
		int count;
		GLFWmonitor** monitors_ptr = glfwGetMonitors(&count);
		std::list<Monitor> monitors;
		for(int i = 0; i < count; i++)
			monitors.push_back(Monitor(monitors_ptr[i]));
		return monitors;
	}

	const Monitor Monitor::GetPrimaryMonitor()
	{
		return Monitor(glfwGetPrimaryMonitor());
	}

	const MonitorPos Monitor::GetPos() const
	{
		int x,y;
		glfwGetMonitorPos(m_monitor, &x, &y);
		return MonitorPos(x,y);
	}

	const MonitorSize Monitor::GetPhysicalSize() const
	{
		int x,y;
		glfwGetMonitorPhysicalSize(m_monitor, &x, &y);
		return MonitorSize(x,y);
	}

	const std::string Monitor::GetName() const
	{
		return std::string{glfwGetMonitorName(m_monitor)};
	}

	const monitorfun Monitor::SetCallback(monitorfun cbfun)
	{
		return glfwSetMonitorCallback(cbfun);
	}

	const std::list<vidmode> Monitor::GetVideoModes() const
	{
		int count;
		const vidmode* video_modes_ptr = glfwGetVideoModes(m_monitor, &count);
		std::list<vidmode> video_modes;
		for(int i = 0; i < count; i++)
			video_modes.push_back(video_modes_ptr[i]);
		return video_modes;	
	}

	const vidmode &Monitor::GetVideoMode() const
	{
		return *glfwGetVideoMode(m_monitor);
	}

	void Monitor::SetGamma(float gamma)
	{
		glfwSetGamma(m_monitor, gamma);
	}

	const gammaramp &Monitor::GetGammaRamp() const
	{
		return *glfwGetGammaRamp(m_monitor);
	}

	void Monitor::SetGammaRamp(const gammaramp &ramp)
	{
		glfwSetGammaRamp(m_monitor, &ramp);
	}

	GLFWmonitor* Monitor::GetRawPointerData() const
	{
		return m_monitor;
	}


	Monitor::Monitor(GLFWmonitor* monitor) : m_monitor{monitor} {}
}
#include <glfw-cxx/Monitor.hpp>

namespace glfw
{

	const Monitor::Function Monitor::DefaultFunction = 
	[](Monitor monitor, MonitorConfigChangeEvents event)
	{
		changed = true;
		ChangedMonitors.push_back(monitor);
	};

	bool Monitor::changed = false;
	std::list<Monitor> Monitor::ChangedMonitors = {};

	Monitor::Function Monitor::CurrentFunction = Monitor::DefaultFunction;
	Monitor::FunctionPointer* Monitor::CurrentFunctionPointer = *Monitor::LambdaFunctionWrapper;
	Monitor::FunctionPointerRaw* Monitor::CurrentFunctionPointerRaw = *Monitor::FunctionPointerWrapper;

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

	const std::list<VideoMode> Monitor::GetVideoModes() const
	{
		int count;
		const GLFWvidmode* video_modes_ptr = glfwGetVideoModes(m_monitor, &count);
		std::list<VideoMode> video_modes;
		for(int i = 0; i < count; i++)
			video_modes.push_back(VideoMode(video_modes_ptr[i]));
		return video_modes;	
	}

	const VideoMode Monitor::GetVideoMode() const
	{
		return VideoMode(*glfwGetVideoMode(m_monitor));
	}

	void Monitor::SetGamma(float gamma)
	{
		glfwSetGamma(m_monitor, gamma);
	}

	const GammaRamp Monitor::GetGammaRamp() const
	{
		return GammaRamp(*glfwGetGammaRamp(m_monitor));
	}

	void Monitor::SetGammaRamp(GammaRamp &ramp)
	{
		glfwSetGammaRamp(m_monitor, ramp.GetRawPointerData());
	}

	GLFWmonitor* Monitor::GetRawPointerData() const
	{
		return m_monitor;
	}

	void Monitor::LambdaFunctionWrapper(Monitor monitor, MonitorConfigChangeEvents event)
	{
		CurrentFunction(monitor, event);
	}

	void Monitor::FunctionPointerWrapper(GLFWmonitor* monitor, int event)
	{
		CurrentFunctionPointer(
			Monitor(monitor), 
			static_cast<MonitorConfigChangeEvents>(event)
		);
	}

	Monitor::Function Monitor::GetDefaultCallback()
	{
		return DefaultFunction;
	}

	Monitor::Function Monitor::SetCallback(Monitor::Function fun)
	{
		auto temp = CurrentFunction;
		CurrentFunction = fun;
		CurrentFunctionPointer = *LambdaFunctionWrapper;
		CurrentFunctionPointerRaw = *FunctionPointerWrapper;
		return temp;
	}

	const Monitor::FunctionPointer* Monitor::SetCallback(Monitor::FunctionPointer* fun)
	{
		auto temp = CurrentFunctionPointer;
		CurrentFunctionPointer = fun;
		CurrentFunctionPointerRaw = FunctionPointerWrapper;
		return temp;
	}

	const Monitor::FunctionPointerRaw* Monitor::SetCallback(Monitor::FunctionPointerRaw* fun)
	{
		auto temp = CurrentFunctionPointerRaw;
		CurrentFunctionPointerRaw = fun;
		return temp;
	}

	bool Monitor::GetConfigChange()
	{
		if(changed)
		{
			changed = false;
			return true;
		}
		return false;
	}

	std::list<Monitor> Monitor::GetChangedMonitors()
	{
		auto temp = ChangedMonitors;
		ChangedMonitors.clear();
		return temp;
	}

	Monitor::operator GLFWmonitor*()
	{
		return m_monitor;
	}


	Monitor::Monitor(GLFWmonitor* monitor) : m_monitor{monitor} {}
}

#pragma once
#include <GLFW/glfw3.h>
#include <list>
#include <string>
#include <glfw-cxx/Vector2.hpp>
#include <glfw-cxx/VideoMode.hpp>
#include <glfw-cxx/GammaRamp.hpp>
#include <functional>

namespace glfw
{
	using MonitorSize = Vector2<int>;
	using MonitorPos = Vector2<int>;

	enum MonitorConfigChangeEvents
	{
		Connected = GLFW_CONNECTED,
		Disconnected = GLFW_DISCONNECTED
	};

	class Monitor
	{
	public:
		using MonitorFunction = std::function<void(Monitor, MonitorConfigChangeEvents)>;
		using MonitorFunctionPointer = void(Monitor, MonitorConfigChangeEvents);
		using MonitorFunctionPointerRaw = void(GLFWmonitor*, int);
		static const MonitorFunction DefaultMonitorFunction;
		static void LambdaFunctionWrapper(Monitor monitor, MonitorConfigChangeEvents event);
		static void FunctionPointerWrapper(GLFWmonitor* monitor, int event);

	private:
		static std::list<Monitor> ChangedMonitors;
		GLFWmonitor* m_monitor;
		static bool changed;

		static MonitorFunction CurrentMonitorFunction;
		static MonitorFunctionPointer* CurrentMonitorFunctionPointer;
		static MonitorFunctionPointerRaw* CurrentMonitorFunctionPointerRaw;



	public:
		static const std::list<Monitor> GetMonitors();
		static const Monitor GetPrimaryMonitor();
		const MonitorPos GetPos() const;
		const MonitorSize GetPhysicalSize() const;
		const std::string GetName() const;
		const std::list<VideoMode> GetVideoModes() const;
		const VideoMode GetVideoMode() const;
		void SetGamma(float gamma);
		const GammaRamp GetGammaRamp() const;
		void SetGammaRamp(GammaRamp &ramp);

		MonitorFunction GetDefaultCallback();
		MonitorFunction SetCallback(MonitorFunction fun);
		const MonitorFunctionPointer* SetCallback(MonitorFunctionPointer* fun);
		const MonitorFunctionPointerRaw* SetCallback(MonitorFunctionPointerRaw* fun);

		GLFWmonitor* GetRawPointerData() const;

		operator GLFWmonitor*();

		Monitor(GLFWmonitor* monitor);

	};
}

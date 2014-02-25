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
		using Function = std::function<void(Monitor, MonitorConfigChangeEvents)>;
		using FunctionPointer = void(Monitor, MonitorConfigChangeEvents);
		using FunctionPointerRaw = void(GLFWmonitor*, int);
		static const Function DefaultFunction;
		static void LambdaFunctionWrapper(Monitor monitor, MonitorConfigChangeEvents event);
		static void FunctionPointerWrapper(GLFWmonitor* monitor, int event);

	private:
		static std::list<Monitor> ChangedMonitors;
		GLFWmonitor* m_monitor;
		static bool changed;

		static Function CurrentFunction;
		static FunctionPointer* CurrentFunctionPointer;
		static FunctionPointerRaw* CurrentFunctionPointerRaw;



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

		Function GetDefaultCallback();
		Function SetCallback(Function fun);
		const FunctionPointer* SetCallback(FunctionPointer* fun);
		const FunctionPointerRaw* SetCallback(FunctionPointerRaw* fun);

		static bool GetConfigChange();
		static std::list<Monitor> GetChangedMonitors();

		GLFWmonitor* GetRawPointerData() const;

		operator GLFWmonitor*();

		Monitor(GLFWmonitor* monitor);

	};
}

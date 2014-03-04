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

	/*! \brief Monitor events (Connected/Disconnected)
	 */
	enum MonitorConfigChangeEvents
	{
		Connected = GLFW_CONNECTED,
		Disconnected = GLFW_DISCONNECTED
	};

	/*! \brief A class representing a computer monitor
	 */
	class Monitor
	{
	private:
		using Function = std::function<void(Monitor, MonitorConfigChangeEvents)>;
		using FunctionPointer = void(Monitor, MonitorConfigChangeEvents);
		using FunctionPointerRaw = void(GLFWmonitor*, int);
		static const Function DefaultFunction;
		static void LambdaFunctionWrapper(Monitor monitor, MonitorConfigChangeEvents event);
		static void FunctionPointerWrapper(GLFWmonitor* monitor, int event);
		static std::list<Monitor> ChangedMonitors;
		GLFWmonitor* m_monitor;
		static bool changed;
		static Function CurrentFunction;
		static FunctionPointer* CurrentFunctionPointer;
		static FunctionPointerRaw* CurrentFunctionPointerRaw;



	public:
		/*!\brief Gets a list of monitors currently plugged into the machine.
		 * \returns a list of monitors currently plugged into the machine
		 */
		static const std::list<Monitor> GetMonitors();

		/*!\brief Gets the primary monitor
		 * \returns the primary monitor
		 */
		static const Monitor GetPrimaryMonitor();

		/*!\brief Gets the position of the monitor
		 * \returns the position of the monitor
		 */
		const MonitorPos GetPos() const;

		/*!\brief Gets the physical size of the monitor
		 * \returns the physical size of the monitor
		 */
		const MonitorSize GetPhysicalSize() const;

		/*!\brief Gets the name of the monitor
		 * \returns the name of the monitor
		 */
		const std::string GetName() const;

		/*!\brief Gets the list of videomodes supported by the monitor
		 * \returns the list of videomodes supported by the monitor
		 */
		const std::list<VideoMode> GetVideoModes() const;

		/*!\brief Gets the monitor's current videomode
		 * \returns the monitor's current videomode
		 */
		const VideoMode GetVideoMode() const;

		/*!\brief Sets the gamma of the monitor
		 * \param[in] gamma the monitor's new gamma.
		 */
		void SetGamma(float gamma);

		/*!\brief Gets the gamma ramp of the monitor.
		 * \returns the monitor's gamma ramp.
		 */
		const GammaRamp GetGammaRamp() const;

		/*!\brief Sets the gamma ramp of the monitor.
		 * \param[in] ramp the monitor's new gamma ramp.
		 */
		void SetGammaRamp(GammaRamp &ramp);

		/*!\brief Gets the default callback for Monitor changes
		 * \returns the default call back for Monitor changes
		 */
		Function GetDefaultCallback();

		/*!\brief Sets the callback for changes in this Monitor
		 * param[in] fun the new callback for changes in this Monitor
		 */
		Function SetCallback(Function fun);

		/*!\brief Sets the callback for changes in this Monitor
		 * param[in] fun the new callback for changes in this Monitor
		 */
		const FunctionPointer* SetCallback(FunctionPointer* fun);

		/*!\brief Sets the callback for changes in this Monitor
		 * param[in] fun the new callback for changes in this Monitor
		 */
		const FunctionPointerRaw* SetCallback(FunctionPointerRaw* fun);

		/*!\brief Gets whether a change in monitor config was made.
		 * \returns Whether a change in monitor config was made.
		 */
		static bool GetConfigChange();

		/*!\brief Gets a list of changed monitors.
		 * \returns a list of changed monitors.
		 */
		static std::list<Monitor> GetChangedMonitors();

		/*!\brief Gets the C GLFW pointer for this Monitor.
		 * \returns the C GLFW pointer for this Monitor.
		 */
		GLFWmonitor* GetRawPointerData() const;

		operator GLFWmonitor*();

		Monitor(GLFWmonitor* monitor);

	};
}

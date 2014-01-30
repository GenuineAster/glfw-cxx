#include <GLFW/glfw3.h>
#include <list>
#include <string>
#include <glfw-c++/Vector2.hpp>
#include <glfw-c++/VideoMode.hpp>
#include <glfw-c++/GammaRamp.hpp>

namespace glfw
{
	using monitorfun = GLFWmonitorfun;

	using MonitorSize = Vector2<int>;
	using MonitorPos = Vector2<int>;

	class Monitor
	{
	private:
		GLFWmonitor* m_monitor;

	public:
		static const std::list<Monitor> GetMonitors();
		static const Monitor GetPrimaryMonitor();
		const MonitorPos GetPos() const;
		const MonitorSize GetPhysicalSize() const;
		const std::string GetName() const;
		const monitorfun SetCallback(monitorfun cbfun);
		const std::list<VideoMode> GetVideoModes() const;
		const VideoMode GetVideoMode() const;
		void SetGamma(float gamma);
		const GammaRamp GetGammaRamp() const;
		void SetGammaRamp(GammaRamp &ramp);

		GLFWmonitor* GetRawPointerData() const;

		Monitor(GLFWmonitor* monitor);
	};
}

#include <GLFW/glfw3.h>
#include <list>
#include <string>
#include <glfw-c++/Vector2.hpp>

namespace glfw
{
	using vidmode = GLFWvidmode;
	using gammaramp = GLFWgammaramp;
	using monitorfun = GLFWmonitorfun;

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
		const std::list<vidmode> GetVideoModes() const;
		const vidmode &GetVideoMode() const;
		void SetGamma(float gamma);
		const gammaramp &GetGammaRamp() const;
		void SetGammaRamp(const gammaramp &ramp);

		GLFWmonitor* GetRawPointerData() const;

		Monitor(GLFWmonitor* monitor);
	};
}

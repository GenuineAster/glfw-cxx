#include <GLFW/glfw3.h>
#include <list>
#include <string>

namespace glfw
{
	using vidmode = GLFWvidmode;
	using gammaramp = GLFWgammaramp;

	class Monitor
	{
	private:
		GLFWmonitor* monitor;

	public:
		static Monitor GetPrimaryMonitor();
		static const std::list<Monitor> GetMonitors();
		const std::list<vidmode*> GetVideoModes() const;
		const vidmode &GetVideoMode() const;
		const int GetPhysicalSizeX() const;
		const int GetPhysicalSizeY() const;
		const std::string GetName() const;
		const gammaramp &GetGammaRamp() const;
		void SetGammaRamp(const gammaramp &ramp);
		void setGamma(float gamma);

		Monitor(GLFWmonitor* monitor_);
	};
}

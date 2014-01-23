#include <GLFW/glfw3.h>
#include <list>
#include <string>

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
		const int GetPosX() const;
		const int GetPosY() const;
		const int GetPhysicalSizeX() const;
		const int GetPhysicalSizeY() const;
		const std::string GetName() const;
		const monitorfun SetCallback(monitorfun cbfun);
		const std::list<vidmode> GetVideoModes() const;
		const vidmode &GetVideoMode() const;
		void SetGamma(float gamma);
		const gammaramp &GetGammaRamp() const;
		void SetGammaRamp(const gammaramp &ramp);

		GLFWmonitor* GetRawPointerData();

		Monitor(GLFWmonitor* monitor);
	};
}

#include <GLFW/glfw3.h>
#include <glfw-c++/Monitor.hpp>
#include <string>
#include <vector>

namespace glfw
{
	using windowposfun = GLFWwindowposfun;
	using windowsizefun = GLFWwindowsizefun;
	using windowclosefun = GLFWwindowclosefun;
	using windowrefreshfun = GLFWwindowrefreshfun;
	using windowfocusfun = GLFWwindowfocusfun;
	using windowiconifyfun = GLFWwindowiconifyfun;
	using framebuffersizefun = GLFWframebuffersizefun;

	using mousebuttonfun = GLFWmousebuttonfun;
	using cursorposfun = GLFWcursorposfun;
	using cursorenterfun = GLFWcursorenterfun;
	using scrollfun = GLFWscrollfun;
	using keyfun = GLFWkeyfun;
	using charfun = GLFWcharfun;
	using dropfun = GLFWdropfun;

	class Window
	{
	private:
		GLFWwindow* m_window;
	public:

		int GetInputMode(int mode) const;

		void SetInputMode(int mode, int value);

		int GetKey(int key) const;

		int GetMouseButton(int button) const;

		double GetCursorPosX() const;

		double GetCursorPosY() const;

		void SetCursorPos(double x, double y);

		static int JoystickPresent(int joy);

		static std::vector<float> GetJoystickAxes(int joy);

		static const std::vector<uint8_t> GetJoystickButtons(int joy);

		static std::string GetJoystickName(int joy);

		keyfun SetKeyCallback(keyfun cbfun);

		charfun SetCharCallback(charfun cbfun);

		mousebuttonfun SetMouseButtonCallback(mousebuttonfun cbfun);

		cursorposfun SetCursorPosCallback(cursorposfun cbfun);

		cursorenterfun SetCursorEnterCallback(cursorenterfun cbfun);

		scrollfun SetScrollCallback(scrollfun cbfun);

		dropfun SetDropCallback(dropfun cbfun);

		void SwapBuffers();

		void MakeContextCurrent();

		void SetClipboard(std::string clipboard);

		std::string GetClipboard() const;

		static void DefaultHints();
		static void Hint(int target, int hint);

		void Create(int width, int height, const std::string &title, const Monitor &monitor, const Window &share);
		void Create(int width, int height, const std::string &title, const Monitor &monitor);
		void Create(int width, int height, const std::string &title, const Window &share);
		void Create(int width, int height, const std::string &title);

		int ShouldClose() const;
		void SetShouldClose(int value);

		void SetTitle(std::string title);

		int GetPosX() const;
		int GetPosY() const;
		void SetPos(int x, int y);

		int GetSizeX() const;
		int GetSizeY() const;
		void SetSize(int x, int y);

		int GetFramebufferSizeX() const;
		int GetFramebufferSizeY() const;

		void Iconify();
		void Restore();
		void Show();
		void Hide();

		Monitor GetMonitor() const;

		int GetAttrib(int attrib) const;

		void SetUserPointer(void *pointer);
		void* GetUserPointer() const;

		static void PollEvents();
		static void WaitEvents();

		GLFWwindow* GetRawPointerData() const;

		windowposfun SetPosCallback(windowposfun cbfun);
		windowsizefun SetSizeCallback(windowsizefun cbfun);
		windowclosefun SetCloseCallback(windowclosefun cbfun);
		windowrefreshfun SetRefreshCallback(windowrefreshfun cbfun);
		windowfocusfun SetFocusCallback(windowfocusfun cbfun);
		windowiconifyfun SetIconifyCallback(windowiconifyfun cbfun);
		framebuffersizefun SetFramebufferSizeCallback(framebuffersizefun cbfun);

		Window(int width, int height, const std::string &title, const Monitor &monitor, const Window &share);
		Window(int width, int height, const std::string &title, const Monitor &monitor);
		Window(int width, int height, const std::string &title, const Window &share);
		Window(int width, int height, const std::string &title);
		Window(GLFWwindow* window);
		~Window();
	};
}
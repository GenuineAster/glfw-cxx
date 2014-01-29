#include <glfw-c++/Window.hpp>

namespace glfw
{
	void Window::SetClipboard(std::string clipboard)
	{
		glfwSetClipboardString(m_window, clipboard.c_str());
	}

	std::string Window::GetClipboard() const
	{
		return std::string{glfwGetClipboardString(m_window)};
	}

	void Window::DefaultHints()
	{
		glfwDefaultWindowHints();
	}
	
	void Window::Hint(int target, int hint)
	{
		glfwWindowHint(target,hint);
	}

	void Window::Create(int width, int height, const std::string &title, const Monitor &monitor, const Window &share)
	{
		m_window = glfwCreateWindow(width, height, title.c_str(), monitor.GetRawPointerData(), share.GetRawPointerData());
	}

	void Window::Create(int width, int height, const std::string &title, const Monitor &monitor)
	{
		m_window = glfwCreateWindow(width, height, title.c_str(), monitor.GetRawPointerData(), NULL);
	}

	void Window::Create(int width, int height, const std::string &title, const Window &share)
	{
		m_window = glfwCreateWindow(width, height, title.c_str(), NULL, share.GetRawPointerData());
	}

	void Window::Create(int width, int height, const std::string &title)
	{
		m_window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
	}

	int Window::ShouldClose() const
	{
		return glfwWindowShouldClose(m_window);
	}

	void Window::SetShouldClose(int value)
	{
		glfwSetWindowShouldClose(m_window, value);
	}

	void Window::SetTitle(std::string title)
	{
		glfwSetWindowTitle(m_window, title.c_str());
	}

	int Window::GetPosX() const
	{
		int x,y;
		glfwGetWindowPos(m_window, &x, &y);
		return x;
	}

	int Window::GetPosY() const
	{
		int x,y;
		glfwGetWindowPos(m_window, &x, &y);
		return y;
	}

	void Window::SetPos(int x, int y)
	{
		glfwSetWindowPos(m_window, x, y);
	}

	int Window::GetSizeX() const
	{
		int x,y;
		glfwGetWindowSize(m_window, &x, &y);
		return x;
	}

	int Window::GetSizeY() const
	{
		int x,y;
		glfwGetWindowSize(m_window, &x, &y);
		return y;
	}

	void Window::SetSize(int x, int y)
	{
		glfwSetWindowSize(m_window, x, y);
	}

	int Window::GetFramebufferSizeX() const
	{
		int x,y;
		glfwGetFramebufferSize(m_window, &x, &y);
		return x;
	}

	int Window::GetFramebufferSizeY() const
	{
		int x,y;
		glfwGetFramebufferSize(m_window, &x, &y);
		return y;
	}

	void Window::Iconify()
	{
		glfwIconifyWindow(m_window);
	}

	void Window::Restore()
	{
		glfwRestoreWindow(m_window);
	}

	void Window::Show()
	{
		glfwShowWindow(m_window);
	}

	void Window::Hide()
	{
		glfwHideWindow(m_window);
	}

	Monitor Window::GetMonitor() const
	{
		return Monitor(glfwGetWindowMonitor(m_window));
	}

	int Window::GetAttrib(int attrib) const
	{
		return glfwGetWindowAttrib(m_window, attrib);
	}

	void Window::SetUserPointer(void* pointer)
	{
		glfwSetWindowUserPointer(m_window, pointer);
	}

	void* Window::GetUserPointer() const
	{
		return glfwGetWindowUserPointer(m_window);
	}

	void Window::PollEvents()
	{
		glfwPollEvents();
	}

	void Window::WaitEvents()
	{
		glfwWaitEvents();
	}

	GLFWwindow* Window::GetRawPointerData() const
	{
		return m_window;
	}

	windowposfun Window::SetPosCallback(windowposfun cbfun)
	{
		return glfwSetWindowPosCallback(m_window, cbfun);
	}

	windowsizefun Window::SetSizeCallback(windowsizefun cbfun)
	{
		return glfwSetWindowSizeCallback(m_window, cbfun);
	}

	windowclosefun Window::SetCloseCallback(windowclosefun cbfun)
	{
		return glfwSetWindowCloseCallback(m_window, cbfun);
	}

	windowrefreshfun Window::SetRefreshCallback(windowrefreshfun cbfun)
	{
		return glfwSetWindowRefreshCallback(m_window, cbfun);
	}

	windowfocusfun Window::SetFocusCallback(windowfocusfun cbfun)
	{
		return glfwSetWindowFocusCallback(m_window, cbfun);
	}

	windowiconifyfun Window::SetIconifyCallback(windowiconifyfun cbfun)
	{
		return glfwSetWindowIconifyCallback(m_window, cbfun);
	}

	framebuffersizefun Window::SetFramebufferSizeCallback(framebuffersizefun cbfun)
	{
		return glfwSetFramebufferSizeCallback(m_window, cbfun);
	}


	Window::Window(int width, int height, const std::string &title, const Monitor &monitor, const Window &share)
	{
		m_window = glfwCreateWindow(width, height, title.c_str(), monitor.GetRawPointerData(), share.GetRawPointerData());
	}

	Window::Window(int width, int height, const std::string &title, const Monitor &monitor)
	{
		m_window = glfwCreateWindow(width, height, title.c_str(), monitor.GetRawPointerData(), NULL);
	}

	Window::Window(int width, int height, const std::string &title, const Window &share)
	{
		m_window = glfwCreateWindow(width, height, title.c_str(), NULL, share.GetRawPointerData());
	}

	Window::Window(int width, int height, const std::string &title)
	{
		m_window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
	}

	Window::~Window()
	{
		glfwDestroyWindow(m_window);
	}
}
#include <glfw-cxx/Window.hpp>
#include <glfw-cxx/Context.hpp>
#include <iostream>

namespace glfw
{
	int Window::GetInputMode(int mode) const
	{
		return glfwGetInputMode(m_window, mode);
	}

	void Window::SetInputMode(int mode, int value)
	{
		glfwSetInputMode(m_window, mode, value);
	}

	int Window::GetKey(Key key) const
	{
		return glfwGetKey(m_window, key);
	}

	int Window::GetMouseButton(int button) const
	{
		return glfwGetMouseButton(m_window, button);
	}

	CursorPos Window::GetCursorPos() const
	{
		double x,y;
		glfwGetCursorPos(m_window, &x, &y);
		return CursorPos(x,y);
	}

	void Window::SetCursorPos(CursorPos pos)
	{
		glfwSetCursorPos(m_window, pos.x, pos.y);
	}

	void Window::SetCursorPos(double x, double y)
	{
		glfwSetCursorPos(m_window, x, y);
	}

	int Window::JoystickPresent(Joystick joy)
	{
		return glfwJoystickPresent(joy);
	}

	std::vector<float> Window::GetJoystickAxes(Joystick joy)
	{
		int count;
		const float* temp = glfwGetJoystickAxes(joy, &count);
		return std::vector<float>(*temp, count);
	}

	const std::vector<uint8_t> Window::GetJoystickButtons(Joystick joy)
	{
		int count;
		const uint8_t* temp = glfwGetJoystickButtons(joy, &count);
		return std::vector<uint8_t>(*temp, count);
	}

	std::string Window::GetJoystickName(Joystick joy)
	{
		return std::string(glfwGetJoystickName(joy));
	}

	void Window::SwapBuffers()
	{
		glfwSwapBuffers(m_window);
	}

	void Window::MakeContextCurrent()
	{
		glfw::Context::MakeContextCurrent(*this);
	}

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
		PrepareCallbacks();
	}

	void Window::Create(int width, int height, const std::string &title, const Monitor &monitor)
	{
		m_window = glfwCreateWindow(width, height, title.c_str(), monitor.GetRawPointerData(), NULL);
		PrepareCallbacks();
	}

	void Window::Create(int width, int height, const std::string &title, const Window &share)
	{
		m_window = glfwCreateWindow(width, height, title.c_str(), NULL, share.GetRawPointerData());
		PrepareCallbacks();
	}

	void Window::Create(int width, int height, const std::string &title)
	{
		m_window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
		PrepareCallbacks();
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

	WindowPos Window::GetPos() const
	{
		int x,y;
		glfwGetWindowPos(m_window, &x, &y);
		return WindowPos(x, y);
	}

	void Window::SetPos(WindowPos pos)
	{
		glfwSetWindowPos(m_window, pos.x, pos.y);
	}

	void Window::SetPos(int x, int y)
	{
		glfwSetWindowPos(m_window, x, y);
	}

	WindowSize Window::GetSize() const
	{
		int x,y;
		glfwGetWindowSize(m_window, &x, &y);
		return WindowSize(x,y);
	}

	void Window::SetSize(WindowSize size)
	{
		glfwSetWindowSize(m_window, size.x, size.y);
	}

	void Window::SetSize(int x, int y)
	{
		glfwSetWindowSize(m_window, x, y);
	}

	FramebufferSize Window::GetFramebufferSize() const
	{
		int x,y;
		glfwGetFramebufferSize(m_window, &x, &y);
		return FramebufferSize(x,y);
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

	bool Window::GetEvents(Event &event)
	{
		if(glfwGetWindowUserPointer(m_window) == NULL)
			return false;

		std::cout<<"Getting event from queue...\n";
		std::queue<Event>* event_queue = 
			static_cast<std::queue<Event>*>(glfwGetWindowUserPointer(m_window));

		if(!event_queue->empty())
		{
			event = event_queue->front();
			event_queue->pop();
			return true;
		}
		return false;
	}

	void Window::AddToEventQueue(Event &event)
	{
		std::cout<<"Adding event to queue...\n";
		std::queue<Event>* event_queue;
		if(glfwGetWindowUserPointer(m_window) != NULL)
			event_queue = static_cast<std::queue<Event>*>(glfwGetWindowUserPointer(m_window));
		else
			event_queue = new std::queue<Event>;

		glfwSetWindowUserPointer(m_window, event_queue);

		event_queue->push(event);
		std::cout<<"Queue size is now: "<<event_queue->size()<<".\n";
	}

	GLFWwindow* Window::GetRawPointerData() const
	{
		return m_window;
	}

	Window::operator GLFWwindow*()
	{
		return m_window;
	}

	void Window::PrepareCallbacks()
	{
		glfwSetWindowPosCallback(m_window, CurrentPositionFunctionPointerRaw);
		glfwSetWindowSizeCallback(m_window, CurrentSizeFunctionPointerRaw);
		glfwSetWindowCloseCallback(m_window, CurrentCloseFunctionPointerRaw);
		glfwSetWindowRefreshCallback(m_window, CurrentRefreshFunctionPointerRaw);
		glfwSetWindowFocusCallback(m_window, CurrentFocusFunctionPointerRaw);
		glfwSetWindowIconifyCallback(m_window, CurrentIconifyFunctionPointerRaw);
		glfwSetFramebufferSizeCallback(m_window, CurrentFramebufferSizeFunctionPointerRaw);

		glfwSetMouseButtonCallback(m_window, CurrentMouseButtonFunctionPointerRaw);
		glfwSetCursorPosCallback(m_window, CurrentCursorPositionFunctionPointerRaw);
		glfwSetCursorEnterCallback(m_window, CurrentCursorEnterFunctionPointerRaw);
		glfwSetScrollCallback(m_window, CurrentScrollFunctionPointerRaw);
		glfwSetKeyCallback(m_window, CurrentKeyFunctionPointerRaw);
		glfwSetCharCallback(m_window, CurrentCharFunctionPointerRaw);
	}

	Window::Window(int width, int height, const std::string &title, const Monitor &monitor, const Window &share)
	{
		m_window = glfwCreateWindow(width, height, title.c_str(), monitor.GetRawPointerData(), share.GetRawPointerData());
		m_destroy = true;
	}

	Window::Window(int width, int height, const std::string &title, const Monitor &monitor)
	{
		m_window = glfwCreateWindow(width, height, title.c_str(), monitor.GetRawPointerData(), NULL);
		m_destroy = true;
	}

	Window::Window(int width, int height, const std::string &title, const Window &share)
	{
		m_window = glfwCreateWindow(width, height, title.c_str(), NULL, share.GetRawPointerData());
		m_destroy = true;
	}

	Window::Window(int width, int height, const std::string &title)
	{
		m_window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
		m_destroy = true;
	}

	Window::Window(GLFWwindow* window)
	{
		m_window = window;
		m_destroy = false;
		PrepareCallbacks();
	}

	Window::Window()
	{
		m_destroy = true;
		//using Window::LambdaPositionFunctionWrapper;
		//using Window::PositionFunctionPointerWrapper;
	}

	Window::~Window()
	{
		if(m_destroy)
			glfwDestroyWindow(m_window);
	}
}

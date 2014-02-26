#include <glfw-cxx/Window.hpp>

namespace glfw
{
	//Window Position
		void Window::LambdaPositionFunctionWrapper(Window window, WindowPos pos)
		{
			window.CurrentPositionFunction(window, pos);
		}

		void Window::PositionFunctionPointerWrapper(GLFWwindow* window, int PosX, int PosY)
		{
			Window{window}.CurrentPositionFunctionPointer({window}, {PosX, PosY});
		}

		const Window::PositionFunction Window::DefaultPositionFunction = 
		[](Window window, WindowPos pos)
		{
			Event event;
			event.type = Event::Type::WindowPosition;
			event.window_position.position = pos;
			window.EventQueue.push(event);
		};

		Window::PositionFunction Window::GetDefaultPositionCallback()
		{
			return DefaultPositionFunction;
		}

		void Window::SetPositionCallback(PositionFunction fun)
		{
			CurrentPositionFunction = fun;
			CurrentPositionFunctionPointer = *LambdaPositionFunctionWrapper;
			CurrentPositionFunctionPointerRaw = *PositionFunctionPointerWrapper;
			glfwSetWindowPosCallback(m_window, CurrentPositionFunctionPointerRaw);
		}

		void Window::SetPositionCallback(PositionFunctionPointer fun)
		{
			CurrentPositionFunctionPointer = fun;
			CurrentPositionFunctionPointerRaw = *PositionFunctionPointerWrapper;
			glfwSetWindowPosCallback(m_window, CurrentPositionFunctionPointerRaw);
		}

		void Window::SetPositionCallback(PositionFunctionPointerRaw fun)
		{
			CurrentPositionFunctionPointerRaw = fun;
			glfwSetWindowPosCallback(m_window, CurrentPositionFunctionPointerRaw);
		}

	//Window Size
		void Window::LambdaSizeFunctionWrapper(Window window, WindowSize size)
		{
			window.CurrentSizeFunction(window, size);
		}

		void Window::SizeFunctionPointerWrapper(GLFWwindow* window, int SizeX, int SizeY)
		{
			Window{window}.CurrentSizeFunctionPointer({window}, {SizeX, SizeY});
		}

		const Window::SizeFunction Window::DefaultSizeFunction = 
		[](Window window, WindowSize size)
		{
			Event event;
			event.type = Event::Type::WindowSize;
			event.window_size.size = size;
			window.EventQueue.push(event);
		};

		Window::SizeFunction Window::GetDefaultSizeCallback()
		{
			return DefaultSizeFunction;
		}

		void Window::SetSizeCallback(SizeFunction fun)
		{
			CurrentSizeFunction = fun;
			CurrentSizeFunctionPointer = *LambdaSizeFunctionWrapper;
			CurrentSizeFunctionPointerRaw = *SizeFunctionPointerWrapper;
			glfwSetWindowSizeCallback(m_window, CurrentSizeFunctionPointerRaw);
		}

		void Window::SetSizeCallback(SizeFunctionPointer fun)
		{
			CurrentSizeFunctionPointer = fun;
			CurrentSizeFunctionPointerRaw = *SizeFunctionPointerWrapper;
			glfwSetWindowSizeCallback(m_window, CurrentSizeFunctionPointerRaw);
		}

		void Window::SetSizeCallback(SizeFunctionPointerRaw fun)
		{
			CurrentSizeFunctionPointerRaw = fun;
			glfwSetWindowSizeCallback(m_window, CurrentSizeFunctionPointerRaw);
		}

	//Window Close
		void Window::LambdaCloseFunctionWrapper(Window window)
		{
			window.CurrentCloseFunction(window);
		}

		void Window::CloseFunctionPointerWrapper(GLFWwindow* window)
		{
			Window{window}.CurrentCloseFunctionPointer({window});
		}

		const Window::CloseFunction Window::DefaultCloseFunction = 
		[](Window window)
		{
			Event event;
			event.type = Event::Type::WindowClose;
			window.EventQueue.push(event);
		};

		Window::CloseFunction Window::GetDefaultCloseCallback()
		{
			return DefaultCloseFunction;
		}

		void Window::SetCloseCallback(CloseFunction fun)
		{
			CurrentCloseFunction = fun;
			CurrentCloseFunctionPointer = *LambdaCloseFunctionWrapper;
			CurrentCloseFunctionPointerRaw = *CloseFunctionPointerWrapper;
			glfwSetWindowCloseCallback(m_window, CurrentCloseFunctionPointerRaw);
		}

		void Window::SetCloseCallback(CloseFunctionPointer fun)
		{
			CurrentCloseFunctionPointer = fun;
			CurrentCloseFunctionPointerRaw = *CloseFunctionPointerWrapper;
			glfwSetWindowCloseCallback(m_window, CurrentCloseFunctionPointerRaw);
		}

		void Window::SetCloseCallback(CloseFunctionPointerRaw fun)
		{
			CurrentCloseFunctionPointerRaw = fun;
			glfwSetWindowCloseCallback(m_window, CurrentCloseFunctionPointerRaw);
		}

	//Window Refresh
		void Window::LambdaRefreshFunctionWrapper(Window window)
		{
			window.CurrentRefreshFunction(window);
		}

		void Window::RefreshFunctionPointerWrapper(GLFWwindow* window)
		{
			Window{window}.CurrentRefreshFunctionPointer({window});
		}

		const Window::RefreshFunction Window::DefaultRefreshFunction = 
		[](Window window)
		{
			Event event;
			event.type = Event::Type::WindowRefresh;
			window.EventQueue.push(event);
		};

		Window::RefreshFunction Window::GetDefaultRefreshCallback()
		{
			return DefaultRefreshFunction;
		}

		void Window::SetRefreshCallback(RefreshFunction fun)
		{
			CurrentRefreshFunction = fun;
			CurrentRefreshFunctionPointer = *LambdaRefreshFunctionWrapper;
			CurrentRefreshFunctionPointerRaw = *RefreshFunctionPointerWrapper;
			glfwSetWindowRefreshCallback(m_window, CurrentRefreshFunctionPointerRaw);
		}

		void Window::SetRefreshCallback(RefreshFunctionPointer fun)
		{
			CurrentRefreshFunctionPointer = fun;
			CurrentRefreshFunctionPointerRaw = *RefreshFunctionPointerWrapper;
			glfwSetWindowRefreshCallback(m_window, CurrentRefreshFunctionPointerRaw);
		}

		void Window::SetRefreshCallback(RefreshFunctionPointerRaw fun)
		{
			CurrentRefreshFunctionPointerRaw = fun;
			glfwSetWindowRefreshCallback(m_window, CurrentRefreshFunctionPointerRaw);
		}

	//Window Focus
		void Window::LambdaFocusFunctionWrapper(Window window, int focus)
		{
			window.CurrentFocusFunction(window, focus);
		}

		void Window::FocusFunctionPointerWrapper(GLFWwindow* window, int focus)
		{
			Window{window}.CurrentFocusFunctionPointer({window}, focus);
		}

		const Window::FocusFunction Window::DefaultFocusFunction = 
		[](Window window, int focus)
		{
			Event event;
			event.type = Event::Type::WindowFocus;
			event.window_focus.focused = focus;
			window.EventQueue.push(event);
		};

		Window::FocusFunction Window::GetDefaultFocusCallback()
		{
			return DefaultFocusFunction;
		}

		void Window::SetFocusCallback(FocusFunction fun)
		{
			CurrentFocusFunction = fun;
			CurrentFocusFunctionPointer = *LambdaFocusFunctionWrapper;
			CurrentFocusFunctionPointerRaw = *FocusFunctionPointerWrapper;
			glfwSetWindowFocusCallback(m_window, CurrentFocusFunctionPointerRaw);
		}

		void Window::SetFocusCallback(FocusFunctionPointer fun)
		{
			CurrentFocusFunctionPointer = fun;
			CurrentFocusFunctionPointerRaw = *FocusFunctionPointerWrapper;
			glfwSetWindowFocusCallback(m_window, CurrentFocusFunctionPointerRaw);
		}

		void Window::SetFocusCallback(FocusFunctionPointerRaw fun)
		{
			CurrentFocusFunctionPointerRaw = fun;
			glfwSetWindowFocusCallback(m_window, CurrentFocusFunctionPointerRaw);
		}

	//Window Iconify
		void Window::LambdaIconifyFunctionWrapper(Window window, int iconify)
		{
			window.CurrentIconifyFunction(window, iconify);
		}

		void Window::IconifyFunctionPointerWrapper(GLFWwindow* window, int iconify)
		{
			Window{window}.CurrentIconifyFunctionPointer({window}, iconify);
		}

		const Window::IconifyFunction Window::DefaultIconifyFunction = 
		[](Window window, int iconify)
		{
			Event event;
			event.type = Event::Type::WindowIconify;
			event.window_iconify.iconified = iconify;
			window.EventQueue.push(event);
		};

		Window::IconifyFunction Window::GetDefaultIconifyCallback()
		{
			return DefaultIconifyFunction;
		}

		void Window::SetIconifyCallback(IconifyFunction fun)
		{
			CurrentIconifyFunction = fun;
			CurrentIconifyFunctionPointer = *LambdaIconifyFunctionWrapper;
			CurrentIconifyFunctionPointerRaw = *IconifyFunctionPointerWrapper;
			glfwSetWindowIconifyCallback(m_window, CurrentIconifyFunctionPointerRaw);
		}

		void Window::SetIconifyCallback(IconifyFunctionPointer fun)
		{
			CurrentIconifyFunctionPointer = fun;
			CurrentIconifyFunctionPointerRaw = *IconifyFunctionPointerWrapper;
			glfwSetWindowIconifyCallback(m_window, CurrentIconifyFunctionPointerRaw);
		}

		void Window::SetIconifyCallback(IconifyFunctionPointerRaw fun)
		{
			CurrentIconifyFunctionPointerRaw = fun;
			glfwSetWindowIconifyCallback(m_window, CurrentIconifyFunctionPointerRaw);
		}

	//Framebuffer Size
		void Window::LambdaFramebufferSizeFunctionWrapper(Window window, FramebufferSize Framebuffersize)
		{
			window.CurrentFramebufferSizeFunction(window, Framebuffersize);
		}

		void Window::FramebufferSizeFunctionPointerWrapper(GLFWwindow* window, int FramebufferSizeX, int FramebufferSizeY)
		{
			Window{window}.CurrentFramebufferSizeFunctionPointer({window}, {FramebufferSizeX, FramebufferSizeY});
		}

		const Window::FramebufferSizeFunction Window::DefaultFramebufferSizeFunction = 
		[](Window window, FramebufferSize framebuffersize)
		{
			Event event;
			event.type = Event::Type::FramebufferSize;
			event.fb_size.size = framebuffersize;
			window.EventQueue.push(event);
		};

		Window::FramebufferSizeFunction Window::GetDefaultFramebufferSizeCallback()
		{
			return DefaultFramebufferSizeFunction;
		}

		void Window::SetFramebufferSizeCallback(FramebufferSizeFunction fun)
		{
			CurrentFramebufferSizeFunction = fun;
			CurrentFramebufferSizeFunctionPointer = *LambdaFramebufferSizeFunctionWrapper;
			CurrentFramebufferSizeFunctionPointerRaw = *FramebufferSizeFunctionPointerWrapper;
			glfwSetFramebufferSizeCallback(m_window, CurrentFramebufferSizeFunctionPointerRaw);
		}

		void Window::SetFramebufferSizeCallback(FramebufferSizeFunctionPointer fun)
		{
			CurrentFramebufferSizeFunctionPointer = fun;
			CurrentFramebufferSizeFunctionPointerRaw = *FramebufferSizeFunctionPointerWrapper;
			glfwSetFramebufferSizeCallback(m_window, CurrentFramebufferSizeFunctionPointerRaw);
		}

		void Window::SetFramebufferSizeCallback(FramebufferSizeFunctionPointerRaw fun)
		{
			CurrentFramebufferSizeFunctionPointerRaw = fun;
			glfwSetFramebufferSizeCallback(m_window, CurrentFramebufferSizeFunctionPointerRaw);
		}
}

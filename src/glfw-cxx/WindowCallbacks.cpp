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
			;
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
		}

		void Window::SetPositionCallback(PositionFunctionPointer fun)
		{
			CurrentPositionFunctionPointer = fun;
			CurrentPositionFunctionPointerRaw = *PositionFunctionPointerWrapper;
		}

		void Window::SetPositionCallback(PositionFunctionPointerRaw fun)
		{
			CurrentPositionFunctionPointerRaw = fun;
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
			;
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
		}

		void Window::SetSizeCallback(SizeFunctionPointer fun)
		{
			CurrentSizeFunctionPointer = fun;
			CurrentSizeFunctionPointerRaw = *SizeFunctionPointerWrapper;
		}

		void Window::SetSizeCallback(SizeFunctionPointerRaw fun)
		{
			CurrentSizeFunctionPointerRaw = fun;
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
			;
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
		}

		void Window::SetCloseCallback(CloseFunctionPointer fun)
		{
			CurrentCloseFunctionPointer = fun;
			CurrentCloseFunctionPointerRaw = *CloseFunctionPointerWrapper;
		}

		void Window::SetCloseCallback(CloseFunctionPointerRaw fun)
		{
			CurrentCloseFunctionPointerRaw = fun;
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
			;
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
		}

		void Window::SetRefreshCallback(RefreshFunctionPointer fun)
		{
			CurrentRefreshFunctionPointer = fun;
			CurrentRefreshFunctionPointerRaw = *RefreshFunctionPointerWrapper;
		}

		void Window::SetRefreshCallback(RefreshFunctionPointerRaw fun)
		{
			CurrentRefreshFunctionPointerRaw = fun;
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
			;
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
		}

		void Window::SetFocusCallback(FocusFunctionPointer fun)
		{
			CurrentFocusFunctionPointer = fun;
			CurrentFocusFunctionPointerRaw = *FocusFunctionPointerWrapper;
		}

		void Window::SetFocusCallback(FocusFunctionPointerRaw fun)
		{
			CurrentFocusFunctionPointerRaw = fun;
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
			;
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
		}

		void Window::SetIconifyCallback(IconifyFunctionPointer fun)
		{
			CurrentIconifyFunctionPointer = fun;
			CurrentIconifyFunctionPointerRaw = *IconifyFunctionPointerWrapper;
		}

		void Window::SetIconifyCallback(IconifyFunctionPointerRaw fun)
		{
			CurrentIconifyFunctionPointerRaw = fun;
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
		[](Window window, FramebufferSize Framebuffersize)
		{
			;
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
		}

		void Window::SetFramebufferSizeCallback(FramebufferSizeFunctionPointer fun)
		{
			CurrentFramebufferSizeFunctionPointer = fun;
			CurrentFramebufferSizeFunctionPointerRaw = *FramebufferSizeFunctionPointerWrapper;
		}

		void Window::SetFramebufferSizeCallback(FramebufferSizeFunctionPointerRaw fun)
		{
			CurrentFramebufferSizeFunctionPointerRaw = fun;
		}
}
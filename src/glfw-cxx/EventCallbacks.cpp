#include <glfw-cxx/Window.hpp>

namespace glfw
{
	//Mouse Button
		void Window::LambdaMouseButtonFunctionWrapper(Window window, MouseButton button, KeyAction action, Modifier modifier)
		{
			window.CurrentMouseButtonFunction(window, button, action, modifier);
		}

		void Window::MouseButtonFunctionPointerWrapper(GLFWwindow* window, int button, int action, int modifier)
		{
			Window{window}.CurrentMouseButtonFunctionPointer(
				{window}, 
				static_cast<MouseButton>(button), 
				static_cast<KeyAction>(action), 
				static_cast<Modifier>(modifier)
			);
		}

		const Window::MouseButtonFunction Window::DefaultMouseButtonFunction = 
		[](Window window, MouseButton button, KeyAction action, Modifier modifier)
		{
			;
		};

		Window::MouseButtonFunction Window::GetDefaultMouseButtonCallback()
		{
			return DefaultMouseButtonFunction;
		}

		void Window::SetMouseButtonCallback(MouseButtonFunction fun)
		{
			CurrentMouseButtonFunction = fun;
			CurrentMouseButtonFunctionPointer = *LambdaMouseButtonFunctionWrapper;
			CurrentMouseButtonFunctionPointerRaw = *MouseButtonFunctionPointerWrapper;
		}

		void Window::SetMouseButtonCallback(MouseButtonFunctionPointer fun)
		{
			CurrentMouseButtonFunctionPointer = fun;
			CurrentMouseButtonFunctionPointerRaw = *MouseButtonFunctionPointerWrapper;
		}

		void Window::SetMouseButtonCallback(MouseButtonFunctionPointerRaw fun)
		{
			CurrentMouseButtonFunctionPointerRaw = fun;
		}

	//Cursor Position
		void Window::LambdaCursorPositionFunctionWrapper(Window window, CursorPos pos)
		{
			window.CurrentCursorPositionFunction(window, pos);
		}

		void Window::CursorPositionFunctionPointerWrapper(GLFWwindow* window, double PosX, double PosY)
		{
			Window{window}.CurrentCursorPositionFunctionPointer({window}, {PosX, PosY});
		}

		const Window::CursorPositionFunction Window::DefaultCursorPositionFunction = 
		[](Window window, CursorPos pos)
		{
			;
		};

		Window::CursorPositionFunction Window::GetDefaultCursorPositionCallback()
		{
			return DefaultCursorPositionFunction;
		}

		void Window::SetCursorPositionCallback(CursorPositionFunction fun)
		{
			CurrentCursorPositionFunction = fun;
			CurrentCursorPositionFunctionPointer = *LambdaCursorPositionFunctionWrapper;
			CurrentCursorPositionFunctionPointerRaw = *CursorPositionFunctionPointerWrapper;
		}

		void Window::SetCursorPositionCallback(CursorPositionFunctionPointer fun)
		{
			CurrentCursorPositionFunctionPointer = fun;
			CurrentCursorPositionFunctionPointerRaw = *CursorPositionFunctionPointerWrapper;
		}

		void Window::SetCursorPositionCallback(CursorPositionFunctionPointerRaw fun)
		{
			CurrentCursorPositionFunctionPointerRaw = fun;
		}

	//Cursor Enter
		void Window::LambdaCursorEnterFunctionWrapper(Window window, int CursorEnter)
		{
			window.CurrentCursorEnterFunction(window, CursorEnter);
		}

		void Window::CursorEnterFunctionPointerWrapper(GLFWwindow* window, int CursorEnter)
		{
			Window{window}.CurrentCursorEnterFunctionPointer({window}, CursorEnter);
		}

		const Window::CursorEnterFunction Window::DefaultCursorEnterFunction = 
		[](Window window, int CursorEnter)
		{
			;
		};

		Window::CursorEnterFunction Window::GetDefaultCursorEnterCallback()
		{
			return DefaultCursorEnterFunction;
		}

		void Window::SetCursorEnterCallback(CursorEnterFunction fun)
		{
			CurrentCursorEnterFunction = fun;
			CurrentCursorEnterFunctionPointer = *LambdaCursorEnterFunctionWrapper;
			CurrentCursorEnterFunctionPointerRaw = *CursorEnterFunctionPointerWrapper;
		}

		void Window::SetCursorEnterCallback(CursorEnterFunctionPointer fun)
		{
			CurrentCursorEnterFunctionPointer = fun;
			CurrentCursorEnterFunctionPointerRaw = *CursorEnterFunctionPointerWrapper;
		}

		void Window::SetCursorEnterCallback(CursorEnterFunctionPointerRaw fun)
		{
			CurrentCursorEnterFunctionPointerRaw = fun;
		}


	//Scroll Offset
		void Window::LambdaScrollFunctionWrapper(Window window, ScrollOffset pos)
		{
			window.CurrentScrollFunction(window, pos);
		}

		void Window::ScrollFunctionPointerWrapper(GLFWwindow* window, double PosX, double PosY)
		{
			Window{window}.CurrentScrollFunctionPointer({window}, {PosX, PosY});
		}

		const Window::ScrollFunction Window::DefaultScrollFunction = 
		[](Window window, ScrollOffset pos)
		{
			;
		};

		Window::ScrollFunction Window::GetDefaultScrollCallback()
		{
			return DefaultScrollFunction;
		}

		void Window::SetScrollCallback(ScrollFunction fun)
		{
			CurrentScrollFunction = fun;
			CurrentScrollFunctionPointer = *LambdaScrollFunctionWrapper;
			CurrentScrollFunctionPointerRaw = *ScrollFunctionPointerWrapper;
		}

		void Window::SetScrollCallback(ScrollFunctionPointer fun)
		{
			CurrentScrollFunctionPointer = fun;
			CurrentScrollFunctionPointerRaw = *ScrollFunctionPointerWrapper;
		}

		void Window::SetScrollCallback(ScrollFunctionPointerRaw fun)
		{
			CurrentScrollFunctionPointerRaw = fun;
		}

	//Key Action
		void Window::LambdaKeyFunctionWrapper(Window window, Key key, int scancode, KeyAction action, Modifier modifier)
		{
			window.CurrentKeyFunction(window, key, scancode, action, modifier);
		}

		void Window::KeyFunctionPointerWrapper(GLFWwindow* window, int key, int scancode, int action, int modifier)
		{
			Window{window}.CurrentKeyFunctionPointer(
				{window}, 
				static_cast<Key>(key),
				scancode,
				static_cast<KeyAction>(action), 
				static_cast<Modifier>(modifier)
			);
		}

		const Window::KeyFunction Window::DefaultKeyFunction = 
		[](Window window, Key key, int scancode, KeyAction action, Modifier modifier)
		{
			;
		};

		Window::KeyFunction Window::GetDefaultKeyCallback()
		{
			return DefaultKeyFunction;
		}

		void Window::SetKeyCallback(KeyFunction fun)
		{
			CurrentKeyFunction = fun;
			CurrentKeyFunctionPointer = *LambdaKeyFunctionWrapper;
			CurrentKeyFunctionPointerRaw = *KeyFunctionPointerWrapper;
		}

		void Window::SetKeyCallback(KeyFunctionPointer fun)
		{
			CurrentKeyFunctionPointer = fun;
			CurrentKeyFunctionPointerRaw = *KeyFunctionPointerWrapper;
		}

		void Window::SetKeyCallback(KeyFunctionPointerRaw fun)
		{
			CurrentKeyFunctionPointerRaw = fun;
		}

	//Char
		void Window::LambdaCharFunctionWrapper(Window window, unsigned int codepoint)
		{
			window.CurrentCharFunction(window, codepoint);
		}

		void Window::CharFunctionPointerWrapper(GLFWwindow* window, unsigned int codepoint)
		{
			Window{window}.CurrentCharFunctionPointer({window}, codepoint);
		}

		const Window::CharFunction Window::DefaultCharFunction = 
		[](Window window, unsigned int codepoint)
		{
			;
		};

		Window::CharFunction Window::GetDefaultCharCallback()
		{
			return DefaultCharFunction;
		}

		void Window::SetCharCallback(CharFunction fun)
		{
			CurrentCharFunction = fun;
			CurrentCharFunctionPointer = *LambdaCharFunctionWrapper;
			CurrentCharFunctionPointerRaw = *CharFunctionPointerWrapper;
		}

		void Window::SetCharCallback(CharFunctionPointer fun)
		{
			CurrentCharFunctionPointer = fun;
			CurrentCharFunctionPointerRaw = *CharFunctionPointerWrapper;
		}

		void Window::SetCharCallback(CharFunctionPointerRaw fun)
		{
			CurrentCharFunctionPointerRaw = fun;
		}
}
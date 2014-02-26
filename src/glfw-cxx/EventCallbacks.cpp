#include <glfw-cxx/Window.hpp>
#include <iostream>

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
			Event event;
			event.type = Event::Type::MouseButton;
			event.mouse_button.button = button;
			event.mouse_button.action = action;
			event.mouse_button.modifier = modifier;
			window.EventQueue.push(event);
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
			glfwSetMouseButtonCallback(m_window, CurrentMouseButtonFunctionPointerRaw);
		}

		void Window::SetMouseButtonCallback(MouseButtonFunctionPointer* fun)
		{
			CurrentMouseButtonFunctionPointer = fun;
			CurrentMouseButtonFunctionPointerRaw = *MouseButtonFunctionPointerWrapper;
			glfwSetMouseButtonCallback(m_window, CurrentMouseButtonFunctionPointerRaw);
		}

		void Window::SetMouseButtonCallback(MouseButtonFunctionPointerRaw* fun)
		{
			CurrentMouseButtonFunctionPointerRaw = fun;
			glfwSetMouseButtonCallback(m_window, CurrentMouseButtonFunctionPointerRaw);
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
			Event event;
			event.type = Event::Type::CursorPosition;
			event.cursor_position.position = pos;
			window.EventQueue.push(event);
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
			glfwSetCursorPosCallback(m_window, CurrentCursorPositionFunctionPointerRaw);
		}

		void Window::SetCursorPositionCallback(CursorPositionFunctionPointer* fun)
		{
			CurrentCursorPositionFunctionPointer = fun;
			CurrentCursorPositionFunctionPointerRaw = *CursorPositionFunctionPointerWrapper;
			glfwSetCursorPosCallback(m_window, CurrentCursorPositionFunctionPointerRaw);
		}

		void Window::SetCursorPositionCallback(CursorPositionFunctionPointerRaw* fun)
		{
			CurrentCursorPositionFunctionPointerRaw = fun;
			glfwSetCursorPosCallback(m_window, CurrentCursorPositionFunctionPointerRaw);
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
			Event event;
			event.type = Event::Type::CursorPosition;
			event.cursor_enter.entered = CursorEnter;
			window.EventQueue.push(event);
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
			glfwSetCursorEnterCallback(m_window, CurrentCursorEnterFunctionPointerRaw);
		}

		void Window::SetCursorEnterCallback(CursorEnterFunctionPointer* fun)
		{
			CurrentCursorEnterFunctionPointer = fun;
			CurrentCursorEnterFunctionPointerRaw = *CursorEnterFunctionPointerWrapper;
			glfwSetCursorEnterCallback(m_window, CurrentCursorEnterFunctionPointerRaw);
		}

		void Window::SetCursorEnterCallback(CursorEnterFunctionPointerRaw* fun)
		{
			CurrentCursorEnterFunctionPointerRaw = fun;
			glfwSetCursorEnterCallback(m_window, CurrentCursorEnterFunctionPointerRaw);
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
			Event event;
			event.type = Event::Type::Scroll;
			event.scroll.offset = pos;
			window.EventQueue.push(event);
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
			glfwSetScrollCallback(m_window, CurrentScrollFunctionPointerRaw);
		}

		void Window::SetScrollCallback(ScrollFunctionPointer* fun)
		{
			CurrentScrollFunctionPointer = fun;
			CurrentScrollFunctionPointerRaw = *ScrollFunctionPointerWrapper;
			glfwSetScrollCallback(m_window, CurrentScrollFunctionPointerRaw);
		}

		void Window::SetScrollCallback(ScrollFunctionPointerRaw* fun)
		{
			CurrentScrollFunctionPointerRaw = fun;
			glfwSetScrollCallback(m_window, CurrentScrollFunctionPointerRaw);
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
			Event event;
			event.type = Event::Type::Key;
			event.key.key = key;
			event.key.scancode = scancode;
			event.key.action = action;
			event.key.modifier = modifier;
			window.EventQueue.push(event);
		};

		Window::KeyFunction Window::GetDefaultKeyCallback()
		{
			return DefaultKeyFunction;
		}

		void Window::SetKeyCallback(Window::KeyFunction fun)
		{
			CurrentKeyFunction = fun;
			CurrentKeyFunctionPointer = *LambdaKeyFunctionWrapper;
			CurrentKeyFunctionPointerRaw = *KeyFunctionPointerWrapper;
			glfwSetKeyCallback(m_window, CurrentKeyFunctionPointerRaw);
		}

		void Window::SetKeyCallback(Window::KeyFunctionPointer* fun)
		{
			CurrentKeyFunctionPointer = fun;
			CurrentKeyFunctionPointerRaw = *KeyFunctionPointerWrapper;
			glfwSetKeyCallback(m_window, CurrentKeyFunctionPointerRaw);
		}

		void Window::SetKeyCallback(Window::KeyFunctionPointerRaw* fun)
		{
			CurrentKeyFunctionPointerRaw = fun;
			glfwSetKeyCallback(m_window, CurrentKeyFunctionPointerRaw);
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
			Event event;
			event.type = Event::Type::Char;
			event.text.codepoint = codepoint;
			window.EventQueue.push(event);
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
			glfwSetCharCallback(m_window, CurrentCharFunctionPointerRaw);
		}

		void Window::SetCharCallback(CharFunctionPointer* fun)
		{
			CurrentCharFunctionPointer = fun;
			CurrentCharFunctionPointerRaw = *CharFunctionPointerWrapper;
			glfwSetCharCallback(m_window, CurrentCharFunctionPointerRaw);
		}

		void Window::SetCharCallback(CharFunctionPointerRaw* fun)
		{
			CurrentCharFunctionPointerRaw = fun;
			glfwSetCharCallback(m_window, CurrentCharFunctionPointerRaw);
		}
}
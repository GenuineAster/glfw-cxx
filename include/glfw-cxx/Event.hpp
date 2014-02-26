#pragma once
#include <glfw-cxx/Vector2.hpp>
#include <glfw-cxx/Input.hpp>

namespace glfw
{
	using CursorPos = Vector2<double>;
	using ScrollOffset = Vector2<double>;
	using WindowSize = Vector2<int>;
	using WindowPos = Vector2<int>;
	using FramebufferSize = Vector2<int>;

	class Event
	{
	public:
		enum class Type
		{
			WindowPosition,
			WindowSize,
			WindowClose,
			WindowRefresh,
			WindowFocus,
			WindowIconify,
			FramebufferSize,
			MouseButton,
			CursorPosition,
			CursorEnter,
			Scroll,
			Key,
			Char
		};

		Type type;

		struct WindowPositionEvent
		{
			WindowPos position;
		};

		struct WindowSizeEvent
		{
			WindowSize size;
		};

		struct WindowFocusEvent
		{
			int focused;
		};

		struct WindowIconifyEvent
		{
			int iconified;
		};

		struct FramebufferSizeEvent
		{
			FramebufferSize size;
		};

		struct MouseButtonEvent
		{
			MouseButton button;
			KeyAction action;
			Modifier modifier;
		};

		struct CursorPositionEvent
		{
			CursorPos position;
		};

		struct CursorEnterEvent
		{
			int entered;
		};

		struct ScrollEvent
		{
			ScrollOffset offset;
		};

		struct KeyEvent
		{
			Key key;
			int scancode;
			KeyAction action;
			Modifier modifier;
		};

		struct CharEvent
		{
			unsigned int codepoint;
		};

		union
		{
			WindowPositionEvent window_position;
			WindowSizeEvent window_size;
			WindowFocusEvent window_focus;
			WindowIconifyEvent window_iconify;
			FramebufferSizeEvent fb_size;
			MouseButtonEvent mouse_button;
			CursorPositionEvent cursor_position;
			CursorEnterEvent cursor_enter;
			ScrollEvent scroll;
			KeyEvent key;
			CharEvent text;
		};

		Event() {}
	};
} 
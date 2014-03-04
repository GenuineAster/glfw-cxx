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


	/*! \brief Defines a glfw-cxx event and its paramaters
	 */
	class Event
	{
	public:

		/*! \brief Possible types of events
		 */
		enum class Type
		{
			WindowPosition, ///< Window moved (Event::WindowPositionEvent)
			WindowSize, ///< Window resized (Event::WindowSizeEvent)
			WindowClose, ///< Window closed (None)
			WindowRefresh, ///< Window refreshed (None)
			WindowFocus, ///< Window focus changed (Event::WindowFocusEvent)
			WindowIconify, ///< Window minimized/opened (Event::WindowIconifyEvent)
			FramebufferSize, ///< Framebuffer resized (Event::FramebufferSizeEvent)
			MouseButton, ///< Mousebutton pressed/released (Event::MouseButtonEvent)
			CursorPosition, ///< Cursor moved (Event::CursorPositionEvent)
			CursorEnter, ///< Cursor left/entered the window (Event::CursorEnterEvent)
			Scroll, ///< Mouse scrolled (Event::ScrollEvent)
			Key, ///< Key pressed/released/held (Event::KeyEvent)
			Char ///< Text entered (Event::CharEvent)
		};

		Type type;


		/*! \brief Window Position event parameters (Window moved)
		 */
		struct WindowPositionEvent
		{
			WindowPos position;
		};

		/*! \brief Window Size event parameters (Window Resized)
		 */
		struct WindowSizeEvent
		{
			WindowSize size;
		};

		/*! \brief Window Focus event parameters (Window in/out of focus)
		 */
		struct WindowFocusEvent
		{
			int focused;
		};

		/*! \brief Window Iconify event parameters (Window Minimized)
		 */
		struct WindowIconifyEvent
		{
			int iconified;
		};

		/*! \brief Framebuffer Size event parameters (Framebuffer resized)
		 */
		struct FramebufferSizeEvent
		{
			FramebufferSize size;
		};

		/*! \brief Mouse Button event parameters (Mouse Button clicked/released)
		 */
		struct MouseButtonEvent
		{
			MouseButton button;
			ButtonAction action;
			Modifier modifier;
		};

		/*! \brief Cursor Position event parameters (Mouse moved)
		 */
		struct CursorPositionEvent
		{
			CursorPos position;
		};

		/*! \brief Cursor Enter event parameters (Cursor left/entered window)
		 */
		struct CursorEnterEvent
		{
			int entered;
		};

		/*! \brief Scroll event parameters (Mouse scrolled)
		 */
		struct ScrollEvent
		{
			ScrollOffset offset;
		};

		/*! \brief Key event parameters (Key pressed/released/held)
		 */
		struct KeyEvent
		{
			Key key;
			int scancode;
			KeyAction action;
			Modifier modifier;
		};

		/*! \brief Char event parameters (Text entered)
		 */
		struct CharEvent
		{
			unsigned int codepoint;
		};

		union
		{
			WindowPositionEvent window_position; ///< WindowPosition event parameters (Event::WindowPositionEvent)
			WindowSizeEvent window_size; ///< WindowSize event parameters (Event::WindowSizeEvent)
			WindowFocusEvent window_focus; ///< WindowFocus event parameters (Event::WindowFocusEvent)
			WindowIconifyEvent window_iconify; ///< WindowIconify event parameters (Event::WindowIconifyEvent)
			FramebufferSizeEvent fb_size; ///< Framebuffer Size event parameters (Event::FramebufferSizeEvent)
			MouseButtonEvent mouse_button; ///< MouseButton event parameters (Event::MouseButtonEvent)
			CursorPositionEvent cursor_position; ///< CursorPosition event parameters (Event::CursorPositionEvent)
			CursorEnterEvent cursor_enter; ///< CursorEnter event parameters (Event::CursorEnterEvent)
			ScrollEvent scroll; ///< Scroll event parameters (Event::ScollEvent)
			KeyEvent key; ///< Key event parameters (Event::KeyEvent)
			CharEvent text; ///< Char event parameters (Event::CharEvent)
		};

		Event() {}
	};
}

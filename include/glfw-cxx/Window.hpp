#pragma once
#include <GLFW/glfw3.h>
#include <glfw-cxx/Monitor.hpp>
#include <string>
#include <vector>
#include <functional>
#include <glfw-cxx/Event.hpp>
#include <queue>


namespace glfw
{

	/*!\brief A class used for window handling.
	 */
	class Window
	{

	private:
		GLFWwindow* m_window;
		bool m_destroy;

		void AddToEventQueue(Event &event);
		void PrepareCallbacks();

	public:

		/*!\brief Gets the input mode of the window.
		 * \param[in] mode the mode
		 * \returns the value of the specified input mode
		 */
		int GetInputMode(int mode) const;

		/*!\brief Sets the input mode of the window.
		 * \param[in] mode the input mode to set
		 * \param[in] value the new value of the mode
		 */
		void SetInputMode(int mode, int value);

		/*!\brief Gets the status of the specified key
		 * \param[in] key The key whose status to get
		 * \returns the status of the specified key
		 */
		int GetKey(Key key) const;

		/*!\brief Gets the status of the specified mouse button
		 * \param[in] button The moust button whose status to get
		 * \returns the status of the specified mouse button
		 */
		int GetMouseButton(int button) const;

		/*!\brief Gets the position of the cursor
		 * \returns the cursor's position
		 */
		CursorPos GetCursorPos() const;

		/*!\brief Sets the cursor's position
		 * \param[in] pos the cursor's new position
		 */
		void SetCursorPos(CursorPos pos);

		/*!\brief Sets the cursor's position
		 * \param[in] x The cursor's new x position
		 * \param[in] y The cursor's new y position
		 */
		void SetCursorPos(double x, double y);

		/*!\brief Gets whether the specified joystick is present
		 * \param[in] joy The joystick to check
		 * \returns whether the specified joystick is present
		 */
		static int JoystickPresent(Joystick joy);

		/*!\brief Gets a list of the specified joystick's axes and their values
		 * \param[in] joy The joystick whose axes to get
		 * \returns a vector of axes' values
		 */
		static std::vector<float> GetJoystickAxes(Joystick joy);

		/*!\brief Gets a list of the specified joystick's buttons and their values
		 * \param[in] joy the joystick whose buttons to get
		 * \returns a vector of buttons' values
		 */
		static const std::vector<uint8_t> GetJoystickButtons(Joystick joy);

		/*!\brief Gets the name of the specified joystick
		 * \param[in] joy the joystick whose name to get
		 * \returns the name of the specified joystick
		 */
		static std::string GetJoystickName(Joystick joy);

		/*! \brief Swaps the front and back buffers of the window.
		 *
		 *  This function swaps the front and back buffers of the window.  If
		 *  the swap interval is greater than zero, the GPU driver waits the specified
		 *  number of screen updates before swapping the buffers.
		 *
		 *  \remarks This function may be called from secondary threads.
		 *
		 *  \sa Window::SwapInterval
		 *
		 */
		void SwapBuffers();

		/*! \brief Makes the context of the window current for the calling
		 *  thread.
		 *
		 *  This function makes the context of the window current on the
		 *  calling thread.  A context can only be made current on a single thread at
		 *  a time and each thread can have only a single current context at a time.
		 *
		 *  \remarks This function may be called from secondary threads.
		 *
		 *  \sa Window::GetCurrentContext
		 */
		void MakeContextCurrent();

		/*! \brief Sets the clipboard to the specified string.
		 *
		 *  This function sets the system clipboard to the specified string.  
		 *  
		 *  \param[in] clipboard The new clipboard string.
		 *
		 *  \note This function may only be called from the main thread.
		 *
		 *  \sa Window::GetClipboard
		 */
		void SetClipboard(std::string clipboard);

		/*! \brief Retrieves the contents of the clipboard as a string.
		 *
		 *  This function returns the contents of the system clipboard, if it contains
		 *  or is convertible to a string.
		 *
		 *  \note This function may only be called from the main thread.
		 *
		 *  \sa Window::SetClipboard
		 */
		std::string GetClipboard() const;

		/*! \brief Resets all window hints to their default values.
		 *
		 *  This function resets all window hints to their
		 *  [default values](\ref window_hints_values).
		 *
		 *  \note This function may only be called from the main thread.
		 *
		 *  \sa Window::Hint
		 */		
		static void DefaultHints();

		/*! \brief Sets the specified window hint to the desired value.
		 *
		 *  This function sets hints for the next call to \ref Window::Create.  The
		 *  hints, once set, retain their values until changed by a call to \ref
		 *  Window::Hint or \ref Window::DefaultHints.
		 *
		 *  \param[in] target The [window hint](\ref window_hints) to set.
		 *  \param[in] hint The new value of the window hint.
		 *
		 *  \note This function may only be called from the main thread.
		 *
		 *  \sa Window::DefaultHints
		 */
		static void Hint(int target, int hint);

		/*! \brief Creates a window and its associated context.
		 *
		 *  This function creates a window and its associated context.  Most of the
		 *  options controlling how the window and its context should be created are
		 *  specified through \ref Window::Hint.
		 *
		 *  Successful creation does not change which context is current.  Before you
		 *  can use the newly created context, you need to make it current using \ref
		 *  Window::MakeContextCurrent.
		 *
		 *  Note that the created window and context may differ from what you requested,
		 *  as not all parameters and hints are
		 *  [hard constraints](\ref window_hints_hard).  This includes the size of the
		 *  window, especially for full screen windows.  To retrieve the actual
		 *  attributes of the created window and context, use queries like \ref
		 *  Window::GetAttrib and \ref Window::GetSize.
		 *
		 *  To create a full screen window, you need to specify the monitor to use.  If
		 *  no monitor is specified, windowed mode will be used.  Unless you have a way
		 *  for the user to choose a specific monitor, it is recommended that you pick
		 *  the primary monitor.  For more information on how to retrieve monitors, see
		 *  \ref monitor_monitors.
		 *
		 *  To create the window at a specific position, make it initially invisible
		 *  using the `GLFW_VISIBLE` window hint, set its position and then show it.
		 *
		 *  If a full screen window is active, the screensaver is prohibited from
		 *  starting.
		 *
		 *  \param[in] width The desired width, in screen coordinates, of the window.
		 *  This must be greater than zero.
		 *  \param[in] height The desired height, in screen coordinates, of the window.
		 *  This must be greater than zero.
		 *  \param[in] title The initial, UTF-8 encoded window title.
		 *  \param[in] monitor The monitor to use for full screen mode
		 *  \param[in] share The window whose context to share resources with
		 *
		 *  \remarks **Windows:** Window creation will fail if the Microsoft GDI
		 *  software OpenGL implementation is the only one available.
		 *
		 *  \remarks **Windows:** If the executable has an icon resource named
		 *  `GLFW_ICON,` it will be set as the icon for the window.  If no such icon is
		 *  present, the `IDI_WINLOGO` icon will be used instead.
		 *
		 *  \remarks **OS X:** The GLFW window has no icon, as it is not a document
		 *  window, but the dock icon will be the same as the application bundle's icon.
		 *  Also, the first time a window is opened the menu bar is populated with
		 *  common commands like Hide, Quit and About.  The (minimal) about dialog uses
		 *  information from the application's bundle.  For more information on bundles,
		 *  see the Bundle Programming Guide provided by Apple.
		 *
		 *  \remarks **X11:** There is no mechanism for setting the window icon yet.
		 *
		 *  \remarks The swap interval is not set during window creation, but is left at
		 *  the default value for that platform.  For more information, see \ref
		 *  Window::SwapInterval.
		 *
		 *  \note This function may only be called from the main thread.
		 */
		void Create(int width, int height, const std::string &title, const Monitor &monitor, const Window &share);

		/*! \brief Creates a window and its associated context.
		 *
		 *  This function creates a window and its associated context.  Most of the
		 *  options controlling how the window and its context should be created are
		 *  specified through \ref Window::Hint.
		 *
		 *  Successful creation does not change which context is current.  Before you
		 *  can use the newly created context, you need to make it current using \ref
		 *  Window::MakeContextCurrent.
		 *
		 *  Note that the created window and context may differ from what you requested,
		 *  as not all parameters and hints are
		 *  [hard constraints](\ref window_hints_hard).  This includes the size of the
		 *  window, especially for full screen windows.  To retrieve the actual
		 *  attributes of the created window and context, use queries like \ref
		 *  Window::GetAttrib and \ref Window::GetSize.
		 *
		 *  To create a full screen window, you need to specify the monitor to use.  If
		 *  no monitor is specified, windowed mode will be used.  Unless you have a way
		 *  for the user to choose a specific monitor, it is recommended that you pick
		 *  the primary monitor.  For more information on how to retrieve monitors, see
		 *  \ref monitor_monitors.
		 *
		 *  To create the window at a specific position, make it initially invisible
		 *  using the `GLFW_VISIBLE` window hint, set its position and then show it.
		 *
		 *  If a full screen window is active, the screensaver is prohibited from
		 *  starting.
		 *
		 *  \param[in] width The desired width, in screen coordinates, of the window.
		 *  This must be greater than zero.
		 *  \param[in] height The desired height, in screen coordinates, of the window.
		 *  This must be greater than zero.
		 *  \param[in] title The initial, UTF-8 encoded window title.
		 *  \param[in] monitor The monitor to use for full screen mode
		 *
		 *  \remarks **Windows:** Window creation will fail if the Microsoft GDI
		 *  software OpenGL implementation is the only one available.
		 *
		 *  \remarks **Windows:** If the executable has an icon resource named
		 *  `GLFW_ICON,` it will be set as the icon for the window.  If no such icon is
		 *  present, the `IDI_WINLOGO` icon will be used instead.
		 *
		 *  \remarks **OS X:** The GLFW window has no icon, as it is not a document
		 *  window, but the dock icon will be the same as the application bundle's icon.
		 *  Also, the first time a window is opened the menu bar is populated with
		 *  common commands like Hide, Quit and About.  The (minimal) about dialog uses
		 *  information from the application's bundle.  For more information on bundles,
		 *  see the Bundle Programming Guide provided by Apple.
		 *
		 *  \remarks **X11:** There is no mechanism for setting the window icon yet.
		 *
		 *  \remarks The swap interval is not set during window creation, but is left at
		 *  the default value for that platform.  For more information, see \ref
		 *  Window::SwapInterval.
		 *
		 *  \note This function may only be called from the main thread.
		 */
		void Create(int width, int height, const std::string &title, const Monitor &monitor);

		/*! \brief Creates a window and its associated context.
		 *
		 *  This function creates a window and its associated context.  Most of the
		 *  options controlling how the window and its context should be created are
		 *  specified through \ref Window::Hint.
		 *
		 *  Successful creation does not change which context is current.  Before you
		 *  can use the newly created context, you need to make it current using \ref
		 *  Window::MakeContextCurrent.
		 *
		 *  Note that the created window and context may differ from what you requested,
		 *  as not all parameters and hints are
		 *  [hard constraints](\ref window_hints_hard).  This includes the size of the
		 *  window, especially for full screen windows.  To retrieve the actual
		 *  attributes of the created window and context, use queries like \ref
		 *  Window::GetAttrib and \ref Window::GetSize.
		 *
		 *  To create a full screen window, you need to specify the monitor to use.  If
		 *  no monitor is specified, windowed mode will be used.  Unless you have a way
		 *  for the user to choose a specific monitor, it is recommended that you pick
		 *  the primary monitor.  For more information on how to retrieve monitors, see
		 *  \ref monitor_monitors.
		 *
		 *  To create the window at a specific position, make it initially invisible
		 *  using the `GLFW_VISIBLE` window hint, set its position and then show it.
		 *
		 *  If a full screen window is active, the screensaver is prohibited from
		 *  starting.
		 *
		 *  \param[in] width The desired width, in screen coordinates, of the window.
		 *  This must be greater than zero.
		 *  \param[in] height The desired height, in screen coordinates, of the window.
		 *  This must be greater than zero.
		 *  \param[in] title The initial, UTF-8 encoded window title.
		 *  \param[in] share The window whose context to share resources with
		 *
		 *  \remarks **Windows:** Window creation will fail if the Microsoft GDI
		 *  software OpenGL implementation is the only one available.
		 *
		 *  \remarks **Windows:** If the executable has an icon resource named
		 *  `GLFW_ICON,` it will be set as the icon for the window.  If no such icon is
		 *  present, the `IDI_WINLOGO` icon will be used instead.
		 *
		 *  \remarks **OS X:** The GLFW window has no icon, as it is not a document
		 *  window, but the dock icon will be the same as the application bundle's icon.
		 *  Also, the first time a window is opened the menu bar is populated with
		 *  common commands like Hide, Quit and About.  The (minimal) about dialog uses
		 *  information from the application's bundle.  For more information on bundles,
		 *  see the Bundle Programming Guide provided by Apple.
		 *
		 *  \remarks **X11:** There is no mechanism for setting the window icon yet.
		 *
		 *  \remarks The swap interval is not set during window creation, but is left at
		 *  the default value for that platform.  For more information, see \ref
		 *  Window::SwapInterval.
		 *
		 *  \note This function may only be called from the main thread.
		 */
		void Create(int width, int height, const std::string &title, const Window &share);

		/*! \brief Creates a window and its associated context.
		 *
		 *  This function creates a window and its associated context.  Most of the
		 *  options controlling how the window and its context should be created are
		 *  specified through \ref Window::Hint.
		 *
		 *  Successful creation does not change which context is current.  Before you
		 *  can use the newly created context, you need to make it current using \ref
		 *  Window::MakeContextCurrent.
		 *
		 *  Note that the created window and context may differ from what you requested,
		 *  as not all parameters and hints are
		 *  [hard constraints](\ref window_hints_hard).  This includes the size of the
		 *  window, especially for full screen windows.  To retrieve the actual
		 *  attributes of the created window and context, use queries like \ref
		 *  Window::GetAttrib and \ref Window::GetSize.
		 *
		 *  To create a full screen window, you need to specify the monitor to use.  If
		 *  no monitor is specified, windowed mode will be used.  Unless you have a way
		 *  for the user to choose a specific monitor, it is recommended that you pick
		 *  the primary monitor.  For more information on how to retrieve monitors, see
		 *  \ref monitor_monitors.
		 *
		 *  To create the window at a specific position, make it initially invisible
		 *  using the `GLFW_VISIBLE` window hint, set its position and then show it.
		 *
		 *  If a full screen window is active, the screensaver is prohibited from
		 *  starting.
		 *
		 *  \param[in] width The desired width, in screen coordinates, of the window.
		 *  This must be greater than zero.
		 *  \param[in] height The desired height, in screen coordinates, of the window.
		 *  This must be greater than zero.
		 *  \param[in] title The initial, UTF-8 encoded window title.
		 *
		 *  \remarks **Windows:** Window creation will fail if the Microsoft GDI
		 *  software OpenGL implementation is the only one available.
		 *
		 *  \remarks **Windows:** If the executable has an icon resource named
		 *  `GLFW_ICON,` it will be set as the icon for the window.  If no such icon is
		 *  present, the `IDI_WINLOGO` icon will be used instead.
		 *
		 *  \remarks **OS X:** The GLFW window has no icon, as it is not a document
		 *  window, but the dock icon will be the same as the application bundle's icon.
		 *  Also, the first time a window is opened the menu bar is populated with
		 *  common commands like Hide, Quit and About.  The (minimal) about dialog uses
		 *  information from the application's bundle.  For more information on bundles,
		 *  see the Bundle Programming Guide provided by Apple.
		 *
		 *  \remarks **X11:** There is no mechanism for setting the window icon yet.
		 *
		 *  \remarks The swap interval is not set during window creation, but is left at
		 *  the default value for that platform.  For more information, see \ref
		 *  Window::SwapInterval.
		 *
		 *  \note This function may only be called from the main thread.
		 */
		void Create(int width, int height, const std::string &title);

		/*! \brief Checks the close flag of the window.
		 *
		 *  This function returns the value of the close flag of the window.
		 *
		 *  \return The value of the close flag.
		 *
		 *  \remarks This function may be called from secondary threads.
		 */
		int ShouldClose() const;

		/*! \brief Sets the close flag of the window.
		 *
		 *  This function sets the value of the close flag of the window.
		 *  This can be used to override the user's attempt to close the window, or
		 *  to signal that it should be closed.
		 *
		 *  \param[in] value The new value.
		 *
		 *  \remarks This function may be called from secondary threads.
		 */
		void SetShouldClose(int value);

		/*! \brief Sets the title of the window.
		 *
		 *  This function sets the window title of the window.
		 *
		 *  \param[in] title The new window title.
		 *
		 *  \note This function may only be called from the main thread.
		 */
		void SetTitle(std::string title);

		/*!\brief Gets the window's position.
		 * \returns the Window's position.
		 */
		WindowPos GetPos() const;

		/*!\brief Sets the window's position
		 * \param[in] pos The window's new position.
		 */
		void SetPos(WindowPos pos);

		/*!\brief Sets the window's position
		 * \param[in] x The window's new x coordinate
		 * \param[in] y The window's new y coordinate
		 */
		void SetPos(int x, int y);

		/*!\brief Gets the window's size
		 * \returns the window's size
		 */
		WindowSize GetSize() const;

		/*!\brief Sets the window's size
		 * \param[in] size the window's new size
		 */
		void SetSize(WindowSize size);

		/*!\brief Sets the window's size
		 * \param[in] x the window's new width
		 * \param[in] y the window's new height
		 */
		void SetSize(int x, int y);

		/*!\brief Gets the framebuffer's size
		 * \returns the framebuffer's size
		 */
		FramebufferSize GetFramebufferSize() const;

		/*!\brief Iconifies the window.
		 */
		void Iconify();

		/*!\brief Restores the window.
		 */
		void Restore();

		/*!\brief Shows the window.
		 */
		void Show();

		/*!\brief Hides the window.
		 */
		void Hide();

		/*!\brief Gets the monitor the window is currently on.
		 * \returns the monitor the window is currently on.
		 */
		Monitor GetMonitor() const;

		/*! \brief Returns an attribute of the window.
		 *
		 *  This function returns an attribute of the window.  There are many
		 *  attributes, some related to the window and others to its context.
		 *
		 *  \param[in] attrib The [window attribute](\ref window_attribs) whose value to
		 *  return.
		 *  \return The value of the attribute, or zero if an error occurred.
		 */
		int GetAttrib(int attrib) const;

		/*!\brief Sets the window's user pointer.
		 * \warning Do NOT use this function if you want to use glfw-cxx's event queue.
		 */
		void SetUserPointer(void *pointer);

		/*!\brief Gets the window's user pointer.
		 * \returns the user pointer
		 */
		void* GetUserPointer() const;

		/*!\brief Gets the list of events from the system, and feeds them to their callbacks
		 */
		static void PollEvents();

		/*!\brief Waits for the next event from the system, and feeds it to its callback.
		 */
		static void WaitEvents();

		/*!\brief Sets the event to the newest event in the event queue.
		 * \param[out] event the Event to set
		 * \returns whether the event queue is exhausted or not
		 */
		bool GetEvents(Event &event);

		/*!\brief Gets the C GLFW window pointer.
		 * \returns the C GLFW window pointer
		 */
		GLFWwindow* GetRawPointerData() const;

		operator GLFWwindow*();

		Window(int width, int height, const std::string &title, const Monitor &monitor, const Window &share);
		Window(int width, int height, const std::string &title, const Monitor &monitor);
		Window(int width, int height, const std::string &title, const Window &share);
		Window(int width, int height, const std::string &title);
		Window(GLFWwindow* window);
		Window();
		~Window();

	private:
		using PositionFunction = std::function<void(Window,WindowPos)>;
		using PositionFunctionPointer = void(Window,WindowPos);
		using PositionFunctionPointerRaw = void(GLFWwindow*, int, int);
		using SizeFunction = std::function<void(Window,WindowSize)>;
		using SizeFunctionPointer = void(Window,WindowSize);
		using SizeFunctionPointerRaw = void(GLFWwindow*, int, int);
		using CloseFunction = std::function<void(Window)>;
		using CloseFunctionPointer = void(Window);
		using CloseFunctionPointerRaw = void(GLFWwindow*);
		using RefreshFunction = std::function<void(Window)>;
		using RefreshFunctionPointer = void(Window);
		using RefreshFunctionPointerRaw = void(GLFWwindow*);
		using FocusFunction = std::function<void(Window,int)>;
		using FocusFunctionPointer = void(Window,int);
		using FocusFunctionPointerRaw = void(GLFWwindow*, int);
		using IconifyFunction = std::function<void(Window,int)>;
		using IconifyFunctionPointer = void(Window,int);
		using IconifyFunctionPointerRaw = void(GLFWwindow*, int);
		using FramebufferSizeFunction = std::function<void(Window,FramebufferSize)>;
		using FramebufferSizeFunctionPointer = void(Window,FramebufferSize);
		using FramebufferSizeFunctionPointerRaw = void(GLFWwindow*, int, int);
		using MouseButtonFunction = std::function<void(Window,MouseButton,KeyAction,Modifier)>;
		using MouseButtonFunctionPointer = void(Window,MouseButton,KeyAction,Modifier);
		using MouseButtonFunctionPointerRaw = void(GLFWwindow*, int, int, int);
		using CursorPositionFunction = std::function<void(Window,CursorPos)>;
		using CursorPositionFunctionPointer = void(Window,CursorPos);
		using CursorPositionFunctionPointerRaw = void(GLFWwindow*, double, double);
		using CursorEnterFunction = std::function<void(Window,int)>;
		using CursorEnterFunctionPointer = void(Window,int);
		using CursorEnterFunctionPointerRaw = void(GLFWwindow*, int);
		using ScrollFunction = std::function<void(Window,ScrollOffset)>;
		using ScrollFunctionPointer = void(Window,ScrollOffset);
		using ScrollFunctionPointerRaw = void(GLFWwindow*, double, double);
		using KeyFunction = std::function<void(Window,Key,int,KeyAction,Modifier)>;
		using KeyFunctionPointer = void(Window,Key,int,KeyAction,Modifier);
		using KeyFunctionPointerRaw = void(GLFWwindow*, int, int, int, int);
		using CharFunction = std::function<void(Window,unsigned int)>;
		using CharFunctionPointer = void(Window,unsigned int);
		using CharFunctionPointerRaw = void(GLFWwindow*, unsigned int);
		static void LambdaPositionFunctionWrapper(Window window, WindowPos pos);
		static void PositionFunctionPointerWrapper(GLFWwindow* window, int PosX, int PosY);
		static void LambdaSizeFunctionWrapper(Window window, WindowSize size);
		static void SizeFunctionPointerWrapper(GLFWwindow* window, int SizeX, int SizeY);
		static void LambdaCloseFunctionWrapper(Window window);
		static void CloseFunctionPointerWrapper(GLFWwindow* window);
		static void LambdaRefreshFunctionWrapper(Window window);
		static void RefreshFunctionPointerWrapper(GLFWwindow* window);
		static void LambdaFocusFunctionWrapper(Window window, int focus);
		static void FocusFunctionPointerWrapper(GLFWwindow* window, int focus);
		static void LambdaIconifyFunctionWrapper(Window window, int Iconify);
		static void IconifyFunctionPointerWrapper(GLFWwindow* window, int Iconify);
		static void LambdaFramebufferSizeFunctionWrapper(Window window, FramebufferSize Framebuffersize);
		static void FramebufferSizeFunctionPointerWrapper(GLFWwindow* window, int FramebufferSizeX, int FramebufferSizeY);
		static void LambdaMouseButtonFunctionWrapper(Window window, MouseButton button, KeyAction action, Modifier modifier);
		static void MouseButtonFunctionPointerWrapper(GLFWwindow* window, int button, int action, int modifier);
		static void LambdaCursorPositionFunctionWrapper(Window window, CursorPos pos);
		static void CursorPositionFunctionPointerWrapper(GLFWwindow* window, double PosX, double PosY);
		static void LambdaCursorEnterFunctionWrapper(Window window, int CursorEnter);
		static void CursorEnterFunctionPointerWrapper(GLFWwindow* window, int CursorEnter);
		static void LambdaScrollFunctionWrapper(Window window, ScrollOffset pos);
		static void ScrollFunctionPointerWrapper(GLFWwindow* window, double OffsetX, double OffsetY);
		static void LambdaKeyFunctionWrapper(Window window, Key key, int scancode, KeyAction action, Modifier modifier);
		static void KeyFunctionPointerWrapper(GLFWwindow* window, int key, int scancode, int action, int modifier);
		static void LambdaCharFunctionWrapper(Window window, unsigned int codepoint);
		static void CharFunctionPointerWrapper(GLFWwindow* window, unsigned int codepoint);
		static const PositionFunction DefaultPositionFunction;
		static const SizeFunction DefaultSizeFunction;
		static const CloseFunction DefaultCloseFunction;
		static const RefreshFunction DefaultRefreshFunction;
		static const FocusFunction DefaultFocusFunction;
		static const IconifyFunction DefaultIconifyFunction;
		static const FramebufferSizeFunction DefaultFramebufferSizeFunction;
		static const MouseButtonFunction DefaultMouseButtonFunction;
		static const CursorPositionFunction DefaultCursorPositionFunction;
		static const CursorEnterFunction DefaultCursorEnterFunction;
		static const ScrollFunction DefaultScrollFunction;
		static const KeyFunction DefaultKeyFunction;
		static const CharFunction DefaultCharFunction;
		PositionFunction CurrentPositionFunction = DefaultPositionFunction;
		PositionFunctionPointer* CurrentPositionFunctionPointer = *LambdaPositionFunctionWrapper;
		PositionFunctionPointerRaw* CurrentPositionFunctionPointerRaw = *PositionFunctionPointerWrapper;
		SizeFunction CurrentSizeFunction = DefaultSizeFunction;
		SizeFunctionPointer* CurrentSizeFunctionPointer = *LambdaSizeFunctionWrapper;
		SizeFunctionPointerRaw* CurrentSizeFunctionPointerRaw = *SizeFunctionPointerWrapper;
		CloseFunction CurrentCloseFunction = DefaultCloseFunction;
		CloseFunctionPointer* CurrentCloseFunctionPointer = *LambdaCloseFunctionWrapper;
		CloseFunctionPointerRaw* CurrentCloseFunctionPointerRaw = *CloseFunctionPointerWrapper;
		RefreshFunction CurrentRefreshFunction = DefaultRefreshFunction;
		RefreshFunctionPointer* CurrentRefreshFunctionPointer = *LambdaRefreshFunctionWrapper;
		RefreshFunctionPointerRaw* CurrentRefreshFunctionPointerRaw = *RefreshFunctionPointerWrapper;
		FocusFunction CurrentFocusFunction = DefaultFocusFunction;
		FocusFunctionPointer* CurrentFocusFunctionPointer = *LambdaFocusFunctionWrapper;
		FocusFunctionPointerRaw* CurrentFocusFunctionPointerRaw = *FocusFunctionPointerWrapper;
		IconifyFunction CurrentIconifyFunction = DefaultIconifyFunction;
		IconifyFunctionPointer* CurrentIconifyFunctionPointer = *LambdaIconifyFunctionWrapper;
		IconifyFunctionPointerRaw* CurrentIconifyFunctionPointerRaw = *IconifyFunctionPointerWrapper;
		FramebufferSizeFunction CurrentFramebufferSizeFunction = DefaultFramebufferSizeFunction;
		FramebufferSizeFunctionPointer* CurrentFramebufferSizeFunctionPointer = *LambdaFramebufferSizeFunctionWrapper;
		FramebufferSizeFunctionPointerRaw* CurrentFramebufferSizeFunctionPointerRaw = *FramebufferSizeFunctionPointerWrapper;
		MouseButtonFunction CurrentMouseButtonFunction = DefaultMouseButtonFunction;
		MouseButtonFunctionPointer* CurrentMouseButtonFunctionPointer = *LambdaMouseButtonFunctionWrapper;
		MouseButtonFunctionPointerRaw* CurrentMouseButtonFunctionPointerRaw = *MouseButtonFunctionPointerWrapper;
		CursorPositionFunction CurrentCursorPositionFunction = DefaultCursorPositionFunction;
		CursorPositionFunctionPointer* CurrentCursorPositionFunctionPointer = *LambdaCursorPositionFunctionWrapper;
		CursorPositionFunctionPointerRaw* CurrentCursorPositionFunctionPointerRaw = *CursorPositionFunctionPointerWrapper;
		CursorEnterFunction CurrentCursorEnterFunction = DefaultCursorEnterFunction;
		CursorEnterFunctionPointer* CurrentCursorEnterFunctionPointer = *LambdaCursorEnterFunctionWrapper;
		CursorEnterFunctionPointerRaw* CurrentCursorEnterFunctionPointerRaw = *CursorEnterFunctionPointerWrapper;
		ScrollFunction CurrentScrollFunction = DefaultScrollFunction;
		ScrollFunctionPointer* CurrentScrollFunctionPointer = *LambdaScrollFunctionWrapper;
		ScrollFunctionPointerRaw* CurrentScrollFunctionPointerRaw = *ScrollFunctionPointerWrapper;
		KeyFunction CurrentKeyFunction = DefaultKeyFunction;
		KeyFunctionPointer* CurrentKeyFunctionPointer = *LambdaKeyFunctionWrapper;
		KeyFunctionPointerRaw* CurrentKeyFunctionPointerRaw = *KeyFunctionPointerWrapper;
		CharFunction CurrentCharFunction = DefaultCharFunction;
		CharFunctionPointer* CurrentCharFunctionPointer = *LambdaCharFunctionWrapper;
		CharFunctionPointerRaw* CurrentCharFunctionPointerRaw = *CharFunctionPointerWrapper;

	public:

		/*!\brief Gets the default window position callback.
		 * \returns the default window position callback
		 */
		static PositionFunction GetDefaultPositionCallback();

		/*!\brief Sets the window position callback
		 * \param[in] fun The new window position callback
		 */
		void SetPositionCallback(PositionFunction fun);

		/*!\brief Sets the window position callback
		 * \param[in] fun The new window position callback
		 */
		void SetPositionCallback(PositionFunctionPointer* fun);

		/*!\brief Sets the window position callback
		 * \param[in] fun The new window position callback
		 */
		void SetPositionCallback(PositionFunctionPointerRaw* fun);
		
		/*!\brief Gets the default window size callback.
		 * \returns the default window size callback
		 */
		static SizeFunction GetDefaultSizeCallback();

		/*!\brief Sets the window size callback
		 * \param[in] fun The new window size callback
		 */
		void SetSizeCallback(SizeFunction fun);

		/*!\brief Sets the window size callback
		 * \param[in] fun The new window size callback
		 */
		void SetSizeCallback(SizeFunctionPointer* fun);

		/*!\brief Sets the window size callback
		 * \param[in] fun The new window size callback
		 */
		void SetSizeCallback(SizeFunctionPointerRaw* fun);
		
		/*!\brief Gets the default window close callback.
		 * \returns the default window close callback
		 */
		static CloseFunction GetDefaultCloseCallback();

		/*!\brief Sets the window close callback
		 * \param[in] fun The new window close callback
		 */
		void SetCloseCallback(CloseFunction fun);

		/*!\brief Sets the window close callback
		 * \param[in] fun The new window close callback
		 */
		void SetCloseCallback(CloseFunctionPointer* fun);

		/*!\brief Sets the window close callback
		 * \param[in] fun The new window close callback
		 */
		void SetCloseCallback(CloseFunctionPointerRaw* fun);

		/*!\brief Gets the default window refresh callback.
		 * \returns the default window refresh callback
		 */
		static RefreshFunction GetDefaultRefreshCallback();

		/*!\brief Sets the window refresh callback
		 * \param[in] fun The new window refresh callback
		 */
		void SetRefreshCallback(RefreshFunction fun);

		/*!\brief Sets the window refresh callback
		 * \param[in] fun The new window refresh callback
		 */
		void SetRefreshCallback(RefreshFunctionPointer* fun);

		/*!\brief Sets the window refresh callback
		 * \param[in] fun The new window refresh callback
		 */
		void SetRefreshCallback(RefreshFunctionPointerRaw* fun);
		
		/*!\brief Gets the default window focus callback.
		 * \returns the default window focus callback
		 */
		static FocusFunction GetDefaultFocusCallback();

		/*!\brief Sets the window focus callback
		 * \param[in] fun The new window focus callback
		 */
		void SetFocusCallback(FocusFunction fun);

		/*!\brief Sets the window focus callback
		 * \param[in] fun The new window focus callback
		 */
		void SetFocusCallback(FocusFunctionPointer* fun);

		/*!\brief Sets the window focus callback
		 * \param[in] fun The new window focus callback
		 */
		void SetFocusCallback(FocusFunctionPointerRaw* fun);
		
		/*!\brief Gets the default window iconify callback.
		 * \returns the default window iconify callback
		 */
		static IconifyFunction GetDefaultIconifyCallback();

		/*!\brief Sets the window iconify callback
		 * \param[in] fun The new window iconify callback
		 */
		void SetIconifyCallback(IconifyFunction fun);

		/*!\brief Sets the window iconify callback
		 * \param[in] fun The new window iconify callback
		 */
		void SetIconifyCallback(IconifyFunctionPointer* fun);

		/*!\brief Sets the window iconify callback
		 * \param[in] fun The new window iconify callback
		 */
		void SetIconifyCallback(IconifyFunctionPointerRaw* fun);

		/*!\brief Gets the default framebuffer size callback.
		 * \returns the default framebuffer size callback
		 */
		static FramebufferSizeFunction GetDefaultFramebufferSizeCallback();

		/*!\brief Sets the framebuffer size callback
		 * \param[in] fun The new framebuffer size callback
		 */
		void SetFramebufferSizeCallback(FramebufferSizeFunction fun);

		/*!\brief Sets the framebuffer size callback
		 * \param[in] fun The new framebuffer size callback
		 */
		void SetFramebufferSizeCallback(FramebufferSizeFunctionPointer* fun);

		/*!\brief Sets the framebuffer size callback
		 * \param[in] fun The new framebuffer size callback
		 */
		void SetFramebufferSizeCallback(FramebufferSizeFunctionPointerRaw* fun);

		/*!\brief Gets the default mouse button callback.
		 * \returns the default mouse button callback
		 */
		static MouseButtonFunction GetDefaultMouseButtonCallback();

		/*!\brief Sets the mousebutton callback
		 * \param[in] fun The new mousebutton callback
		 */
		void SetMouseButtonCallback(MouseButtonFunction fun);

		/*!\brief Sets the mousebutton callback
		 * \param[in] fun The new mousebutton callback
		 */
		void SetMouseButtonCallback(MouseButtonFunctionPointer* fun);

		/*!\brief Sets the mousebutton callback
		 * \param[in] fun The new mousebutton callback
		 */
		void SetMouseButtonCallback(MouseButtonFunctionPointerRaw* fun);
		
		/*!\brief Gets the default cursor position callback.
		 * \returns the default cursor position callback
		 */
		static CursorPositionFunction GetDefaultCursorPositionCallback();

		/*!\brief Sets the cursor position callback
		 * \param[in] fun The new cursor position callback
		 */
		void SetCursorPositionCallback(CursorPositionFunction fun);

		/*!\brief Sets the cursor position callback
		 * \param[in] fun The new cursor position callback
		 */
		void SetCursorPositionCallback(CursorPositionFunctionPointer* fun);

		/*!\brief Sets the cursor position callback
		 * \param[in] fun The new cursor position callback
		 */
		void SetCursorPositionCallback(CursorPositionFunctionPointerRaw* fun);
		
		/*!\brief Gets the default cursor enter callback.
		 * \returns the default cursor enter callback
		 */
		static CursorEnterFunction GetDefaultCursorEnterCallback();

		/*!\brief Sets the cursor enter callback
		 * \param[in] fun The new cursor enter callback
		 */
		void SetCursorEnterCallback(CursorEnterFunction fun);

		/*!\brief Sets the cursor enter callback
		 * \param[in] fun The new cursor enter callback
		 */
		void SetCursorEnterCallback(CursorEnterFunctionPointer* fun);

		/*!\brief Sets the cursor enter callback
		 * \param[in] fun The new cursor enter callback
		 */
		void SetCursorEnterCallback(CursorEnterFunctionPointerRaw* fun);		
		
		/*!\brief Gets the default scroll callback.
		 * \returns the default scroll callback
		 */
		static ScrollFunction GetDefaultScrollCallback();

		/*!\brief Sets the scroll callback
		 * \param[in] fun The new scroll callback
		 */
		void SetScrollCallback(ScrollFunction fun);

		/*!\brief Sets the scroll callback
		 * \param[in] fun The new scroll callback
		 */
		void SetScrollCallback(ScrollFunctionPointer* fun);

		/*!\brief Sets the scroll callback
		 * \param[in] fun The new scroll callback
		 */
		void SetScrollCallback(ScrollFunctionPointerRaw* fun);
		
		/*!\brief Gets the default key callback.
		 * \returns the default key callback
		 */
		static KeyFunction GetDefaultKeyCallback();

		/*!\brief Sets the key callback
		 * \param[in] fun The new key callback
		 */
		void SetKeyCallback(KeyFunction fun);

		/*!\brief Sets the key callback
		 * \param[in] fun The new key callback
		 */
		void SetKeyCallback(KeyFunctionPointer* fun);

		/*!\brief Sets the key callback
		 * \param[in] fun The new key callback
		 */
		void SetKeyCallback(KeyFunctionPointerRaw* fun);

		/*!\brief Gets the default char callback.
		 * \returns the default char callback
		 */
		static CharFunction GetDefaultCharCallback();

		/*!\brief Sets the char callback
		 * \param[in] fun The new char callback
		 */
		void SetCharCallback(CharFunction fun);

		/*!\brief Sets the char callback
		 * \param[in] fun The new char callback
		 */
		void SetCharCallback(CharFunctionPointer* fun);

		/*!\brief Sets the char callback
		 * \param[in] fun The new char callback
		 */
		void SetCharCallback(CharFunctionPointerRaw* fun);
	};
}

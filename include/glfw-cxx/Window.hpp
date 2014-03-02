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

	class Window
	{

	private:
		GLFWwindow* m_window;
		bool m_destroy;

		void AddToEventQueue(Event &event);
		void PrepareCallbacks();

	public:

		int GetInputMode(int mode) const;

		void SetInputMode(int mode, int value);

		int GetKey(Key key) const;

		int GetMouseButton(int button) const;

		CursorPos GetCursorPos() const;

		void SetCursorPos(CursorPos pos);
		void SetCursorPos(double x, double y);

		static int JoystickPresent(Joystick joy);

		static std::vector<float> GetJoystickAxes(Joystick joy);

		static const std::vector<uint8_t> GetJoystickButtons(Joystick joy);

		static std::string GetJoystickName(Joystick joy);

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

		WindowPos GetPos() const;
		void SetPos(WindowPos pos);
		void SetPos(int x, int y);

		WindowSize GetSize() const;
		void SetSize(WindowSize size);
		void SetSize(int x, int y);

		FramebufferSize GetFramebufferSize() const;

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

		bool GetEvents(Event &event);

		GLFWwindow* GetRawPointerData() const;

		operator GLFWwindow*();

		Window(int width, int height, const std::string &title, const Monitor &monitor, const Window &share);
		Window(int width, int height, const std::string &title, const Monitor &monitor);
		Window(int width, int height, const std::string &title, const Window &share);
		Window(int width, int height, const std::string &title);
		Window(GLFWwindow* window);
		Window();
		~Window();

	public:
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
		

	private:
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

		static PositionFunction GetDefaultPositionCallback();
		void SetPositionCallback(PositionFunction fun);
		void SetPositionCallback(PositionFunctionPointer* fun);
		void SetPositionCallback(PositionFunctionPointerRaw* fun);
		
		static SizeFunction GetDefaultSizeCallback();
		void SetSizeCallback(SizeFunction fun);
		void SetSizeCallback(SizeFunctionPointer* fun);
		void SetSizeCallback(SizeFunctionPointerRaw* fun);
		
		static CloseFunction GetDefaultCloseCallback();
		void SetCloseCallback(CloseFunction fun);
		void SetCloseCallback(CloseFunctionPointer* fun);
		void SetCloseCallback(CloseFunctionPointerRaw* fun);

		static RefreshFunction GetDefaultRefreshCallback();
		void SetRefreshCallback(RefreshFunction fun);
		void SetRefreshCallback(RefreshFunctionPointer* fun);
		void SetRefreshCallback(RefreshFunctionPointerRaw* fun);
		
		static FocusFunction GetDefaultFocusCallback();
		void SetFocusCallback(FocusFunction fun);
		void SetFocusCallback(FocusFunctionPointer* fun);
		void SetFocusCallback(FocusFunctionPointerRaw* fun);
		
		static IconifyFunction GetDefaultIconifyCallback();
		void SetIconifyCallback(IconifyFunction fun);
		void SetIconifyCallback(IconifyFunctionPointer* fun);
		void SetIconifyCallback(IconifyFunctionPointerRaw* fun);

		static FramebufferSizeFunction GetDefaultFramebufferSizeCallback();
		void SetFramebufferSizeCallback(FramebufferSizeFunction fun);
		void SetFramebufferSizeCallback(FramebufferSizeFunctionPointer* fun);
		void SetFramebufferSizeCallback(FramebufferSizeFunctionPointerRaw* fun);

		static MouseButtonFunction GetDefaultMouseButtonCallback();
		void SetMouseButtonCallback(MouseButtonFunction fun);
		void SetMouseButtonCallback(MouseButtonFunctionPointer* fun);
		void SetMouseButtonCallback(MouseButtonFunctionPointerRaw* fun);
		
		static CursorPositionFunction GetDefaultCursorPositionCallback();
		void SetCursorPositionCallback(CursorPositionFunction fun);
		void SetCursorPositionCallback(CursorPositionFunctionPointer* fun);
		void SetCursorPositionCallback(CursorPositionFunctionPointerRaw* fun);
		
		static CursorEnterFunction GetDefaultCursorEnterCallback();
		void SetCursorEnterCallback(CursorEnterFunction fun);
		void SetCursorEnterCallback(CursorEnterFunctionPointer* fun);
		void SetCursorEnterCallback(CursorEnterFunctionPointerRaw* fun);		
		
		static ScrollFunction GetDefaultScrollCallback();
		void SetScrollCallback(ScrollFunction fun);
		void SetScrollCallback(ScrollFunctionPointer* fun);
		void SetScrollCallback(ScrollFunctionPointerRaw* fun);
		
		static KeyFunction GetDefaultKeyCallback();
		void SetKeyCallback(KeyFunction fun);
		void SetKeyCallback(KeyFunctionPointer* fun);
		void SetKeyCallback(KeyFunctionPointerRaw* fun);

		static CharFunction GetDefaultCharCallback();
		void SetCharCallback(CharFunction fun);
		void SetCharCallback(CharFunctionPointer* fun);
		void SetCharCallback(CharFunctionPointerRaw* fun);
	};
}

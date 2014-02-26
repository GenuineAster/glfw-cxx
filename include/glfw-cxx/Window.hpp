#pragma once
#include <GLFW/glfw3.h>
#include <glfw-cxx/Monitor.hpp>
#include <string>
#include <vector>
#include <functional>
#include <glfw-cxx/Event.hpp>


namespace glfw
{

	class Window
	{
	public:
		using PositionFunction = std::function<void(Window,WindowPos)>;
		using PositionFunctionPointer = void(Window,WindowPos);
		using PositionFunctionPointerRaw = void(GLFWwindow*, int, int);
		static void LambdaPositionFunctionWrapper(Window window, WindowPos pos);
		static void PositionFunctionPointerWrapper(GLFWwindow* window, int PosX, int PosY);
		static const PositionFunction DefaultPositionFunction;
		PositionFunction CurrentPositionFunction = DefaultPositionFunction;
		PositionFunctionPointer* CurrentPositionFunctionPointer = *LambdaPositionFunctionWrapper;
		PositionFunctionPointerRaw* CurrentPositionFunctionPointerRaw = *PositionFunctionPointerWrapper;
		static PositionFunction GetDefaultPositionCallback();
		void SetPositionCallback(PositionFunction fun);
		void SetPositionCallback(PositionFunctionPointer* fun);
		void SetPositionCallback(PositionFunctionPointerRaw* fun);



		using SizeFunction = std::function<void(Window,WindowSize)>;
		using SizeFunctionPointer = void(Window,WindowSize);
		using SizeFunctionPointerRaw = void(GLFWwindow*, int, int);
		static void LambdaSizeFunctionWrapper(Window window, WindowSize size);
		static void SizeFunctionPointerWrapper(GLFWwindow* window, int SizeX, int SizeY);
		static const SizeFunction DefaultSizeFunction;
		SizeFunction CurrentSizeFunction = DefaultSizeFunction;
		SizeFunctionPointer* CurrentSizeFunctionPointer = *LambdaSizeFunctionWrapper;
		SizeFunctionPointerRaw* CurrentSizeFunctionPointerRaw = *SizeFunctionPointerWrapper;
		static SizeFunction GetDefaultSizeCallback();
		void SetSizeCallback(SizeFunction fun);
		void SetSizeCallback(SizeFunctionPointer* fun);
		void SetSizeCallback(SizeFunctionPointerRaw* fun);



		using CloseFunction = std::function<void(Window)>;
		using CloseFunctionPointer = void(Window);
		using CloseFunctionPointerRaw = void(GLFWwindow*);
		static void LambdaCloseFunctionWrapper(Window window);
		static void CloseFunctionPointerWrapper(GLFWwindow* window);
		static const CloseFunction DefaultCloseFunction;
		CloseFunction CurrentCloseFunction = DefaultCloseFunction;
		CloseFunctionPointer* CurrentCloseFunctionPointer = *LambdaCloseFunctionWrapper;
		CloseFunctionPointerRaw* CurrentCloseFunctionPointerRaw = *CloseFunctionPointerWrapper;
		static CloseFunction GetDefaultCloseCallback();
		void SetCloseCallback(CloseFunction fun);
		void SetCloseCallback(CloseFunctionPointer* fun);
		void SetCloseCallback(CloseFunctionPointerRaw* fun);



		using RefreshFunction = std::function<void(Window)>;
		using RefreshFunctionPointer = void(Window);
		using RefreshFunctionPointerRaw = void(GLFWwindow*);
		static void LambdaRefreshFunctionWrapper(Window window);
		static void RefreshFunctionPointerWrapper(GLFWwindow* window);
		static const RefreshFunction DefaultRefreshFunction;
		RefreshFunction CurrentRefreshFunction = DefaultRefreshFunction;
		RefreshFunctionPointer* CurrentRefreshFunctionPointer = *LambdaRefreshFunctionWrapper;
		RefreshFunctionPointerRaw* CurrentRefreshFunctionPointerRaw = *RefreshFunctionPointerWrapper;
		static RefreshFunction GetDefaultRefreshCallback();
		void SetRefreshCallback(RefreshFunction fun);
		void SetRefreshCallback(RefreshFunctionPointer* fun);
		void SetRefreshCallback(RefreshFunctionPointerRaw* fun);



		using FocusFunction = std::function<void(Window,int)>;
		using FocusFunctionPointer = void(Window,int);
		using FocusFunctionPointerRaw = void(GLFWwindow*, int);
		static void LambdaFocusFunctionWrapper(Window window, int focus);
		static void FocusFunctionPointerWrapper(GLFWwindow* window, int focus);
		static const FocusFunction DefaultFocusFunction;
		FocusFunction CurrentFocusFunction = DefaultFocusFunction;
		FocusFunctionPointer* CurrentFocusFunctionPointer = *LambdaFocusFunctionWrapper;
		FocusFunctionPointerRaw* CurrentFocusFunctionPointerRaw = *FocusFunctionPointerWrapper;
		static FocusFunction GetDefaultFocusCallback();
		void SetFocusCallback(FocusFunction fun);
		void SetFocusCallback(FocusFunctionPointer* fun);
		void SetFocusCallback(FocusFunctionPointerRaw* fun);



		using IconifyFunction = std::function<void(Window,int)>;
		using IconifyFunctionPointer = void(Window,int);
		using IconifyFunctionPointerRaw = void(GLFWwindow*, int);
		static void LambdaIconifyFunctionWrapper(Window window, int Iconify);
		static void IconifyFunctionPointerWrapper(GLFWwindow* window, int Iconify);
		static const IconifyFunction DefaultIconifyFunction;
		IconifyFunction CurrentIconifyFunction = DefaultIconifyFunction;
		IconifyFunctionPointer* CurrentIconifyFunctionPointer = *LambdaIconifyFunctionWrapper;
		IconifyFunctionPointerRaw* CurrentIconifyFunctionPointerRaw = *IconifyFunctionPointerWrapper;
		static IconifyFunction GetDefaultIconifyCallback();
		void SetIconifyCallback(IconifyFunction fun);
		void SetIconifyCallback(IconifyFunctionPointer* fun);
		void SetIconifyCallback(IconifyFunctionPointerRaw* fun);



		using FramebufferSizeFunction = std::function<void(Window,FramebufferSize)>;
		using FramebufferSizeFunctionPointer = void(Window,FramebufferSize);
		using FramebufferSizeFunctionPointerRaw = void(GLFWwindow*, int, int);
		static void LambdaFramebufferSizeFunctionWrapper(Window window, FramebufferSize Framebuffersize);
		static void FramebufferSizeFunctionPointerWrapper(GLFWwindow* window, int FramebufferSizeX, int FramebufferSizeY);
		static const FramebufferSizeFunction DefaultFramebufferSizeFunction;
		FramebufferSizeFunction CurrentFramebufferSizeFunction = DefaultFramebufferSizeFunction;
		FramebufferSizeFunctionPointer* CurrentFramebufferSizeFunctionPointer = *LambdaFramebufferSizeFunctionWrapper;
		FramebufferSizeFunctionPointerRaw* CurrentFramebufferSizeFunctionPointerRaw = *FramebufferSizeFunctionPointerWrapper;
		static FramebufferSizeFunction GetDefaultFramebufferSizeCallback();
		void SetFramebufferSizeCallback(FramebufferSizeFunction fun);
		void SetFramebufferSizeCallback(FramebufferSizeFunctionPointer* fun);
		void SetFramebufferSizeCallback(FramebufferSizeFunctionPointerRaw* fun);



		using MouseButtonFunction = std::function<void(Window,MouseButton,KeyAction,Modifier)>;
		using MouseButtonFunctionPointer = void(Window,MouseButton,KeyAction,Modifier);
		using MouseButtonFunctionPointerRaw = void(GLFWwindow*, int, int, int);
		static void LambdaMouseButtonFunctionWrapper(Window window, MouseButton button, KeyAction action, Modifier modifier);
		static void MouseButtonFunctionPointerWrapper(GLFWwindow* window, int button, int action, int modifier);
		static const MouseButtonFunction DefaultMouseButtonFunction;
		MouseButtonFunction CurrentMouseButtonFunction = DefaultMouseButtonFunction;
		MouseButtonFunctionPointer* CurrentMouseButtonFunctionPointer = *LambdaMouseButtonFunctionWrapper;
		MouseButtonFunctionPointerRaw* CurrentMouseButtonFunctionPointerRaw = *MouseButtonFunctionPointerWrapper;
		static MouseButtonFunction GetDefaultMouseButtonCallback();
		void SetMouseButtonCallback(MouseButtonFunction fun);
		void SetMouseButtonCallback(MouseButtonFunctionPointer* fun);
		void SetMouseButtonCallback(MouseButtonFunctionPointerRaw* fun);



		using CursorPositionFunction = std::function<void(Window,CursorPos)>;
		using CursorPositionFunctionPointer = void(Window,CursorPos);
		using CursorPositionFunctionPointerRaw = void(GLFWwindow*, double, double);
		static void LambdaCursorPositionFunctionWrapper(Window window, CursorPos pos);
		static void CursorPositionFunctionPointerWrapper(GLFWwindow* window, double PosX, double PosY);
		static const CursorPositionFunction DefaultCursorPositionFunction;
		CursorPositionFunction CurrentCursorPositionFunction = DefaultCursorPositionFunction;
		CursorPositionFunctionPointer* CurrentCursorPositionFunctionPointer = *LambdaCursorPositionFunctionWrapper;
		CursorPositionFunctionPointerRaw* CurrentCursorPositionFunctionPointerRaw = *CursorPositionFunctionPointerWrapper;
		static CursorPositionFunction GetDefaultCursorPositionCallback();
		void SetCursorPositionCallback(CursorPositionFunction fun);
		void SetCursorPositionCallback(CursorPositionFunctionPointer* fun);
		void SetCursorPositionCallback(CursorPositionFunctionPointerRaw* fun);



		using CursorEnterFunction = std::function<void(Window,int)>;
		using CursorEnterFunctionPointer = void(Window,int);
		using CursorEnterFunctionPointerRaw = void(GLFWwindow*, int);
		static void LambdaCursorEnterFunctionWrapper(Window window, int CursorEnter);
		static void CursorEnterFunctionPointerWrapper(GLFWwindow* window, int CursorEnter);
		static const CursorEnterFunction DefaultCursorEnterFunction;
		CursorEnterFunction CurrentCursorEnterFunction = DefaultCursorEnterFunction;
		CursorEnterFunctionPointer* CurrentCursorEnterFunctionPointer = *LambdaCursorEnterFunctionWrapper;
		CursorEnterFunctionPointerRaw* CurrentCursorEnterFunctionPointerRaw = *CursorEnterFunctionPointerWrapper;
		static CursorEnterFunction GetDefaultCursorEnterCallback();
		void SetCursorEnterCallback(CursorEnterFunction fun);
		void SetCursorEnterCallback(CursorEnterFunctionPointer* fun);
		void SetCursorEnterCallback(CursorEnterFunctionPointerRaw* fun);



		using ScrollFunction = std::function<void(Window,ScrollOffset)>;
		using ScrollFunctionPointer = void(Window,ScrollOffset);
		using ScrollFunctionPointerRaw = void(GLFWwindow*, double, double);
		static void LambdaScrollFunctionWrapper(Window window, ScrollOffset pos);
		static void ScrollFunctionPointerWrapper(GLFWwindow* window, double OffsetX, double OffsetY);
		static const ScrollFunction DefaultScrollFunction;
		ScrollFunction CurrentScrollFunction = DefaultScrollFunction;
		ScrollFunctionPointer* CurrentScrollFunctionPointer = *LambdaScrollFunctionWrapper;
		ScrollFunctionPointerRaw* CurrentScrollFunctionPointerRaw = *ScrollFunctionPointerWrapper;
		static ScrollFunction GetDefaultScrollCallback();
		void SetScrollCallback(ScrollFunction fun);
		void SetScrollCallback(ScrollFunctionPointer* fun);
		void SetScrollCallback(ScrollFunctionPointerRaw* fun);



		using KeyFunction = std::function<void(Window,Key,int,KeyAction,Modifier)>;
		using KeyFunctionPointer = void(Window,Key,int,KeyAction,Modifier);
		using KeyFunctionPointerRaw = void(GLFWwindow*, int, int, int, int);
		static void LambdaKeyFunctionWrapper(Window window, Key key, int scancode, KeyAction action, Modifier modifier);
		static void KeyFunctionPointerWrapper(GLFWwindow* window, int key, int scancode, int action, int modifier);
		static const KeyFunction DefaultKeyFunction;
		KeyFunction CurrentKeyFunction = DefaultKeyFunction;
		KeyFunctionPointer* CurrentKeyFunctionPointer = *LambdaKeyFunctionWrapper;
		KeyFunctionPointerRaw* CurrentKeyFunctionPointerRaw = *KeyFunctionPointerWrapper;
		static KeyFunction GetDefaultKeyCallback();
		void SetKeyCallback(KeyFunction fun);
		void SetKeyCallback(KeyFunctionPointer* fun);
		void SetKeyCallback(KeyFunctionPointerRaw* fun);



		using CharFunction = std::function<void(Window,unsigned int)>;
		using CharFunctionPointer = void(Window,unsigned int);
		using CharFunctionPointerRaw = void(GLFWwindow*, unsigned int);
		static void LambdaCharFunctionWrapper(Window window, unsigned int codepoint);
		static void CharFunctionPointerWrapper(GLFWwindow* window, unsigned int codepoint);
		static const CharFunction DefaultCharFunction;
		CharFunction CurrentCharFunction = DefaultCharFunction;
		CharFunctionPointer* CurrentCharFunctionPointer = *LambdaCharFunctionWrapper;
		CharFunctionPointerRaw* CurrentCharFunctionPointerRaw = *CharFunctionPointerWrapper;
		static CharFunction GetDefaultCharCallback();
		void SetCharCallback(CharFunction fun);
		void SetCharCallback(CharFunctionPointer* fun);
		void SetCharCallback(CharFunctionPointerRaw* fun);



	private:
		GLFWwindow* m_window;
		bool destroy;
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

		GLFWwindow* GetRawPointerData() const;

		operator GLFWwindow*();

		Window(int width, int height, const std::string &title, const Monitor &monitor, const Window &share);
		Window(int width, int height, const std::string &title, const Monitor &monitor);
		Window(int width, int height, const std::string &title, const Window &share);
		Window(int width, int height, const std::string &title);
		Window(GLFWwindow* window);
		Window();
		~Window();
	};
}

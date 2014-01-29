#include <GLFW/glfw3.h>

namespace glfw
{
	class Window
	{
	private:
		GLFWwindow* m_window;
	public:
		static void DefaultHints();
		static void Hint(int target, int hint);

		void Create(int width, int height, const std::string &title, const Monitor &monitor, const Window &share);
		void Create(int width, int height, const std::string &title, const Monitor &monitor);
		void Create(int width, int height, const std::string &title, const Window &share);
		void Create(int width, int height, const std::string &title);

		int ShouldClose();
		void SetShouldClose(int value);

		void SetWindowTitle(std::string title);

		int GetPosX();
		int GetPosY();
		void SetPos(int x, int y);

		int GetSizeX();
		int GetSizeY();
		void SetSize(int x, int y);

		int GetFramebufferSizeX();
		int GetFramebufferSizeY();

		void Iconify();
		void Restore();
		void Show();
		void Hide();

		const Monitor &getMonitor();

		int GetAttrib(int attrib);

		void SetUserPointer(void *pointer);
		void* GetUserPointer();

		void PollEvents();
		void WaitEvents();

		GLFWwindow* GetRawPointerData();

		Window(int width, int height, const std::string &title, const Monitor &monitor, const Window &share);
		Window(int width, int height, const std::string &title, const Monitor &monitor);
		Window(int width, int height, const std::string &title, const Window &share);
		Window(int width, int height, const std::string &title);
		~Window();
	};
}
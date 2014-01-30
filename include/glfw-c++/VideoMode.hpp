#include <GLFW/glfw3.h>
#include <glfw-c++/Vector2.hpp>

namespace glfw
{
	using Resolution = Vector2<int>;
	class VideoMode
	{
	private:
		GLFWvidmode m_vidmode;

	public:
		int GetWidth() const;
		void SetWidth(int width);
		int GetHeight() const;
		void SetHeight(int height);
		Resolution GetResolution() const;
		void SetResolution(Resolution res);

		int GetRedBits() const;
		void SetRedBits(int redbits);
		int GetGreenBits() const;
		void SetGreenBits(int greenbits);
		int GetBlueBits() const;
		void SetBlueBits(int bluebits);

		int GetRefreshRate() const;
		void SetRefreshRate(int refreshrate);

		GLFWvidmode* GetRawPointerData();

		VideoMode(int width, int height);
		VideoMode(int width, int height, int refreshrate);
		VideoMode(int width, int height, int redbits, int greenbits, int bluebits);
		VideoMode(int width, int height, int redbits, int greenbits, int bluebits, int refreshrate);
		VideoMode(GLFWvidmode vidmode);
		VideoMode();
	};
}
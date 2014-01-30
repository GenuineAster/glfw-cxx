#include <GLFW/glfw3.h>

namespace glfw
{
	class GammaRamp
	{
	private:
		GLFWgammaramp m_gammaramp;

	public:
		unsigned short* GetRed();
		void SetRed(unsigned short* red);
		unsigned short* GetGreen();
		void SetGreen(unsigned short* green);
		unsigned short* GetBlue();
		void SetBlue(unsigned short* blue);

		unsigned int GetSize();
		void SetSize(unsigned int size);

		GLFWgammaramp* GetRawDataPointer();

		GammaRamp(GLFWgammaramp gammaramp);
		GammaRamp();
	};
}
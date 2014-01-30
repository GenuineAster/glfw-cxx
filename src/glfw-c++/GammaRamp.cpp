#include <glfw-c++/GammaRamp.hpp>

namespace glfw
{
	unsigned short* GammaRamp::GetRed()
	{
		return m_gammaramp.red;
	}

	void GammaRamp::SetRed(unsigned short* red)
	{
		m_gammaramp.red = red;
	}

	unsigned short* GammaRamp::GetGreen()
	{
		return m_gammaramp.green;
	}

	void GammaRamp::SetGreen(unsigned short* green)
	{
		m_gammaramp.green = green;
	}

	unsigned short* GammaRamp::GetBlue()
	{
		return m_gammaramp.blue;
	}

	void GammaRamp::SetBlue(unsigned short* blue)
	{
		m_gammaramp.blue = blue;
	}

	unsigned int GammaRamp::GetSize()
	{
		return m_gammaramp.size;
	}

	void GammaRamp::SetSize(unsigned int size)
	{
		m_gammaramp.size = size;
	}

	GLFWgammaramp* GammaRamp::GetRawDataPointer()
	{
		return &m_gammaramp;
	}

	GammaRamp::GammaRamp(GLFWgammaramp gammaramp) : m_gammaramp(gammaramp) {}

	GammaRamp::GammaRamp() {}
}
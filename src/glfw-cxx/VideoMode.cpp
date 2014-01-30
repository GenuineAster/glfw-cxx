#include <glfw-cxx/VideoMode.hpp>

namespace glfw
{
	int VideoMode::GetWidth() const
	{
		return m_vidmode.width;
	}

	void VideoMode::SetWidth(int width)
	{
		m_vidmode.width = width;
	}

	int VideoMode::GetHeight() const
	{
		return m_vidmode.height;
	}

	void VideoMode::SetHeight(int height)
	{
		m_vidmode.height = height;
	}

	Resolution VideoMode::GetResolution() const
	{
		return Resolution(m_vidmode.width, m_vidmode.height);
	}

	void VideoMode::SetResolution(Resolution res)
	{
		m_vidmode.width = res.x;
		m_vidmode.height = res.y;
	}

	int VideoMode::GetRedBits() const
	{
		return m_vidmode.redBits;
	}

	void VideoMode::SetRedBits(int redbits)
	{
		m_vidmode.redBits = redbits;
	}

	int VideoMode::GetGreenBits() const
	{
		return m_vidmode.greenBits;
	}

	void VideoMode::SetGreenBits(int greenbits)
	{
		m_vidmode.greenBits = greenbits;
	}

	int VideoMode::GetBlueBits() const
	{
		return m_vidmode.blueBits;
	}

	void VideoMode::SetBlueBits(int bluebits)
	{
		m_vidmode.blueBits = bluebits;
	}

	int VideoMode::GetRefreshRate() const
	{
		return m_vidmode.refreshRate;
	}

	void VideoMode::SetRefreshRate(int refreshrate)
	{
		m_vidmode.refreshRate = refreshrate;
	}

	GLFWvidmode* VideoMode::GetRawPointerData()
	{
		return &m_vidmode;
	}

	VideoMode::VideoMode(int width, int height)
	{
		m_vidmode.width = width;
		m_vidmode.height = height;
		m_vidmode.refreshRate = 60;
		m_vidmode.redBits = 24;
		m_vidmode.greenBits = 24;
		m_vidmode.blueBits = 24;
	}

	VideoMode::VideoMode(int width, int height, int refreshrate)
	{
		m_vidmode.width = width;
		m_vidmode.height = height;
		m_vidmode.refreshRate = refreshrate;
		m_vidmode.redBits = 24;
		m_vidmode.greenBits = 24;
		m_vidmode.blueBits = 24;
	}

	VideoMode::VideoMode(int width, int height, int redbits, int greenbits, int bluebits)
	{
		m_vidmode.width = width;
		m_vidmode.height = height;
		m_vidmode.refreshRate = 60;
		m_vidmode.redBits = redbits;
		m_vidmode.greenBits = greenbits;
		m_vidmode.blueBits = bluebits;
	}

	VideoMode::VideoMode(int width, int height, int redbits, int greenbits, int bluebits, int refreshrate)
	{
		m_vidmode.width = width;
		m_vidmode.height = height;
		m_vidmode.refreshRate = refreshrate;
		m_vidmode.redBits = redbits;
		m_vidmode.greenBits = greenbits;
		m_vidmode.blueBits = bluebits;
	}

	VideoMode::VideoMode(GLFWvidmode vidmode) : m_vidmode(vidmode) {}

	VideoMode::VideoMode()
	{
		m_vidmode.width = 640;
		m_vidmode.height = 320;
		m_vidmode.refreshRate = 60;
		m_vidmode.redBits = 24;
		m_vidmode.greenBits = 24;
		m_vidmode.blueBits = 24;
	}
}

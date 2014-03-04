#pragma once
#include <GLFW/glfw3.h>
#include <glfw-cxx/Vector2.hpp>

namespace glfw
{
	using Resolution = Vector2<int>;

	/*!\brief A class containing information on a videomode
	 */
	class VideoMode
	{
	private:
		GLFWvidmode m_vidmode;

	public:

		/*!\brief Gets the width of the videomode
		 * \returns the width of the videomode
		 */
		int GetWidth() const;

		/*!\brief Sets the width of the videomode
		 * \param[in] width the width of the videomode
		 */
		void SetWidth(int width);

		/*!\brief Gets the height of the videomode
		 * \returns the height of the videomode
		 */
		int GetHeight() const;

		/*!\brief Sets the height of the videomode
		 * \param[in] height the height of the videomode
		 */
		void SetHeight(int height);

		/*!\brief Gets the resolution of the videomode
		 * \returns the resolution of the videomode
		 */
		Resolution GetResolution() const;

		/*!\brief Sets the resolution of the videomode
		 * \param[in] res the resolution of the videomode
		 */
		void SetResolution(Resolution res);

		/*!\brief Gets the bit depth for red
		 * \returns the red bit depth
		 */
		int GetRedBits() const;

		/*!\brief Sets the bit depth for red
		 * \param[in] redbits The new red bit depth
		 */
		void SetRedBits(int redbits);

		/*!\brief Gets the bit depth for green
		 * \returns the green bit depth
		 */
		int GetGreenBits() const;

		/*!\brief Sets the bit depth for green
		 * \param[in] greenbits The new green bit depth
		 */
		void SetGreenBits(int greenbits);

		/*!\brief Gets the bit depth for blue
		 * \returns the blue bit depth
		 */
		int GetBlueBits() const;

		/*!\brief Sets the bit depth for blue
		 * \param[in] bluebits The new blue bit depth
		 */
		void SetBlueBits(int bluebits);

		/*!\brief Gets the refresh rate for the monitor
		 * \returns the monitor's refresh rate
		 */
		int GetRefreshRate() const;

		/*!\brief Sets the refresh rate for the monitor
		 * \param[in] refreshrate the monitor's new refresh rate
		 */
		void SetRefreshRate(int refreshrate);

		/*!\brief Gets the C GLFW pointer for the monitor
		 * \returns the monitor's C GLFW pointer
		 */
		GLFWvidmode* GetRawPointerData();

		VideoMode(int width, int height);
		VideoMode(int width, int height, int refreshrate);
		VideoMode(int width, int height, int redbits, int greenbits, int bluebits);
		VideoMode(int width, int height, int redbits, int greenbits, int bluebits, int refreshrate);
		VideoMode(GLFWvidmode vidmode);
		VideoMode();
	};
}

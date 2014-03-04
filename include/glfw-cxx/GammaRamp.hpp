#pragma once
#include <GLFW/glfw3.h>

namespace glfw
{
	/*!\brief A class describing gamma ramp parameters.
	 */
	class GammaRamp
	{
	private:
		GLFWgammaramp m_gammaramp;

	public:
		
		/*! \brief Returns an array of values describing the response of the red channel.
		 * \return An array of values describing the response of the red channel.
		 */
		unsigned short* GetRed();
		/*! \brief Sets the array of values describing the response of the red channel.
		 * \param[in] red An array of values describing the response of the red channel.
		 */
		void SetRed(unsigned short* red);

		/*! \brief Returns an array of values describing the response of the green channel.
		 * \return An array of values describing the response of the green channel.
		 */
		unsigned short* GetGreen();
		/*! \brief Sets the array of values describing the response of the green channel.
		 * \param[in] green An array of values describing the response of the green channel.
		 */
		void SetGreen(unsigned short* green);

		/*! \brief Returns an array of values describing the response of the blue channel.
		 * \return An array of values describing the response of the blue channel.
		 */
		unsigned short* GetBlue();
		/*! \brief Sets the array of values describing the response of the blue channel.
		 * \param[in] blue An array of values describing the response of the blue channel.
		 */
		void SetBlue(unsigned short* blue);

		/*! \brief Returns the size of the ramp
		 * \return The size of the ramp
		 */
		unsigned int GetSize();
		/*! \brief Sets the size of the ramp
		 * \param[in] size The size of the ramp
		 */
		void SetSize(unsigned int size);

		/*! \brief Returns the C GLFW pointer to the data
		 * \return the C GLFW pointer to the data
		 */
		GLFWgammaramp* GetRawPointerData();

		GammaRamp(GLFWgammaramp gammaramp);
		GammaRamp();
	};
}

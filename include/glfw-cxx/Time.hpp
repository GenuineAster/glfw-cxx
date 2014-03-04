#pragma once
#include <GLFW/glfw3.h>

namespace glfw
{
	/*!\brief GLFW timer handling
	 */
	class Time
	{
	public:
		/*!\brief Gets the current time of the GLFW timer.
		 * \returns the current time of the GLFW timer.
		 */
		static double Get();

		/*!\brief Sets the current time of the GLFW timer.
		 * \param[in] time The new time for the GLFW timer.
		 */
		static void Set(double time);
	};
}

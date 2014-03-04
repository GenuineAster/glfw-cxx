#pragma once

namespace glfw
{
	/*!\brief Returns the glfwInit() status.
	 * \warning It is not necessary to call this on startup. glfw-cxx takes care of initiating glfw.
	 * \returns The glfwinit() status.
	 */
	bool GetInit();

	/*!\brief Returns whether GLFW will terminate on exit. This should always be true.
	 * \warning If this is true, do not call glfwTerminate() on exit.
	 * \returns whether GLFW will terminate on exit.
	 */
	bool GetWillTerminateOnExit();
}

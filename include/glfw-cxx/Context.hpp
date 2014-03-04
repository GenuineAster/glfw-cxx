/*! \file Context.hpp
 * \brief The Context header file
 *
 * Contains several functions used for context handling.
 */


#pragma once
#include <GLFW/glfw3.h>
#include <string>

/*! 
  * \brief The GLFW namespace
  */
namespace glfw
{
	/*! \brief Client API function pointer type.
	 *
	 *  Generic function pointer used for returning client API function pointers
	 *  without forcing a cast from a regular pointer.
	 */
	using glproc = GLFWglproc;

	class Window;

	/*!
	 * \brief The Context namespace
	 */
	namespace Context
	{
		/*! \brief Makes the context of the specified window current for the calling
		 *  thread.
		 *
		 *  This function makes the context of the specified window current on the
		 *  calling thread.  A context can only be made current on a single thread at
		 *  a time and each thread can have only a single current context at a time.
		 *
		 *  \param[in] window The window whose context to make current, or `NULL` to
		 *  detach the current context.
		 *
		 *  \remarks This function may be called from secondary threads.
		 *
		 *  \sa glfwGetCurrentContext
		 *
		 *  \ingroup context
		 */
		void MakeContextCurrent(Window &window);

		/*! \brief Returns the window whose context is current on the calling thread.
		 *
		 *  This function returns the window whose context is current on the calling
		 *  thread.
		 *
		 *  \return The window whose context is current, or `NULL` if no window's
		 *  context is current.
		 *
		 *  \remarks This function may be called from secondary threads.
		 *
		 *  \sa glfwMakeContextCurrent()
		 *
		 *  \ingroup context
		 */
		Window GetCurrentContext();

		/*! \brief Sets the swap interval for the current context.
		 *
		 *  This function sets the swap interval for the current context, i.e. the
		 *  number of screen updates to wait before swapping the buffers of a window and
		 *  returning from @ref glfwSwapBuffers.  This is sometimes called 'vertical
		 *  synchronization', 'vertical retrace synchronization' or 'vsync'.
		 *
		 *  Contexts that support either of the `WGL_EXT_swap_control_tear` and
		 *  `GLX_EXT_swap_control_tear` extensions also accept negative swap intervals,
		 *  which allow the driver to swap even if a frame arrives a little bit late.
		 *  You can check for the presence of these extensions using @ref
		 *  glfwExtensionSupported.  For more information about swap tearing, see the
		 *  extension specifications.
		 *
		 *  \param[in] interval The minimum number of screen updates to wait for
		 *  until the buffers are swapped by @ref glfwSwapBuffers.
		 *
		 *  \remarks This function may be called from secondary threads.
		 *
		 *  \note This function is not called during window creation, leaving the swap
		 *  interval set to whatever is the default on that platform.  This is done
		 *  because some swap interval extensions used by GLFW do not allow the swap
		 *  interval to be reset to zero once it has been set to a non-zero value.
		 *
		 *  \note Some GPU drivers do not honor the requested swap interval, either
		 *  because of user settings that override the request or due to bugs in the
		 *  driver.
		 *
		 *  \sa \ref glfwSwapBuffers()
		 *
		 *  \ingroup context
		 */
		void SwapInterval(int interval);

		/*! \brief Returns whether the specified extension is available.
		 *
		 *  This function returns whether the specified
		 *  [OpenGL or context creation API extension](@ref context_glext) is supported
		 *  by the current context.  For example, on Windows both the OpenGL and WGL
		 *  extension strings are checked.
		 *
		 *  \param[in] extension The name of the extension.
		 *  \return `GL_TRUE` if the extension is available, or `GL_FALSE` otherwise.
		 *
		 *  \remarks This function may be called from secondary threads.
		 *
		 *  \note As this functions searches one or more extension strings on each call,
		 *  it is recommended that you cache its results if it's going to be used
		 *  frequently.  The extension strings will not change during the lifetime of
		 *  a context, so there is no danger in doing this.
		 *
		 *  \ingroup context
		 */
		int ExtensionSupported(std::string extension);

		/*! \brief Returns the address of the specified function for the current
		 *  context.
		 *
		 *  This function returns the address of the specified
		 *  [client API or extension function](@ref context_glext), if it is supported
		 *  by the current context.
		 *
		 *  \param[in] procname The name of the function.
		 *  \return The address of the function, or `NULL` if the function is
		 *  unavailable.
		 *
		 *  \remarks This function may be called from secondary threads.
		 *
		 *  \note The addresses of these functions are not guaranteed to be the same for
		 *  all contexts, especially if they use different client APIs or even different
		 *  context creation hints.
		 *
		 *  \ingroup context
		 */
		glproc GetProcAddress(std::string procname);
	}
}

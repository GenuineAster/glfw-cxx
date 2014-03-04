#pragma once
#include <GLFW/glfw3.h>
#include <string>
#include <functional>
#include <iostream>

namespace glfw
{

	/*! \brief The error codes thrown by GLFW
	 */
	enum ErrorCode
	{
		NotInitialized = 0x00010001,
		NoCurrentContext,
		InvalidEnum,
		InvalidValue,
		OutOfMemory,
		ApiUnavailable,
		VersionUnavailable,
		PlatformError,
		FormatUnavailable
	};

	/*! \brief Defines a system event and its parameters
	 */
	class Error
	{
	private:
		/*! \brief The std::function type for error callbacks.
		 *
		 *  This is the std::function type for error callbacks.
		 *
		 *  \param[in] error The error
		 *
		 *  \sa SetErrorCallback
		 *
		 */
		using Function = std::function<void(Error)>;

		/*! \brief The function signature for error callbacks.
		 *
		 *  This is the function signature for error callback functions.
		 *
		 *  \param[in] error The error
		 *
		 *  \sa SetErrorCallback
		 *
		 */
		using FunctionPointer = void(Error);


		/*! \brief The legacy GLFW function signature for error callbacks.
		 *
		 *  This is the function legacy GLFW signature for error callback functions.
		 *
		 *  \param[in] error An \ref ErrorCode["error code"].
		 *  \param[in] description A UTF-8 encoded string describing the error.
		 *
		 *  \sa SetErrorCallback
		 *
		 */
		using FunctionPointerRaw = void(int, const char*);

		static const Function DefaultErrorFunction;
		static void LambdaFunctionWrapper(Error error);
		static void FunctionPointerWrapper(int error, const char* description);

		static Function CurrentErrorFunction;
		static FunctionPointer* CurrentErrorFunctionPointer;
		static FunctionPointerRaw* CurrentErrorFunctionPointerRaw;

	public:

		/*! \brief Returns the default error callback
		 *
		 * This function returns the default error callback.
		 */

		static Function GetDefaultErrorCallback();

		/*! \brief Sets the error callback
		 *  
		 *  Sets the error callback.
		 *  
		 *  \param[in] fun A function of type Function
		 *
		 *	\warning Changing the callback will nullify the default behavior.
		 */
		static Function SetErrorCallback(Function fun);

		/*! \brief Sets the error callback
		 *  
		 *  Sets the error callback.
		 *  
		 *  \param[in] fun A function of type FunctionPointer
		 *
		 *	\warning Changing the callback will nullify the default behavior.
		 */
		static const FunctionPointer* SetErrorCallback(FunctionPointer* fun);

		/*! \brief Sets the error callback
		 *  
		 *  Sets the error callback.
		 *  
		 *  \param[in] fun A function of type FunctionPointerRaw
		 *
		 *	\warning Changing the callback will nullify the default behavior.
		 */
		static const FunctionPointerRaw* SetErrorCallback(FunctionPointerRaw* fun);

	public:
		/*! \brief The error code
		 */
		ErrorCode error;

		/*! \brief The error description
		 */
		std::string description;

		/*! \brief Error constructor
		 *  \param[in] error_ the \ref ErrorCode["error code"] of the error
		 */
		Error(ErrorCode error_, const char* description_);
	};
}

#include <glfw-cxx/Error.hpp>
#include <iostream>


namespace glfw
{

	//FunctionPointerRaw 
	namespace Error
	{
		void LambdaFunctionWrapper(ErrorData error)
		{
			CurrentErrorFunction(error);
		}

		void FunctionPointerWrapper(int error, const char* description)
		{
			CurrentErrorFunctionPointer({error, description});
		}

		Function GetDefaultErrorCallback()
		{
			return DefaultErrorFunction;
		}

		Function SetErrorCallback(Function fun)
		{
			Function temp = CurrentErrorFunction;
			CurrentErrorFunction = fun;
			CurrentErrorFunctionPointer = LambdaFunctionWrapper;
			CurrentErrorFunctionPointerRaw = FunctionPointerWrapper;
			glfwSetErrorCallback(CurrentErrorFunctionPointerRaw);
			return temp;
		}

		const FunctionPointer* SetErrorCallback(FunctionPointer fun)
		{
			FunctionPointer* temp = CurrentErrorFunctionPointer;
			CurrentErrorFunctionPointer = fun;
			CurrentErrorFunctionPointerRaw = FunctionPointerWrapper;
			glfwSetErrorCallback(CurrentErrorFunctionPointerRaw);
			return temp;
		}

		const FunctionPointerRaw* SetErrorCallback(FunctionPointerRaw fun)
		{
			FunctionPointerRaw* temp = CurrentErrorFunctionPointerRaw;
			CurrentErrorFunctionPointerRaw = fun;
			glfwSetErrorCallback(CurrentErrorFunctionPointerRaw);
			return temp;
		}
	}

	ErrorData::ErrorData(int error_, const char* description_): 
		error{static_cast<ErrorCode>(error_)}, description{description_} {}
}

#include <glfw-cxx/Error.hpp>
#include <iostream>


namespace glfw
{
	const Error::Function Error::DefaultErrorFunction = [](Error error)
	{
		std::cerr<<"ERROR "<<error.error<<": "<<error.description<<std::endl;
	};

	Error::Function Error::CurrentErrorFunction = Error::DefaultErrorFunction;
	Error::FunctionPointer *Error::CurrentErrorFunctionPointer = *Error::LambdaFunctionWrapper;
	Error::FunctionPointerRaw *Error::CurrentErrorFunctionPointerRaw = *Error::FunctionPointerWrapper;


	void Error::LambdaFunctionWrapper(Error error)
	{
		CurrentErrorFunction(error);
	}

	void Error::FunctionPointerWrapper(int error, const char* description)
	{
		CurrentErrorFunctionPointer({static_cast<ErrorCode>(error), description});
	}

	Error::Function Error::GetDefaultErrorCallback()
	{
		return DefaultErrorFunction;
	}

	Error::Function Error::SetErrorCallback(Error::Function fun)
	{
		Function temp = CurrentErrorFunction;
		CurrentErrorFunction = fun;
		CurrentErrorFunctionPointer = LambdaFunctionWrapper;
		CurrentErrorFunctionPointerRaw = FunctionPointerWrapper;
		glfwSetErrorCallback(CurrentErrorFunctionPointerRaw);
		return temp;
	}

	const Error::FunctionPointer* Error::SetErrorCallback(Error::FunctionPointer fun)
	{
		FunctionPointer* temp = CurrentErrorFunctionPointer;
		CurrentErrorFunctionPointer = fun;
		CurrentErrorFunctionPointerRaw = FunctionPointerWrapper;
		glfwSetErrorCallback(CurrentErrorFunctionPointerRaw);
		return temp;
	}

	const Error::FunctionPointerRaw* Error::SetErrorCallback(Error::FunctionPointerRaw fun)
	{
		FunctionPointerRaw* temp = CurrentErrorFunctionPointerRaw;
		CurrentErrorFunctionPointerRaw = fun;
		glfwSetErrorCallback(CurrentErrorFunctionPointerRaw);
		return temp;
	}

	Error::Error(ErrorCode error_, const char* description_): 
		error{static_cast<ErrorCode>(error_)}, description{description_} {}
}

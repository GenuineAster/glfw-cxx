#pragma once
#include <GLFW/glfw3.h>
#include <string>
#include <functional>
#include <iostream>

namespace glfw
{
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

	class ErrorData
	{
	public:
		ErrorCode error;
		std::string description;
		ErrorData(int error_, const char* description_);
	};

	namespace Error
	{
		using Function = std::function<void(ErrorData)>;
		using FunctionPointer = void(ErrorData);
		using FunctionPointerRaw = void(int, const char*);


		void LambdaFunctionWrapper(ErrorData error);
		void FunctionPointerWrapper(int error, const char* description);


		const Function DefaultErrorFunction = [](ErrorData error)
		{
			std::cerr<<"ERROR "<<error.error<<": "<<error.description<<std::endl;
		};

		Function CurrentErrorFunction = DefaultErrorFunction;
		FunctionPointer* CurrentErrorFunctionPointer = *LambdaFunctionWrapper;
		FunctionPointerRaw* CurrentErrorFunctionPointerRaw = *FunctionPointerWrapper;


		Function GetDefaultErrorCallback();
		Function SetErrorCallback(Function fun);
		const FunctionPointer* SetErrorCallback(FunctionPointer* fun);
		const FunctionPointerRaw* SetErrorCallback(FunctionPointerRaw* fun);

	}


}

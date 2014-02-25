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

	class Error
	{
	public:
		using Function = std::function<void(Error)>;
		using FunctionPointer = void(Error);
		using FunctionPointerRaw = void(int, const char*);

		static void LambdaFunctionWrapper(Error error);
		static void FunctionPointerWrapper(int error, const char* description);

		static const Function DefaultErrorFunction;

		static Function CurrentErrorFunction;
		static FunctionPointer* CurrentErrorFunctionPointer;
		static FunctionPointerRaw* CurrentErrorFunctionPointerRaw;

		static Function GetDefaultErrorCallback();
		static Function SetErrorCallback(Function fun);
		static const FunctionPointer* SetErrorCallback(FunctionPointer* fun);
		static const FunctionPointerRaw* SetErrorCallback(FunctionPointerRaw* fun);

	public:
		ErrorCode error;
		std::string description;
		Error(int error_, const char* description_);
	};
}

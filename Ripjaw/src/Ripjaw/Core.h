#pragma once

#ifdef RJ_PLATFORM_WINDOWS
	#ifdef RJ_BUILD_DLL
		#define RIPJAW_API __declspec(dllexport)
	#else
		#define RIPJAW_API __declspec(dllimport)
	#endif
#else
	#error Ripjaw provides support for Windows only!
#endif

#ifdef RJ_ENABLE_ASSERTS
	#define RJ_ASSERT(x, ...) { if(!(x)) { RJ_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define RJ_CORE_ASSERT(x, ...) { if(!(x)) { RJ_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define RJ_ASSERT(x, ...)
	#define RJ_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)
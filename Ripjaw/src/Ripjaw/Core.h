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

#define BIT(x) (1 << x)
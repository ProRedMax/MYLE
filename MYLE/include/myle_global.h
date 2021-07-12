#pragma once

#if defined(MYLE_DLL_LIBRARY)
	#define MYLE_API __declspec(dllexport)
#else
	#define MYLE_API
#endif

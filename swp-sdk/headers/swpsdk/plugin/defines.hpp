#pragma once

#ifndef SWP_SDK_API
#ifndef SWP_LOADER
#	define SWP_SDK_API extern "C" __declspec(dllexport) 
#else
#	define SWP_SDK_API extern "C"
#endif // !SWP_LOADER
#endif // !SWP_SDK_API
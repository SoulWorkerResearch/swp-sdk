#pragma once

// local
#include "./plugin_info.hpp"

namespace swpsdk::plugin
{
#ifdef SWP_SDK_API
  static_assert("wtf?");
#endif

#ifndef SWP_LOADER
#define SWP_SDK_API extern "C" __declspec(dllexport) 
#else
#define SWP_SDK_API 
#endif

  SWP_SDK_API [[nodiscard]] auto emplace(void)->info*;

#undef SWP_SDK_API
}
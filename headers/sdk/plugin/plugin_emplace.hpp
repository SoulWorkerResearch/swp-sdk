#pragma once

// local
#include "./plugin_info.hpp"

namespace sdk::plugin
{
#ifdef SWP_SDK_API
  static_assert("wtf?");
#endif

#ifndef SWP_LOADER
#define SWP_SDK_API extern "C" __declspec(dllexport)
#else
#define SWP_SDK_API
#endif

  SWP_SDK_API auto emplace(void)->info*;

#undef SWP_SDK_API
}
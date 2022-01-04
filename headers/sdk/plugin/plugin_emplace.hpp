#pragma once

// local
#include "./plugin_info.hpp"

namespace sdk::plugin
{
  extern "C" __declspec(dllexport) auto emplace(void)->info*;
}
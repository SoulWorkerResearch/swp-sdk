#pragma once

// cpp
#include <string_view>

// local
#include "../version.hpp"
#include "../version.hpp"
#include "./callback.hpp"
#include "../defines.hpp"

namespace swpsdk::plugin
{
  struct info final
  {
    const version game_version;
    const version plugin_version{};
    const callback* instance;
    const version& sdk_version{ swpsdk::current_version };
  };
}
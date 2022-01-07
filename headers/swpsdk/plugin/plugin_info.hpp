#pragma once

// deps
#include <neargye/semver.hpp>

// cpp
#include <string_view>

// local
#include "../game/game_version.hpp"
#include "../sdk_version.hpp"
#include "./plugin_callback.hpp"

namespace swpsdk::plugin
{
  struct info final
  {
    const game::version game_version;
    const semver::version plugin_version;
    const callback* instance;
    const semver::version sdk_version = version;
  };
}
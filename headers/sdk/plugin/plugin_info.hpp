#pragma once

// deps
#include <neargye/semver.hpp>

// cpp
#include <string_view>

// local
#include "../sdk_version.hpp"
#include "./plugin_callback.hpp"

namespace sdk::plugin
{
  struct info final
  {
    const semver::version game_version;
    const semver::version plugin_version;
    const semver::version sdk_version = version;
    const callback& instance;
  };
}
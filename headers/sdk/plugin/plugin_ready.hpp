#pragma once

// deps
#include <spdlog/spdlog.h>

// cpp
#include <memory>

// local
#include "./plugin_callback.hpp"

namespace sdk::plugin
{
  auto ready(const std::shared_ptr<spdlog::logger>&_logger, const callback & _value) -> void
  {
    spdlog::set_default_logger(_logger);

    _value.on_ready();
  }
}

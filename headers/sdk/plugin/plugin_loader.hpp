#pragma once

// deps
#include <spdlog/spdlog.h>

// cpp
#include <memory>

namespace sdk::plugin
{
  class loader
  {
  public:
    constexpr virtual auto ready(const std::shared_ptr<spdlog::logger>& _logger) const -> void = 0;
  };
}

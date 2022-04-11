#pragma once

// deps
#include <spdlog/spdlog.h>

// cpp
#include <memory>

namespace swpsdk::plugin
{
  class loader
  {
  public:
    constexpr virtual auto attach(const std::shared_ptr<spdlog::logger>& _logger) const -> void = 0;
  };
}

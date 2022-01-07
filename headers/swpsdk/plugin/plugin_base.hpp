#pragma once

// windows
#include <Windows.h>

// cpp
#include <string_view>

// local
#include "./plugin_memory.hpp"
#include "./plugin_callback.hpp"

namespace swpsdk::plugin
{
  template <typename TPlugin> class base : public memory<TPlugin>, public callback
  {
  protected:
    base(void) noexcept {}
    virtual ~base(void) noexcept {}

  private:
    constexpr virtual auto ready(const std::shared_ptr<spdlog::logger>& _logger) const -> void
    {
      set_default_logger(_logger);

      this->main();
    }
  };
};
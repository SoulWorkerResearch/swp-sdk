#pragma once

// windows
#include <Windows.h>

// cpp
#include <string_view>

// local
#include "./memory.hpp"
#include "./callback.hpp"

namespace swpsdk::plugin
{
  template <typename TPlugin> class base : public memory<TPlugin>, public callback, private loader
  {
  protected:
    base(void) noexcept {}
    virtual ~base(void) noexcept {}

  private:
    constexpr auto attach(const std::shared_ptr<spdlog::logger>& _logger) const -> void override final
    {
      setup_logger(_logger);

      this->main();
    }

    static auto setup_logger(const std::shared_ptr<spdlog::logger>& _logger) -> void
    {
      set_default_logger(_logger);
    }
  };
};
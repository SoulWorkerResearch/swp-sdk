#pragma once

#include "loader.hpp"

namespace swpsdk::plugin
{
  class callback : private loader
  {
  protected:
    constexpr virtual auto main(void) const -> void = 0;

  protected:
    callback(void) noexcept {}
    virtual ~callback(void) noexcept {}

  private:
    auto attach(const std::shared_ptr<spdlog::logger>& _logger) const -> void override final
    {
      setup_logger(_logger);

      this->main();
    }

    static auto setup_logger(const std::shared_ptr<spdlog::logger> _logger) -> void
    {
      set_default_logger(_logger);
    }
  };
};
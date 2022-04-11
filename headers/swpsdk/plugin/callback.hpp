#pragma once

#include "loader.hpp"

namespace swpsdk::plugin
{
  class callback
  {
  protected:
    constexpr virtual auto main(void) const -> void = 0;

  protected:
    callback(void) noexcept {}
    virtual ~callback(void) noexcept {}
  };
};
#pragma once

#include "plugin_loader.hpp"

namespace swpsdk::plugin
{
  class callback : private loader
  {
  public:
    constexpr virtual auto main(void) const -> void = 0;

  protected:
    callback(void) noexcept {}
    virtual ~callback(void) noexcept {}
  };
};
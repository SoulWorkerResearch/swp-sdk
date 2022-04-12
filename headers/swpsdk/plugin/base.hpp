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
  template <typename TPlugin> class base : public memory<TPlugin>, public callback
  {
  protected:
    base(void) noexcept {}
    virtual ~base(void) noexcept {}
  };
};
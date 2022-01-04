#pragma once

// windows
#include <Windows.h>

// cpp
#include <string_view>

// local
#include "./plugin_memory.hpp"
#include "./plugin_callback.hpp"

namespace sdk::plugin
{
  template <typename TPlugin> class base : public memory<TPlugin>, public callback
  {
  protected:
    base(void) noexcept {}
    virtual ~base(void) noexcept {}
  };
};
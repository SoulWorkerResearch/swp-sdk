#pragma once

// local
#include "../utils/memory.hpp"
#include "./callback.hpp"

namespace swpsdk::plugin
{
  template <typename TPlugin> class base : public utils::memory<TPlugin>, public callback
  {
  protected:
    base(void) noexcept {}
    virtual ~base(void) noexcept {}
  };
};
#pragma once

// local
#include "../version.hpp"

// deps
#include <spdlog/fmt/ostr.h>

template<typename OStream>
OStream& operator<<(OStream& _stream, const swpsdk::version& _value)
{
  return _stream << _value;
}

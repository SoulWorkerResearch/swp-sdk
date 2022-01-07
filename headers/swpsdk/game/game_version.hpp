#pragma once

// cpp
#include <string_view>
#include <sstream>

namespace swpsdk::game
{
  struct version final
  {
    const uint8_t major;
    const uint8_t minor;
    const uint8_t patch;
    const uint8_t build;

    constexpr auto operator<=>(const version&) const noexcept = default;

    friend std::ostream& operator<<(std::ostream& _os, const version& _value)
    {
      return _os
        << static_cast<uint32_t>(_value.major) << '.' 
        << static_cast<uint32_t>(_value.minor) << '.' 
        << static_cast<uint32_t>(_value.patch) << '.' 
        << static_cast<uint32_t>(_value.build);
    }

    static version from_chars(const std::string_view _buffer);

    constexpr version(const uint8_t _major, const uint8_t _minor, const uint8_t _patch, const uint8_t _build) noexcept :
      major{ _major },
      minor{ _minor },
      patch{ _patch },
      build{ _build }
    {}
  };
}
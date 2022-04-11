#pragma once

// cpp
#include <string_view>
#include <sstream>

namespace swpsdk
{
  struct version final
  {
#pragma region Members

    const uint8_t major;
    const uint8_t minor;
    const uint8_t patch;
    const uint8_t build;

#pragma endregion Members

#pragma region Operators

    version& operator=(version&&) = default;
    version& operator=(const version&) = delete;
    version& operator=(const version) = delete;

    constexpr auto operator<=>(const version&) const noexcept = default;

    static friend std::ostream& operator<<(std::ostream& _os, const version& _value)
    {
      return _os
        << static_cast<uint32_t>(_value.major) << '.'
        << static_cast<uint32_t>(_value.minor) << '.'
        << static_cast<uint32_t>(_value.patch) << '.'
        << static_cast<uint32_t>(_value.build);
    }

#pragma endregion Operators

#pragma region Methods

    static version from_chars(const std::string_view _buffer);

#pragma endregion Methods

#pragma region Constructors

    constexpr version(version&&) = default;
    constexpr version(const version&) = delete;

    constexpr version(const uint8_t _major = 0, const uint8_t _minor = 0, const uint8_t _patch = 0, const uint8_t _build = 0) noexcept :
      major{ _major },
      minor{ _minor },
      patch{ _patch },
      build{ _build }
    {}

#pragma endregion Constructors
  };
}
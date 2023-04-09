#pragma once

#include <sstream>
#include <compare>
#include <cstdint>

namespace swpsdk
{
	struct version final
	{
		uint8_t major;
		uint8_t minor;
		uint8_t patch;
		uint8_t build;

		version& operator=(version&&) = default;
		version& operator=(const version&) = default;

		constexpr auto operator<=>(const version&) const noexcept = default;

		static friend std::ostream& operator<<(std::ostream& _os, const version& _value)
		{
			return _os
				<< static_cast<uint32_t>(_value.major) << '.'
				<< static_cast<uint32_t>(_value.minor) << '.'
				<< static_cast<uint32_t>(_value.patch) << '.'
				<< static_cast<uint32_t>(_value.build);
		}

		static version from_chars(const std::string_view _buffer);

		constexpr version(version&&) = default;
		constexpr version(const version&) = default;

		constexpr version(const uint8_t _major = 0, const uint8_t _minor = 0, const uint8_t _patch = 0, const uint8_t _build = 0) noexcept :
			major{ _major },
			minor{ _minor },
			patch{ _patch },
			build{ _build }
		{}
	};
}

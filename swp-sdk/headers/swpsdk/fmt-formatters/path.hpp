#pragma once

#include <filesystem>
#include <format>

template<>
struct std::formatter<std::filesystem::path> : formatter<string_view>
{
	auto format(std::filesystem::path _value, format_context& _context) const
	{
		return formatter<string_view>::format(_value.string(), _context);
	}
};

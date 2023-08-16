#pragma once

#include <filesystem>
#include <format>

template<>
struct std::formatter<std::filesystem::directory_entry> : formatter<string_view>
{
	auto format(std::filesystem::directory_entry _value, format_context& _context) const
	{
		return formatter<string_view>::format(_value.path().string(), _context);
	}
};

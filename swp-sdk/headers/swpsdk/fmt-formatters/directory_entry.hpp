#pragma once

#include <filesystem>
#include <format>

template<>
struct std::formatter<std::filesystem::directory_entry> : std::formatter<std::string>
{
	template <typename FormatContext>
	auto format(const std::filesystem::directory_entry& _value, FormatContext& _context) -> decltype(_context.out())
	{
		return std::formatter<std::string>::format(_value.path().string(), _context);
	}
};

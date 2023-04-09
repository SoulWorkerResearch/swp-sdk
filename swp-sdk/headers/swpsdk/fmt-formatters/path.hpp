#pragma once

#include <filesystem>
#include <format>

template<>
struct std::formatter<std::filesystem::path> : std::formatter<std::string>
{
	template <typename FormatContext>
	auto format(const std::filesystem::path& _value, FormatContext& _context) -> decltype(_context.out())
	{
		return std::formatter<std::string>::format(_value.string(), _context);
	}
};

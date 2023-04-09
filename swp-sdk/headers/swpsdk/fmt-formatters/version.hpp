#pragma once

#include "../version.hpp"
#include <format>

template<>
struct std::formatter<swpsdk::version>
{
    constexpr auto parse(format_parse_context& _context) -> decltype(_context.end())
    {
        return _context.end();
    }

    template <typename FormatContext>
    auto format(const swpsdk::version& _value, FormatContext& _context) -> decltype(_context.out())
    {
        return std::format_to(_context.out(), "{}.{}.{}.{}", _value.major, _value.minor, _value.patch, _value.build);
    }
};

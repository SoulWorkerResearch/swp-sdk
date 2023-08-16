#pragma once

#include "../version.hpp"
#include <format>

template<>
struct std::formatter<swpsdk::version> : formatter<string_view>
{
    auto format(swpsdk::version _value, format_context& _context) const
    {
        return format_to(_context.out(), "{}.{}.{}.{}", _value.major, _value.minor, _value.patch, _value.build);
    }
};

#pragma once

// local
#include "../version.hpp"

// deps
#include <fmt/format.h>

template<>
struct fmt::formatter<swpsdk::version> 
{
  constexpr auto parse(format_parse_context& _context) -> decltype(_context.end())
  {
    return _context.end();
  }

  template <typename FormatContext>
  auto format(const swpsdk::version& _value, FormatContext& _context) -> decltype(_context.out())
  {
    return fmt::format_to(_context.out(), "{}.{}.{}.{}", _value.major, _value.minor, _value.patch, _value.build);
  }
};

template<>
struct fmt::formatter<std::filesystem::directory_entry> : fmt::formatter<std::string>
{
  template <typename FormatContext>
  auto format(const std::filesystem::directory_entry& _value, FormatContext& _context) -> decltype(_context.out())
  {
    return fmt::formatter<std::string>::format(_value.path().string(), _context);
  }
};
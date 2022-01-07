// local
#include "../../headers/swpsdk/game/game_version.hpp"

// cpp
#include <vector>
#include <charconv>
#include <algorithm>
#include <ranges>

namespace views = std::ranges::views;

swpsdk::game::version swpsdk::game::version::from_chars(const std::string_view _buffer)
{
  auto range{ _buffer | views::split('.') };
  std::vector<std::string_view> values{ range.begin(), range.end() };

  uint8_t parsed[4]{};
  for (size_t i{ 0 }; i < sizeof(parsed); ++i) {
    auto& value = values[i];
    std::from_chars(value.data(), value.data() + value.length(), parsed[i]);
  }

  return { parsed[0], parsed[1], parsed[2], parsed[3] };
}
// local
#include "../headers/swpsdk/version.hpp"

// cpp
#include <vector>
#include <charconv>
#include <algorithm>
#include <ranges>
#include <array>

namespace views = std::ranges::views;

static constexpr size_t major_id{ 0 };
static constexpr size_t minor_id{ 1 };
static constexpr size_t patch_id{ 2 };
static constexpr size_t build_id{ 3 };

swpsdk::version swpsdk::version::from_chars(const std::string_view _buffer)
{
  auto range{ _buffer | views::split('.') };
  std::vector<std::string_view> values{ range.begin(), range.end() };

  std::array<uint8_t, 4> parsed{};
  for (size_t i{ 0 }; i < parsed.size(); ++i) {
    const auto& value{ values[i] };
    std::from_chars(value.data(), value.data() + value.length(), parsed[i]);
  }

  return { parsed[major_id], parsed[minor_id], parsed[patch_id], parsed[build_id] };
}
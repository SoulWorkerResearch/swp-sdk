#include "version.hpp"

namespace views = std::views;
namespace ranges = std::ranges;

static constexpr size_t major_id{ 0 };
static constexpr size_t minor_id{ 1 };
static constexpr size_t patch_id{ 2 };
static constexpr size_t build_id{ 3 };

namespace swpsdk
{
	version version::from_chars(const std::string_view _buffer)
	{
		auto parsed{ _buffer | views::split('.') | ranges::to<std::vector>() };

		std::array<uint8_t, 4> values{};
		for (size_t i{ 0 }, max{ (std::min)(values.size(), parsed.size()) }; i < max; ++i) {
			const auto& value{ parsed[i] };
			std::from_chars(value.data(), value.data() + value.size(), values[i]);
		}

		return { values[major_id], values[minor_id], values[patch_id], values[build_id] };
	}
}

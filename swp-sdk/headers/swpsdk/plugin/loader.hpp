#pragma once

#include <memory>
#include <spdlog/spdlog.h>

namespace swpsdk::plugin
{
	class loader
	{
	public:
		constexpr virtual auto internal_attach(const std::shared_ptr<spdlog::logger>& _logger) const->int32_t = 0;
		constexpr virtual auto internal_main(void) const->int32_t = 0;

	protected:
		constexpr loader(void) noexcept = default;
		constexpr virtual ~loader(void) = default;
	};
}

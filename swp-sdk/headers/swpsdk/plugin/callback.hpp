#pragma once

#include "loader.hpp"

namespace swpsdk::plugin
{
	class callback : private loader
	{
	protected:
		constexpr virtual auto attach(void) const -> int32_t { return 0; }
		constexpr virtual auto main(void) const -> int32_t { return 0; }

	protected:
		constexpr callback(void) = default;
		constexpr virtual ~callback(void) = default;

	private:
		auto internal_attach(const std::shared_ptr<spdlog::logger>& _logger) const -> int32_t override final
		{
			set_default_logger(_logger);

			return this->attach();
		}

		constexpr auto internal_main(void) const -> int32_t override final
		{
			return this->main();
		}
	};
};

#pragma once

namespace spdlog
{
	inline auto system_error(const std::shared_ptr<spdlog::logger> _ptr = spdlog::default_logger()) -> void
	{
		_ptr->error(std::system_category().message(GetLastError()));
	}
}

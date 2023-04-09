#pragma once

#include "callback.hpp"

#include <swpsdk/sdk_version.hpp>
#include <swpsdk/version.hpp>

namespace swpsdk::plugin
{
	struct info final
	{
		version plugin_version{};
		version game_version{};
		callback* instance{ nullptr };
	};
}

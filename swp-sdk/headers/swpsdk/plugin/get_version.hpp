#pragma once

#include "../sdk_version.hpp"

namespace swpsdk::plugin
{
	SWP_SDK_API [[nodiscard]] auto get_version(version& _version) -> void
	{
		_version = sdk_version;
	}
}

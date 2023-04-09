#pragma once

#include "info.hpp"
#include "defines.hpp"
#include "get_version.hpp"

namespace swpsdk::plugin
{
	SWP_SDK_API [[nodiscard]] auto get_info(info& _info) -> void;
}

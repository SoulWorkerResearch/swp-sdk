#pragma once

#include <string_view>
#include <spdlog/spdlog.h>
#include <detours/detours.h>

namespace swpsdk::detour
{
	template<class TPtr, class TCal>
	auto attach(TPtr& _ptr, TCal&& _cal, std::string_view _name) -> bool
	{
		spdlog::debug("attaching {}...", _name);

		if (const auto status{ DetourAttach(&reinterpret_cast<PVOID&>(_ptr), _cal) }; status != NO_ERROR) {
			spdlog::critical("DetourAttach failed with {:08x}", status);
			return false;
		}

		spdlog::debug("attached {} ok", _name);
		return true;
	}
}

#pragma once

#include <string_view>
#include <spdlog/spdlog.h>
#include <detours/detours.h>

namespace swpsdk::detour
{
	template<class TPtr, class TCal>
	auto detach(TPtr&& _ptr, TCal&& _cal, std::string_view _name) -> bool
	{
		spdlog::debug("detaching {}...", _name);

		if (const auto status{ DetourDetach(&reinterpret_cast<PVOID&>(_ptr), _cal) }; status != NO_ERROR) {
			spdlog::critical("DetourDetach failed with {:08x}", status);
			return false;
		}

		spdlog::debug("detached {} ok", _name);
		return true;
	}
}

#include "detour/transaction.hpp"

namespace swpsdk::detour
{
	auto transaction(std::initializer_list<std::function<bool()>>&& _callbacks) -> bool
	{
		if (const auto status{ DetourTransactionBegin() };  status != NO_ERROR) {
			spdlog::critical("DetourTransactionBegin failed with {:08x}", status);
			return false;
		}

		if (std::ranges::all_of(_callbacks, [](auto&& e) { return e(); })) {
			const auto status{ DetourTransactionCommit() };
			if (status == NO_ERROR) { return true; }

			spdlog::critical("DetourTransactionCommit failed with {:08x}", status);
			// no return at this point - must be aborted
		}

		if (const auto status{ DetourTransactionAbort() }; status != NO_ERROR) {
			spdlog::critical("DetourTransactionAbort failed with {:08x}", status);
			return false;
		}

		spdlog::info("Aborted transaction");
		return true;
	}
}

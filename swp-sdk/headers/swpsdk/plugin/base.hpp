#pragma once

#include "callback.hpp"
#include <swpsdk/helpers/memory.hpp>

namespace swpsdk::plugin
{
	template <typename TPlugin> class base : public helpers::memory<TPlugin>, public callback
	{
	protected:
		constexpr base(void) noexcept = default;
		constexpr virtual ~base(void) noexcept = default;
	};
};

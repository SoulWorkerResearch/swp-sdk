#pragma once

#include <initializer_list>
#include <functional>

namespace swpsdk::detour
{
	auto transaction(std::initializer_list<std::function<bool()>>&& _callbacks) -> bool;
}

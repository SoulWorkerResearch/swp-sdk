#pragma once

#include "ini_schema.hpp"

namespace swpsdk::parsers
{
	template <class TPair> requires requires { std::same_as<typename TPair::second_type, ini_schema<typename TPair::first_type>>; }
	auto from_pair(std::filesystem::path _path) -> TPair::first_type
	{
		if (not std::filesystem::exists(_path)) {
			spdlog::error("{} not exists", _path);
			return {};
		}

		typename TPair::first_type value{};
		typename TPair::second_type{ value, _path }.apply();

		return value;
	}
}
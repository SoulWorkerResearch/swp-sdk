#pragma once

#include <swpsdk/version.hpp>
#include <swpsdk/parsers/ini_schema.hpp>

namespace swpsdk::configs::ver
{
	struct client final
	{
		swpsdk::version version{};
	};

	struct type final
	{
		client client{};
	};

	struct schema final : parsers::ini_schema<type>
	{
		constexpr void apply(void)
		{
			using namespace std::string_view_literals;

			section("Client", &type::client, std::tuple{ "ver"sv, & client::version });
		}

		constexpr schema(type& _value, std::filesystem::path _path) noexcept : ini_schema{ _value, _path } {}
	};

	using pair = std::pair<type, schema>;
}

#pragma once

namespace swpsdk::helpers::ini
{
	template<class TValue>
	struct basic abstract
	{
		template<class TSection, class ...ARGS>
		constexpr void section(std::u8string_view _name, TSection&& _section, ARGS &&... _args)
		{
			const auto section = std::ranges::find_if(m_values, [&](const auto _value) { return _value.first == _name; });
			if (std::cend(m_values) == section) {
				spdlog::warn("section key not found: {}", std::string_view{ reinterpret_cast<const char*>(std::data(_name)), std::size(_name) });
				return;
			}

			(row(std::get<0>(_args), section, _section, std::get<1>(_args)), ...);
		}

		template <class TSection, class TRow>
		constexpr void row(std::u8string_view _name, const sections_type::const_iterator _values, TSection&& _section, TRow&& _row)
		{
			const auto value = std::ranges::find_if(_values->second, [&](const auto _value) { return _value.first == _name; });
			if (std::cend(_values->second) == value) {
				spdlog::warn("row key not found: {}", std::string_view{ reinterpret_cast<const char*>(std::data(_name)), std::size(_name) });
				return;
			}

			from(m_value.*_section.*_row, value);
		}

		template<std::unsigned_integral T>
		void from(T& _value, values_type::const_iterator _pair)
		{
			_value = static_cast<T>(std::stoul({ reinterpret_cast<const char*>(std::data(_pair->second)), std::size(_pair->second) }));
		}

		template<std::signed_integral T>
		void from(T& _value, values_type::const_iterator _pair)
		{
			_value = static_cast<T>(std::stoll({ reinterpret_cast<const char*>(std::data(_pair->second)), std::size(_pair->second) }));
		}

		void from(bool& _value, values_type::const_iterator _pair)
		{
			_value = static_cast<bool>(std::stoi({ reinterpret_cast<const char*>(std::data(_pair->second)), std::size(_pair->second) }));
		}

		void from(std::u8string& _value, values_type::const_iterator _pair)
		{
			_value = _pair->second;
		}

		template<class T>
		constexpr void from(T& _value, values_type::const_iterator _pair)
		{
			spdlog::warn("bad schema value: {}", std::string_view{ reinterpret_cast<const char*>(std::data(_pair->first)), std::size(_pair->first) });
		}

		constexpr basic(TValue& _value) noexcept : m_value{ _value } {}

	private:
		TValue& m_value;
	};
}
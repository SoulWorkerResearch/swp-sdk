#pragma once

namespace swpsdk::parsers
{
	template<class TValue>
	struct ini_schema
	{
		template<class TSection, class ...ARGS>
		constexpr void section(std::string_view _section_name, TSection&& _section, ARGS&&... _args)
		{
			(row(std::get<0>(_args), _section_name, _section, std::get<1>(_args)), ...);
		}

		template <class TSection, class TRow>
		constexpr void row(std::string_view _key_name, std::string_view _section_name, TSection&& _section, TRow&& _row)
		{
			
			m_value.*_section.*_row = from<decltype(m_value.*_section.*_row)>(_key_name, _section_name);
		}

		template <class TValue, class T = std::decay_t<TValue>> requires requires { T::from_chars; }
		auto from(std::string_view _key, std::string_view _section) -> decltype(auto)
		{
			char buffer[MAX_PATH]{};
			
			const auto length{ GetPrivateProfileStringA(_section.data(), _key.data(), "", buffer, MAX_PATH, m_path.string().c_str())};

			return T::from_chars({ buffer, length });
		}

		constexpr ini_schema(TValue& _value, std::filesystem::path _path) noexcept : 
			m_value{ _value },
			m_path{ _path } 
		{}

	private:
		TValue& m_value;
		std::filesystem::path m_path;
	};
}

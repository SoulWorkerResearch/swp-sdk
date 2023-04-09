#pragma once

namespace swpsdk::helpers
{
	template <class TPlugin> class memory
	{
	public:
		static auto instance(void) -> TPlugin& { return m_instance; }

	protected:
		constexpr memory(void) noexcept = default;
		constexpr virtual ~memory(void) noexcept = default;

	private:
		static TPlugin m_instance;
	};

	template <class TPlugin>
	TPlugin memory<TPlugin>::m_instance;
};

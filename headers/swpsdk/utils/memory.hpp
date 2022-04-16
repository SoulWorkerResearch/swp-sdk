#pragma once

namespace swpsdk::utils
{
  template <typename TPlugin> class memory
  {
  public:
    static auto instance(void) ->TPlugin& { return m_instance; }

  protected:
    memory(void) noexcept {}
    virtual ~memory(void) noexcept {}

  private:
    static TPlugin m_instance;
  };

  template <typename TPlugin>
  TPlugin memory<TPlugin>::m_instance;
};
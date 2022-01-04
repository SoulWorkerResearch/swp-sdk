#pragma once

namespace sdk::plugin
{
  class callback
  {
  public:
    constexpr virtual auto on_ready(void) const -> void = 0;

  protected:
    callback(void) noexcept {}
    virtual ~callback(void) noexcept {}
  };
};
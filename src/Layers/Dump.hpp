#pragma once

#include "Base.hpp"

namespace Layers {
class Dump : public Layers::Base {
    public:
  void onEvent(Events::Base &event) override;
};
} // namespace Layers

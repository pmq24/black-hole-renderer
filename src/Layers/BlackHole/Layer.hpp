#pragma once

#include "src/Layers/Base.hpp"

namespace Layers {
namespace BlackHole {
class Layer : public Layers::Base {
    public:
  void onEvent(Events::Base &event) override;
};
} // namespace BlackHole
} // namespace Layers

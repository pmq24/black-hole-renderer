#pragma once

#include "src/events.hpp"

namespace Layers {
class Base {
    public:
  virtual void onEvent(Events::Base &event){};
  virtual void onUpdate(float dt){};
  virtual void onRender(){};
};
} // namespace Layers

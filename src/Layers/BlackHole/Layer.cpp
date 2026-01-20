#include "spdlog/spdlog.h"

#include "Layer.hpp"

namespace Layers {
namespace BlackHole {
void Layer::onEvent(Events::Base &event) {
  spdlog::info("Event received in BlackHole layer: {}",
               static_cast<int>(event.type()));
}
} // namespace BlackHole
} // namespace Layers

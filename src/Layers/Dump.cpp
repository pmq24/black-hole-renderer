#include "spdlog/spdlog.h"

#include "Dump.hpp"

namespace Layers {
void Dump::onEvent(Events::Base &event) {
  spdlog::info("Event received in Dump layer: {}",
               static_cast<int>(event.type()));
}
} // namespace Layers

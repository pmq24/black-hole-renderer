#include "Scene.hpp"

namespace Layers {
namespace BlackHole {
Scene::Scene()
  : blackHolePos(0.0f, 0.0f, 0.0f),
    blackHoleUp(0.0f, 1.0f, 0.0f),
    blackHoleAccretionDiskOuterRadius(1.0f),
    camPos(50.0f, 50.0f, 50.0f) {
}
} // namespace BlackHole
} // namespace Layers

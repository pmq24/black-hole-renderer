#pragma once

#include <glm/vec3.hpp>

namespace Layers {
namespace BlackHole {
class Scene {
    public:
  Scene();

    private:
  glm::vec3 blackHolePos;
  glm::vec3 blackHoleUp;
  float     blackHoleAccretionDiskOuterRadius;

  glm::vec3 camPos;
};
} // namespace BlackHole
} // namespace Layers

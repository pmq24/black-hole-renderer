#include "Opengl.hpp"

namespace Rendering {
Shaders::Vert Opengl::loadVertShader(const std::string &name) {
  return Shaders::Vert(this->assetLoader, name);
}

Shaders::Frag Opengl::loadFragShader(const std::string &name) {
  return Shaders::Frag(this->assetLoader, name);
}
} // namespace Rendering

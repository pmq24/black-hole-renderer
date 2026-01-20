#pragma once

#include <memory>
#include <string>

#include <glad/gl.h>

#include "Base.hpp"
#include "src/Rendering/AssetLoader.hpp"

namespace Rendering {
namespace Shaders {
class Vert : public Base {
    public:
  inline Vert(const std::unique_ptr<AssetLoader> &assetLoader,
              const std::string                  &name)
    : Base(assetLoader, name, GL_VERTEX_SHADER){};
};
} // namespace Shaders
} // namespace Rendering

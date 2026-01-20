#pragma once

#include <memory>
#include <string>

#include <glad/gl.h>

#include "src/Rendering/AssetLoader.hpp"

namespace Rendering {
namespace Shaders {
class Base {
    public:
  Base(const std::unique_ptr<AssetLoader> &assetLoader,
       const std::string                  &name,
       GLenum                              shaderType);

    private:
  GLuint      id;
  std::string name;
  std::string src;
};
} // namespace Shaders
} // namespace Rendering

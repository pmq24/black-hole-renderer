#pragma once

#include <memory>

#include "AssetLoader.hpp"
#include "Shaders/Frag.hpp"
#include "Shaders/Vert.hpp"

namespace Rendering {
class Opengl {
    public:
  Shaders::Vert loadVertShader(const std::string &name);
  Shaders::Frag loadFragShader(const std::string &name);

    private:
  std::unique_ptr<AssetLoader> assetLoader;
};
} // namespace Rendering

#pragma once
#include "Base.hpp"
namespace Rendering {
namespace Shaders {
class Frag : public Base {
    public:
  inline Frag(const std::unique_ptr<AssetLoader> &assetLoader,
              const std::string                  &name)
    : Base(assetLoader, name, GL_FRAGMENT_SHADER){};
};
} // namespace Shaders
} // namespace Rendering

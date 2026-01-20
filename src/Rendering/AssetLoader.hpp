#pragma once

#include <string>

namespace Rendering {
class AssetLoader {
    public:
  const std::string loadText(const std::string &assetName);

    private:
  const std::string resolveAssetPath(const std::string &assetName);
};
} // namespace Rendering

#include <fstream>
#include <sstream>

#include "spdlog/spdlog.h"

#include "AssetLoader.hpp"

namespace Rendering {
const std::string AssetLoader::loadText(const std::string &assetName) {
  const std::string filePath = this->resolveAssetPath(assetName);

  std::ifstream file(filePath);
  if (!file.is_open()) {
    spdlog::critical("Failed to open asset file: {}", filePath);
    assert(false);
  }

  std::ostringstream buffer;
  buffer << file.rdbuf();
  return buffer.str();
}

const std::string AssetLoader::resolveAssetPath(const std::string &assetName) {
  return "assets/" + assetName;
}
} // namespace Rendering

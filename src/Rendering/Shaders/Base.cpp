#include "Base.hpp"

#include "spdlog/spdlog.h"

namespace Rendering {
namespace Shaders {
Base::Base(const std::unique_ptr<AssetLoader> &assetLoader,
           const std::string                  &name,
           GLenum                              shaderType) {
  this->id = glCreateShader(shaderType);

  std::string ext = "";
  switch (shaderType) {
    case GL_VERTEX_SHADER: ext = ".vert.glsl"; break;
    case GL_FRAGMENT_SHADER: ext = ".frag.glsl"; break;
  }

  const std::string fileName = name + ext;
  this->src                  = assetLoader->loadText(fileName);
  const char *src_c_str      = this->src.c_str();
  glShaderSource(this->id, 1, &src_c_str, nullptr);
  glCompileShader(this->id);

  GLint status;
  char  buffer[512];
  glGetShaderiv(this->id, GL_COMPILE_STATUS, &status);
  if (status != GL_TRUE) {
    glGetShaderInfoLog(this->id, 512, nullptr, buffer);
    spdlog::critical("assets/{}: compilation failed:\n{}", fileName, buffer);
    assert(false);
  }
}
} // namespace Shaders
} // namespace Rendering

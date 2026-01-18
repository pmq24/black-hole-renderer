#pragma once

#include <string>

#include <glad/gl.h>

namespace Render {
enum class ShaderType { Vert = GL_VERTEX_SHADER, Frag = GL_FRAGMENT_SHADER };

class Shader {
    public:
  Shader(const ShaderType type, const std::string &asset_path);

  inline GLuint get_id() const {
    return this->id;
  }

    private:
  GLuint      id;
  std::string src;
};
} // namespace Render

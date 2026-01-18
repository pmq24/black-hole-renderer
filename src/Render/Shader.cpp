#include <fstream>
#include <sstream>

#include "Shader.hpp"

namespace Render {
Shader::Shader(const ShaderType type, const std::string &asset_path) {
  std::ifstream      src_file("assets/" + asset_path);
  std::ostringstream shader_stream;
  shader_stream << src_file.rdbuf();
  this->src = shader_stream.str();

  this->id              = glCreateShader(static_cast<GLenum>(type));
  const char *src_c_str = this->src.c_str();
  glShaderSource(this->id, 1, &src_c_str, nullptr);
  glCompileShader(this->id);

  GLint status;
  char  buffer[512];
  glGetShaderiv(this->id, GL_COMPILE_STATUS, &status);
  if (status != GL_TRUE) {
    glGetShaderInfoLog(this->id, 512, nullptr, buffer);
    throw std::runtime_error(std::string("Shader compilation failed: ") +
                             buffer);
  }
};
} // namespace Render

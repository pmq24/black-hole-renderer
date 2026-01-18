#include <fstream>
#include <sstream>

#include "Render/Window.hpp"

int main() {
  Render::Window window;

  float vertices[] = {0.0f, 0.5f, 0.5f, -0.5f, -0.5f, -0.5f};

  GLuint vert_buffer;
  glGenBuffers(1, &vert_buffer);
  glBindBuffer(GL_ARRAY_BUFFER, vert_buffer);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

  GLint status;
  char  buffer[512];

  std::ifstream vert_shader_file("assets/triangle.vert.glsl");
  if (!vert_shader_file.is_open()) {
    throw std::runtime_error("Failed to open vertex shader file");
  }
  std::ostringstream vert_shader_stream;
  vert_shader_stream << vert_shader_file.rdbuf();
  std::string vert_shader_src_string = vert_shader_stream.str();
  const char *vert_shader_src        = vert_shader_src_string.c_str();
  GLuint      vert_shader            = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(vert_shader, 1, &vert_shader_src, nullptr);
  glCompileShader(vert_shader);

  glGetShaderiv(vert_shader, GL_COMPILE_STATUS, &status);
  if (status != GL_TRUE) {
    glGetShaderInfoLog(vert_shader, 512, nullptr, buffer);
    throw std::runtime_error(std::string("Vertex shader compilation failed: ") +
                             buffer);
  }

  std::ifstream frag_shader_file("assets/triangle.frag.glsl");
  if (!frag_shader_file.is_open()) {
    throw std::runtime_error("Failed to open fragment shader file");
  }
  std::ostringstream frag_shader_stream;
  frag_shader_stream << frag_shader_file.rdbuf();
  std::string frag_shader_src_string = frag_shader_stream.str();
  const char *frag_shader_src        = frag_shader_src_string.c_str();
  GLuint      frag_shader            = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(frag_shader, 1, &frag_shader_src, nullptr);
  glCompileShader(frag_shader);
  glGetShaderiv(frag_shader, GL_COMPILE_STATUS, &status);
  if (status != GL_TRUE) {
    glGetShaderInfoLog(frag_shader, 512, nullptr, buffer);
    throw std::runtime_error(
      std::string("Fragment shader compilation failed: ") + buffer);
  }

  GLuint shader_program = glCreateProgram();
  glAttachShader(shader_program, vert_shader);
  glAttachShader(shader_program, frag_shader);
  glLinkProgram(shader_program);
  glUseProgram(shader_program);

  GLuint vert_arr;
  glGenVertexArrays(1, &vert_arr);
  glBindVertexArray(vert_arr);

  GLint posAttrib = glGetAttribLocation(shader_program, "position");
  glVertexAttribPointer(posAttrib, 2, GL_FLOAT, GL_FALSE, 0, 0);
  glEnableVertexAttribArray(posAttrib);

  while (!window.should_close()) {
    window.clear();
    glDrawArrays(GL_TRIANGLES, 0, 3);
    window.swap_buffers();
    window.poll_events();
  }
}

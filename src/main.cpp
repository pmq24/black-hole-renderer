#include <fstream>
#include <sstream>

#include "Render/Shader.hpp"
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

  Render::Shader vert_shader(Render::ShaderType::Vert, "triangle.vert.glsl");
  Render::Shader frag_shader(Render::ShaderType::Frag, "triangle.frag.glsl");

  GLuint shader_program = glCreateProgram();
  glAttachShader(shader_program, vert_shader.get_id());
  glAttachShader(shader_program, frag_shader.get_id());
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

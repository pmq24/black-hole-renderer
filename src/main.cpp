#include "App.hpp"

int main() {
  App app;
  app.run();

  // spdlog::info("Starting application...");
  // Render::Window window;
  //
  // float vertices[] = {0.0f, 0.5f, 0.5f, -0.5f, -0.5f, -0.5f};
  //
  // GLuint vert_buffer;
  // glGenBuffers(1, &vert_buffer);
  // glBindBuffer(GL_ARRAY_BUFFER, vert_buffer);
  // glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
  //
  // Render::Shader vert_shader(Render::ShaderType::Vert, "triangle.vert.glsl");
  // Render::Shader frag_shader(Render::ShaderType::Frag, "triangle.frag.glsl");
  //
  // GLuint shader_program = glCreateProgram();
  // glAttachShader(shader_program, vert_shader.get_id());
  // glAttachShader(shader_program, frag_shader.get_id());
  // glLinkProgram(shader_program);
  // glUseProgram(shader_program);
  //
  // GLuint vert_arr;
  // glGenVertexArrays(1, &vert_arr);
  // glBindVertexArray(vert_arr);
  //
  // GLint posAttrib = glGetAttribLocation(shader_program, "position");
  // glVertexAttribPointer(posAttrib, 2, GL_FLOAT, GL_FALSE, 0, 0);
  // glEnableVertexAttribArray(posAttrib);
  //
  // glm::mat4 proj =
  //   glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);
  // glm::mat4 view =
  //   glm::lookAt(glm::vec3(3, 4, 5), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
  // glm::mat4 model = glm::mat4(1.0f);
  // glm::mat4 mvp   = proj * view * model;
  //
  // GLuint mvp_uniform = glGetUniformLocation(shader_program, "mvp");
  // glUniformMatrix4fv(mvp_uniform, 1, GL_FALSE, &mvp[0][0]);
  //
  // glm::vec3 camera_pos = glm::vec3(5, 5, 50);
  // GLuint    camera_pos_uniform =
  //   glGetUniformLocation(shader_program, "camera_pos");
  // glUniform3fv(camera_pos_uniform, 1, &camera_pos[0]);
  //
  // glm::vec2 screen_res = glm::vec2(800, 600);
  // GLuint    screen_res_uniform =
  //   glGetUniformLocation(shader_program, "screen_res");
  // glUniform2fv(screen_res_uniform, 1, &screen_res[0]);
  //
  // while (!window.should_close()) {
  //   window.clear();
  //   glDrawArrays(GL_TRIANGLES, 0, 3);
  //   window.swap_buffers();
  //   window.poll_events();
  // }
}

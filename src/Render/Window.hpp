#pragma once

// Loading glad and GLFW: glad must be included before GLFW,
// therefore a space is added inbetween to prevent clangd's re-ordereing
#include <glad/gl.h>

#include "GLFW/glfw3.h"

namespace Render {
class Window {
    public:
  Window();
  ~Window();

  inline int32_t should_close() const {
    return glfwWindowShouldClose(this->glfwWindow);
  }

  inline void clear() const {
    glClear(GL_COLOR_BUFFER_BIT);
  }

  inline void swap_buffers() {
    glfwSwapBuffers(this->glfwWindow);
  }

  inline void poll_events() const {
    glfwPollEvents();
  }

    private:
  GLFWwindow *glfwWindow;
  uint32_t    openGlVersion;
};
} // namespace Render

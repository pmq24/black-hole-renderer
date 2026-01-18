#include <stdexcept>

#include "Window.hpp"

namespace Render {
Window::Window() {
  auto glfw = glfwInit();
  if (!glfw) {
    throw std::runtime_error("Failed to initialize GLFW");
    glfwTerminate();
  }

  this->glfwWindow =
    glfwCreateWindow(800, 600, "OpenGL Window", nullptr, nullptr);
  if (!this->glfwWindow) {
    throw std::runtime_error("Failed to create GLFW window");
    glfwTerminate();
  }

  glfwMakeContextCurrent(this->glfwWindow);

  this->openGlVersion = gladLoadGL(glfwGetProcAddress);
  if (this->openGlVersion == 0) {
    throw std::runtime_error("Failed to initialize OpenGL context");
    glfwDestroyWindow(this->glfwWindow);
    glfwTerminate();
  }

  glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
}

Window::~Window() {
  glfwDestroyWindow(this->glfwWindow);
  glfwTerminate();
}
} // namespace Render

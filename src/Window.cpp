#include <spdlog/spdlog.h>

#include "Window.hpp"

Window::Window() {
  this->glfwWindow =
    glfwCreateWindow(800, 600, "OpenGL Window", nullptr, nullptr);
  if (!this->glfwWindow) {
    spdlog::critical("Failed to create GLFW window");
  }

  glfwMakeContextCurrent(this->glfwWindow);

  this->openGlVersion = gladLoadGL(glfwGetProcAddress);
  if (this->openGlVersion == 0) {
    spdlog::critical("glad: Failed to initialize OpenGL context");
  }

  glClearColor(0.1f, 0.1f, 0.1f, 1.0f);

  glfwSetWindowUserPointer(this->glfwWindow, this);

  glfwSetWindowCloseCallback(this->glfwWindow, [](GLFWwindow *window) {
    Window *w = static_cast<Window *>(glfwGetWindowUserPointer(window));
    auto    e = Events::Window::Close();
    w->eventCallback(e);
  });

  glfwSetWindowSizeCallback(
    this->glfwWindow, [](GLFWwindow *window, int width, int height) {
      Window *w = static_cast<Window *>(glfwGetWindowUserPointer(window));
      auto    e = Events::Window::Resize(width, height);
      w->eventCallback(e);
    });
}

Window::~Window() {
  glfwDestroyWindow(this->glfwWindow);
}

bool Window::shouldClose() {
  return glfwWindowShouldClose(this->glfwWindow);
}

void Window::clear() {
  glClear(GL_COLOR_BUFFER_BIT);
}

void Window::swapBuffers() {
  glfwSwapBuffers(this->glfwWindow);
}

void Window::pollEvents() {
  glfwPollEvents();
}

void Window::setEventCallback(const EventCallbackFn &callback) {
  this->eventCallback = callback;
}

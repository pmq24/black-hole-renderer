#include <spdlog/spdlog.h>

#include <glad/gl.h>
// glad must be included before GLFW, adding a space to prevent clangd's
// re-ordering
#include <GLFW/glfw3.h>

#include "App.hpp"

App::App() : isRunning(false), window(nullptr) {
  bool glfw = glfwInit();
  if (!glfw) {
    spdlog::critical("Failed to initialize GLFW");
  }

  this->window = std::make_unique<Window>();
  this->window->setEventCallback(
    [this](Events::Base &event) { this->onEvent(event); });
}

App::~App() {
  glfwTerminate();
}

void App::run() {
  this->isRunning = true;

  while (this->isRunning) {
    if (this->window->shouldClose()) {
      this->stop();
    }

    this->window->clear();
    this->window->swapBuffers();
    this->window->pollEvents();
  }
}

void App::stop() {
  this->isRunning = false;
}

void App::onEvent(Events::Base &event) {
  spdlog::info("Event received: {}", static_cast<int>(event.type()));
}

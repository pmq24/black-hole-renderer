#include <spdlog/spdlog.h>

#include <glad/gl.h>
// glad must be included before GLFW, adding a space to prevent clangd's
// re-ordering
#include <GLFW/glfw3.h>

#include "App.hpp"

App::App() : window(nullptr) {
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

  auto lastTime    = std::chrono::high_resolution_clock::now();
  auto currentTime = lastTime;

  while (this->isRunning) {
    if (this->window->shouldClose()) {
      this->stop();
    }

    this->window->clear();
    this->window->pollEvents();

    currentTime = std::chrono::high_resolution_clock::now();
    auto dt     = std::chrono::duration<float, std::chrono::seconds::period>(
                currentTime - lastTime)
                .count();
    lastTime = currentTime;

    for (auto &layer : this->layers) {
      layer->onUpdate(dt);
    }

    for (auto &layer : this->layers) {
      layer->onRender();
    }

    this->window->swapBuffers();
  }
}

void App::stop() {
  this->isRunning = false;
}

void App::onEvent(Events::Base &event) {
  for (auto layer = this->layers.rbegin(); layer != this->layers.rend();
       ++layer) {
    (*layer)->onEvent(event);
  }
}

void App::pushLayer(std::unique_ptr<Layers::Base> layer) {
  this->layers.push_back(std::move(layer));
}

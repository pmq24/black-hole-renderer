#pragma once

#include <functional>
#include <glad/gl.h>
// glad must be included before GLFW, therefore a space is added inbetween to
// prevent clangd's re-ordereing
#include "GLFW/glfw3.h"

#include "events.hpp"

class Window {
  typedef std::function<void(Events::Base &)> EventCallbackFn;

    public:
  Window();
  ~Window();

  bool shouldClose();
  void clear();
  void swapBuffers();
  void pollEvents();

  void setEventCallback(const EventCallbackFn &callback);

    private:
  GLFWwindow     *glfwWindow;
  uint32_t        openGlVersion;
  EventCallbackFn eventCallback;
};

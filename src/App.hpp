#pragma once

#include <memory>

#include "Window.hpp"

class App {
    public:
  App();
  ~App();

  void run();
  void stop();

  void onEvent(Events::Base &event);

    private:
  bool                    isRunning;
  std::unique_ptr<Window> window;
};

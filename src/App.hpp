#pragma once

#include <memory>
#include <vector>

#include "Layers/Base.hpp"
#include "Window.hpp"

class App {
    public:
  App();
  ~App();

  void run();
  void stop();

  void onEvent(Events::Base &event);

  void pushLayer(std::unique_ptr<Layers::Base> layer);

    private:
  std::unique_ptr<Window>                    window;
  std::vector<std::unique_ptr<Layers::Base>> layers;
  bool                                       isRunning;
};

#include "Render/Window.hpp"

int main() {
  Render::Window window;

  while (!window.should_close()) {
    window.clear();
    window.swap_buffers();
    window.poll_events();
  }
}

#pragma once

namespace Events {
enum class Type {
  WindowClose,
  WindowResize,
};

class Base {
    public:
  virtual Type type() const = 0;
};

namespace Window {
class Close : public Base {
    public:
  Type type() const override {
    return Type::WindowClose;
  }
};

class Resize : public Base {
    public:
  Resize(int w, int h) : w(w), h(h) {
  }
  Type type() const override {
    return Type::WindowResize;
  }

    public:
  const int w;
  const int h;
};
} // namespace Window
} // namespace Events

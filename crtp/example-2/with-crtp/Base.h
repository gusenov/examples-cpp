#ifndef BASE_H
#define BASE_H

template <class Self>
struct Base
{
  Self& self() { return static_cast<Self&>(*this); }

  // Base будет вызывать методы Derived, если они там переопределены.

  int algorithm(int x)
  {
    self().prologue();
    if (x > 42)
      x = self().downsize(x);
    x = self().crunch(x);
    self().epilogue();
    return x;
  }

  void prologue()
  {}

  int downsize(int x)
  { return x % 42; }

  int crunch(int x)
  { return -x; }

  void epilogue()
  {}
};

#endif

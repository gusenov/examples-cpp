#ifndef BASE_H
#define BASE_H

struct Base
{
  // Внутри вызова d.algorithm будут вызываться функции из Base.
  // Несмотря на то, что в Derived перезаписываются downsize() и epilogue()
  // будут вызваны их версии из Base.
  // Это происходит из-за статической природы системы типов C++.
  int algorithm(int x)
  {
    prologue();
    if (x > 42)
      x = downsize(x);
    x = crunch(x);
    epilogue();
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

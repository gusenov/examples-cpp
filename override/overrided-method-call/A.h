#ifndef A_H
#define A_H

struct A {
  virtual ~A() = default;

  void bar() {
    // do something and then call foo (possibly) in the derived class:
    foo();
  }

  // possibly non pure virtual
  virtual void foo() const = 0;
};

#endif

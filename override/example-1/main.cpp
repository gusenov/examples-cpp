#include "B.h"

int main(int argc, char* argv[]) {

  B *b = new B();

  b->foo();
  // foo() from B

  b->bar();
  // bar() from B

  // delete b;
  // ~B() from B
  // ~A() from A


  A *a = b;

  a->foo();
  // foo() from A

  a->bar();
  // bar() from B

  delete a;
  // ~B() from B
  // ~A() from A


  return 0;
}

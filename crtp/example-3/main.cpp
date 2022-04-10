#include "C.h"

int main(int argc, char* argv[]) {

  C *c = new C();
  c->foo();
  // foo() from C

  // Проблема:
  B<C> *bc = c;
  bc->foo();
  // do something

  A<C> *ac = c;
  ac->foo();
  // foo() from C

  delete c;

  return 0;
}

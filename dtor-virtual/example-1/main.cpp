#include "C.h"

int main(int argc, char* argv[]) {

  C *c = new C();
  // delete c;
  // ~C()
  // ~A()

  B *b = c;
  // delete b;
  // ~C()
  // ~A()

  A *a = b;
  delete a;
  // ~C()
  // ~A()

  return 0;

}

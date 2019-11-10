#include "C.h"

int main(int argc, char* argv[]) {
  A *a = NULL;

  B *b = new B();
  b->bar();
  // do something

  a = b;
  a->bar();
  // do something

  C *c = new C();
  c->bar();
  // do something else

  B *b_ = c;
  b_->bar();
  // do something else

  a = c;
  a->bar();
  // do something else

  delete b;
  delete c;

  return 0;
}

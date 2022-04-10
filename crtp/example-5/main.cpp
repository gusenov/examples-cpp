#include "Base.h"
#include "Overriding.h"
#include "NonOverriding.h"

template<typename Derived>
void f(/*const*/ Base<Derived>& base)
{
    base.f();    // Base::f
    base.pure(); // Base::pure, which eventually calls Derived::pure

    // Derived::f if an overriding method exists.
    // Base::f otherwise.
    static_cast</*const*/ Derived&>(base).f();
}

int main(int argc, char* argv[]) {
  std::cout << "//---------------------------------------------------------------------" << std::endl;

  Base<Overriding> bo;
  bo.f();
  // Basic case
  bo.pure();
  // pure() from Overriding

  f(bo);
  // Basic case
  // pure() from Overriding
  // Special case

  std::cout << "//---------------------------------------------------------------------" << std::endl;

  Overriding o;
  o.f();
  // Special case
  o.pure();
  // pure() from Overriding

  f(o);
  // Basic case
  // pure() from Overriding
  // Special case

  std::cout << "//---------------------------------------------------------------------" << std::endl;

  NonOverriding no;
  no.f();
  // Basic case
  no.pure();
  // pure() from NonOverriding

  f(no);
  // Basic case
  // pure() from NonOverriding
  // Basic case

  std::cout << "//---------------------------------------------------------------------" << std::endl;

  Base<NonOverriding> bno;
  bno.f();
  // Basic case
  bno.pure();
  // pure() from NonOverriding

  f(bno);
  // Basic case
  // pure() from NonOverriding
  // Basic case

  std::cout << "//---------------------------------------------------------------------" << std::endl;

  return 0;
}

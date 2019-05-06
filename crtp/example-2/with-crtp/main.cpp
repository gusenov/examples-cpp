#include "Derived.h"
#include <vector>

// Ближе к runtime-полиморфизму и предлагает лучший type safety:
template <class T>
int foo(Base<T> &actor)
{
  return actor.algorithm(314);
}

// Более duck-typing based:
// https://ru.wikipedia.org/wiki/Утиная_типизация
template <class T>
int bar(T &actor)
{
  return actor.algorithm(314);
}

int main(int argc, char* argv[]) {

  Derived d;
  std::cout << d.algorithm(420) << std::endl;
  // OUTPUT:
  // We're done!
  // -26

  std::cout << foo(d) << std::endl;
  // We're done!
  // -39

  std::cout << bar(d) << std::endl;
  // We're done!
  // -39

  std::vector<Base<Derived>> v;
  v.push_back(d);

  return 0;
}

#include <iostream>
#include <cstdlib>

template <typename ... Ts>
auto echo(Ts ... ts) {
  (std::cout << ... << ts);
}

int main(int argc, char* argv[]) {
  echo("Hello", ",", " ", "World", "!", "\n");
  return EXIT_SUCCESS;
}

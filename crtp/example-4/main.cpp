#include "level2_impl.h"
#include <iostream>

struct final : public level2_impl<final>
{
    int foo = 1;
    double bar = 2.0;
};

int main(int argc, char* argv[]) {

  final f{};
  std::cout<< f.only_for_level1_and_derived() <<std::endl;   //prints variable foo = 1
  std::cout<< f.only_for_level2_and_derived() <<std::endl;   //prints variable bar = 2.0


  return 0;
}

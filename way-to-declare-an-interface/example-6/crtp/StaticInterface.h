// Curiously Recurring Template Pattern (CRTP):

#include "enable_down_cast.h"

// Статический интерфейс:

template<typename Impl>
class StaticInterface :
  // enable static polymorphism
  public enable_down_cast<Impl>
{

  private:

    // dependent name now in scope
    using enable_down_cast<Impl>::self;

  public:

    // interface
    void fun() { self()->do_fun(); }

  protected:

    // disable deletion of Derived* through Base*
    // enable deletion of Base* through Derived*
    ~StaticInterface() = default; // C++11 only, use ~IFooInterface() {} in C++98/03

};

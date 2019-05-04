// Curiously Recurring Template Pattern (CRTP):

#include "StaticInterface.h"

// Имплементация производится от интерфейса и в качестве параметра передаётся
// сам класса имплементации:

class StaticImplementation:
  public StaticInterface< StaticImplementation >
{

  private:

    // implementation
    friend class StaticInterface< StaticImplementation > ;
    void do_fun() { /* your implementation here */ }

};

// Можно иметь множество имплементаций одного и того же интерфейса, но нужно
// знать на этапе компиляции какая имплементация вызывается.

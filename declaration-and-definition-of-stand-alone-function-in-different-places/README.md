Функция ```foo()``` объявлена в файле [b.h](b.h):

```cpp
void foo();
```

А определена в файле [a.cpp](a.cpp) без инклуда [b.h](b.h):

```cpp
#include <iostream>

void foo() {
  std::cout << "foo" << std::endl;
  return;
}
```

Используется в [main.cpp](main.cpp):

```cpp
#include "b.h"

int main(int argc, char* argv[]) {
  foo();
  return 0;
}
```

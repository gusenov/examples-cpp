#include "SomeClassB.h"
// При подключении SomeClassB.h в исходный файл этот кодовый файл не будет
// автоматически содержать весь код из SomeClassA.h, Flavor.h и Toppings.h
// и компилироваться с ним. Можно подключить их при необходимости, но
// автоматически они не будут подключаться.

// В исходном файле всё равно нужно подключить заголовочные файлы т.к.
// с ними придётся работать в дефинициях функций-членов SomeClassB.

#include "SomeClassA.h"  // class
#include "Flavor.h"      // scoped enum (enum class)
#include "Toppings.h"    // un-scoped enum

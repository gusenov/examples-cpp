Функция:

```cpp
void foo() {
  return;
}
```

определена в файлах [a.cpp](a.cpp) и [b.cpp](b.cpp), что приводит к ошибке:

```
/tmp/ccvV3l7z.o: In function `foo()':
b.cpp:(.text+0x0): multiple definition of `foo()'
/tmp/ccph9CpZ.o:a.cpp:(.text+0x0): first defined here
collect2: error: ld returned 1 exit status
```

Переменная:

```cpp
int b = 20;
```

определена в файлах [a.cpp](a.cpp) и [b.cpp](b.cpp), что приводит к ошибке:

```
/tmp/ccCa42d5.o:(.data+0x0): multiple definition of `b'
/tmp/cc2G6I5Y.o:(.data+0x4): first defined here
collect2: error: ld returned 1 exit status
```

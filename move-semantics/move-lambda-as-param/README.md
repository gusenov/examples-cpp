- C++ не может различить какую функцию ```Foo(std::function<void()>)``` или
  - [```Foo(std::function<void()> const&)``` вызвать с аргументом ```[](){}```](test1.h)
  - [```Foo(std::function<void()>&&)``` вызвать с аргументом ```[](){}```](test9.h)
  - [```Foo(std::function<void()>&&)``` вызвать с аргументом auto-переменной в которой ```[](){}```](test8.h)


- [С аргументом ```[](){}``` вызывается ```Foo(std::function<void()>&&)```, а не ```Foo(std::function<void()> const&)```](test2.h)
- [```auto```-переменой, которой была присвоена лямбда нельзя присвоить другое значение и с ней вызывается функция ```Foo(std::function<void()>&&)```, а не ```Foo(std::function<void()> const&)```](test3.h)


- [Переменная функтора по значению передается в ```Foo(Bar const&)```, а не в ```Foo(Bar&&)``` потому что она L-value](test5.h)
- [Нельзя вызвать ```Foo(std::function<void()>&&)``` с переменной типа ```std::function<void()>``` потому что она L-value, а нужно R-value](test11.h)
- [С ```std::function<void()>```-переменой, которой была присвоена лямбда вызывается функция ```Foo(std::function<void()> const&)```, а не ```Foo(std::function<void()>&&)``` потому что это L-value](test10.h)


- [Анонимный объект функтора по значению передается в ```Foo(Bar&&)```, а не в ```Foo(Bar const&)``` потому что это R-value](test6.h)
- [Переменную функтора по значению нельзя передать в ```Foo(Bar&&)```, но через ```std::move``` можно преобразовать его в R-value](test7.h)


- [Объект захваченный в ```std::function<void()>``` не копируется при передаче wrapper'а в ```Foo(std::function<void()>)```](test4.h)

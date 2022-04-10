#ifndef TYPE2TYPE_H
#define TYPE2TYPE_H

// Шаблонная структура, которая помогает компилятору выбрать имплементацию
// foo() посредством перегрузки:

template< typename T > struct Type2Type {
  typedef T OriginalType;
};

#endif

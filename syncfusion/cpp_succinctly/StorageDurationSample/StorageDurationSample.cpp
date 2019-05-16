#include <iostream>
#include <ostream>
#include <sstream>
#include <thread>
#include <memory>
#include <cstddef>
#include "SomeClass.h"
#include "../pchar.h"

using namespace std;

struct SomeStruct { int Value; };

namespace Value {
  // Visual C++ не поддерживает thread_local начиная с VS 2012 RS. Можно
  // имитировать thread_local с помощью _declspec(thread), но в таком случае
  // мы не можем иметь такие вещи как классы с функциями (включая конструкторы
  // и деструкторы):

  // _declspec(thread) - Microsoft specific extension
  // http://msdn.microsoft.com/en-us/library/9w1sdazb.aspx
  // _declspec(thread) SomeStruct ThreadLocalSomeStruct = {};

  // __thread - GCC-specific extension
  // http://gcc.gnu.org/onlinedocs/gcc-4.7.1/gcc/Thread_002dLocal.html#Thread_002dLocal
  __thread SomeStruct ThreadLocalSomeStruct = {};

  // g_staticSomeClass имеет static duration. Эта переменная существует до тех
  // пор пока программа не закончится или переменной не будет присвоено другое
  // значение. Даже если опустить ключевое слово static, в этом случае
  // переменная всё равно будет static т.к. это не локальная переменная, не
  // динамическая (dynamic) и не thread local переменная.
  static SomeClass g_staticSomeClass = SomeClass(20, L"g_staticSomeClass");
  // ВЫВОД № 2:
  // Creating SomeClass instance.
  // StringId: g_staticSomeClass.
  // Address is: '0x013f8554'.
  // Value is '20'.
  // Thread id: '3660'.
}

// Функция создает экземпляр SomeClass и потом изменяет значение:
void ChangeAndPrintValue(int value) {
  // Создание строкового идентификатора:
  wstringstream wsStr(L"");
  wsStr << L"ChangeAndPrintValue thread id: '" << this_thread::get_id() << L"'";

  // Создание экземпляра SomeClass для демонстрации function-level block scope:
  SomeClass sc(value, wsStr.str().c_str());

  // Демонстрация _declspec(thread):
  wcout << L"Old value is " << Value::ThreadLocalSomeStruct.Value
        << L". Thread id: '" << this_thread::get_id() << L"'." << endl;
  Value::ThreadLocalSomeStruct.Value = value;
  wcout << L"New value is " << Value::ThreadLocalSomeStruct.Value
        << L". Thread id: '" << this_thread::get_id() << L"'." << endl;
}

void LocalStatic(int value) {
  static SomeClass sc(value, L"LocalStatic sc");

  // Если нужно переинициализировать sc каждый раз, то нужно раскомментировать
  // следующую строку:
  // sc = SomeClass(value, L"LocalStatic reinitialize");
  // Хотя это и противоречит цели наличия локальной статики.
  // Но можно сделать что-то подобное, если нужно переинициализировать
  // переменную только при определенных обстоятельствах. В таком случае есть
  // смысл иметь тут локальную статику.

  wcout << L"Local Static sc value: '" << sc.GetValue() << L"'."
        << endl << endl;
}

int _pmain(int /*argc*/, _pchar* /*argv*/[]) {
  // Automatic storage; разрушится при завершении функции:
  SomeClass sc1(1, L"_pmain sc1");
  // ВЫВОД № 3:
  // Creating SomeClass instance.
  // StringId: _pmain sc1.
  // Address is: '0x007bfe98'.
  // Value is '1'.
  // Thread id: '3660'.

  wcout << L"sc1 value: '" << sc1.GetValue() << L"'." << endl << endl;
  // ВЫВОД № 4:
  // sc1 value: '1'.

  { // Фигурные скобки создают новый блок. Это означает, что sc2 "живёт" только
    // только достижения закрывающей скобки потому что sc2 тоже
    // automatic storage:
    SomeClass sc2(2, L"_pmain sc2");
    // ВЫВОД № 5:
    // Creating SomeClass instance.
    // StringId: _pmain sc2.
    // Address is: '0x007bfe70'.
    // Value is '2'.
    // Thread id: '3660'.

    wcout << L"sc2 value: '" << sc2.GetValue() << L"'." << endl << endl;
    // ВЫВОД № 6:
    // sc2 value: '2'.
  }
  // ВЫВОД № 7:
  // Destroying SomeClass instance.
  // StringId: _pmain sc2.
  // Address is: '0x007bfe70'.
  // Thread id: '3660'.

  LocalStatic(1000);
  // ВЫВОД № 8:
  // Creating SomeClass instance.
  // StringId: LocalStatic sc.
  // Address is: '0x013f8578'.
  // Value is '1000'.
  // Thread id: '3660'.
  //
  // Local Static sc value: '1000'.

  LocalStatic(5000);
  // Локальная статика в функции LocalStatic не будет переинициализирована
  // значением 5000!

  // ВЫВОД № 9:
  // Local Static sc value: '1000'.

  // Чтобы продемонстрировать _declspec(thread) мы изменяем в текущем потоке
  // значение Value::ThreadLocalSomeStruct на 20 с его изначального значения
  // по умолчанию 0:
  ChangeAndPrintValue(20);
  // ВЫВОД № 10:
  // Creating SomeClass instance.
  // StringId: ChangeAndPrintValue thread id: '3660'.
  // Address is: '0x007bfbf4'.
  // Value is '20'.
  // Thread id: '3660'.
  //
  // Old value is 0. Thread id: '3660'.
  // New value is 20. Thread id: '3660'.
  //
  // Destroying SomeClass instance.
  // StringId: ChangeAndPrintValue thread id: '3660'.
  // Address is: '0x007bfbf4'.
  // Thread id: '3660'.

  // Создание нового потока (который автоматически стартует) и изменяет значение
  // Value::ThreadLocalSomeStruct на 40. Если бы она была расшарена между
  // потоками, то тогда она бы имела значение 20 от предыдущего запуска
  // ChangeAndPrintValue. Но это не так. Вместо этого её значением по умолчанию
  // будет 0, чего мы и ожидаем, т.к. это новый поток.
  auto thr = thread(ChangeAndPrintValue, 40);
  // ВЫВОД № 11:
  // Creating SomeClass instance.
  // StringId: ChangeAndPrintValue thread id: '5796'.
  // Address is: '0x0045faa8'.
  // Value is '40'.
  // Thread id: '5796'.
  //
  // Old value is 0. Thread id: '5796'.
  // New value is 40. Thread id: '5796'.
  //
  // Destroying SomeClass instance.
  // StringId: ChangeAndPrintValue thread id: '5796'.
  // Address is: '0x0045faa8'.
  // Thread id: '5796'.

  // Ожидание завершения выполнения созданного потока. Вызывать join из UI
  // потока - плохая идея, т.к. это заблокирует текущий поток до тех пор пока
  // не заверится поток для которого вызван join. При программировании для WinRT
  // лучше использовать PPLTasks API.
  thr.join();


  // Dynamic storage.
  // WARNING: Это 'naked' указатель, их использование является плохой практикой.
  // Он здесь только для того чтобы продемонстрировать пример dynamic storage.
  // Обычно следует использовать std::unique_ptr или std::shared_ptr чтобы
  // обернуть аллоцированную память с помощью ключевых слов 'new' или 'new[]'.
  SomeClass* p_dsc = new SomeClass(1000, L"_pmain p_dsc");
  // ВЫВОД № 12:
  // Creating SomeClass instance.
  // StringId: _pmain p_dsc.
  // Address is: '0x009fbcc0'.
  // Value is '1000'.
  // Thread id: '3660'.

  const std::size_t arrIntSize = 5;

  // Dynamic storage array. Тот же самый WARNING.
  int* p_arrInt = new int[arrIntSize];
  // Нет способов узнать какое количество элементов содержит arrInt, кроме как
  // вручную отслеживать это. Также нужно иметь ввиду, что значения в arrInt
  // не проинициализированы (т.е. это не arrIntSize нулей, это arrIntSize
  // произвольных целочисленных значений).

  for (int i = 0; i < arrIntSize; i++) {
    wcout << L"i: '" << i << L"'. p_arrInt[i] = '" << p_arrInt[i] << L"'."
          << endl;
    // Присвоить значение i этому индексу:
    p_arrInt[i] = i;
  }
  wcout << endl;
  // ВЫВОД № 13:
  // i: '0'. p_arrInt[i] = '-842150451'.
  // i: '1'. p_arrInt[i] = '-842150451'.
  // i: '2'. p_arrInt[i] = '-842150451'.
  // i: '3'. p_arrInt[i] = '-842150451'.
  // i: '4'. p_arrInt[i] = '-842150451'.

  // Если нужно обнулить динамический массив, то можно сделать следующее:
  // uninitialized_fill_n(p_arrInt, arrIntSize, 0);

  for (int i = 0; i < arrIntSize; i++) {
    wcout << L"i: '" << i << L"'. p_arrInt[i] = '" << p_arrInt[i] << L"'."
          << endl;
  }
  // ВЫВОД № 14:
  // i: '0'. p_arrInt[i] = '0'.
  // i: '1'. p_arrInt[i] = '1'.
  // i: '2'. p_arrInt[i] = '2'.
  // i: '3'. p_arrInt[i] = '3'.
  // i: '4'. p_arrInt[i] = '4'.

  // Если забыть это, то будет утечка памяти:
  delete p_dsc;
  // ВЫВОД № 15:
  // Destroying SomeClass instance.
  // StringId: _pmain p_dsc.
  // Address is: '0x009fbcc0'.
  // Thread id: '3660'.

  // Двойной delete приведет к сбою программы:
  // delete p_dsc;

  // Если сделать это, то будет ошибка, которая может привести к сбою программу,
  // потому что dsc - это не массив, и поэтому здесь не должно использоваться
  // удаление массива, т.е. delete[]:
  // delete[] p_dsc;

  // После удаления указателя всегда нужно присваивать ему nullptr чтобы
  // предотвратить случайное его использовать (т.к. неизвестно на что он
  // указывает):
  p_dsc = nullptr;

  // Если забыть это, то будет утечка памяти:
  delete[] p_arrInt;
  // Если использовать 'delete'
  // вместо 'delete[]' могут произойти неопределенные плохие вещи. Некоторые
  // имплементации могут этого не заметить, другие приведут к сбою программу
  // или вообще неизвестно к чему.

  p_arrInt = nullptr;

  wcout << L"Ending program." << endl;
  // ВЫВОД № 16:
  // Ending program.
  //
  // Destroying SomeClass instance.
  // StringId: _pmain sc1.
  // Address is: '0x007bfe98'.
  // Thread id: '3660'.
  //
  // Destroying SomeClass instance.
  // StringId: LocalStatic sc.
  // Address is: '0x013f8578'.
  // Thread id: '3660'.
  //
  // Destroying SomeClass instance.
  // StringId: g_staticSomeClass.
  // Address is: '0x013f8554'.
  // Thread id: '3660'.
  //
  // Destroying SomeClass instance.
  // StringId: s_someClass.
  // Address is: '0x009fade8'.
  // Thread id: '3660'.

  return 0;
}

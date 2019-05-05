#pragma once

// Если вы подключаете заголовочный файл A.h в исходный файл и потом
// подключаете другой заголовочный файл у которого есть A.h, то директива
// #pragma once подскажет препроцессору не подключать A.h снова.
// Это предотвращает препроцессор от вечного перехода между двумя
// заголовочными файлами, которые подключают друг друга.
// Также это защищает от ошибок компиляции. Если A.h подключен множество раз,
// компилятор потерпит неудачу когда доберется до дефиниции типа во втором
// включении A.h.

// Даже с этой директивой компилятор вынужден подключать и парсить каждый
// заголовочный файл для каждого исходного файла, который подключает его.
// Чем больше вещей кладется в заголовочный файл, тем больше времени нужно на
// сборку каждого исходного файла.

namespace Inventory {

  // Декларация VehicleCondition должна предшествовать дефиниции Vehicle.
  // Чтобы отвести достаточно пространства для экземпляров Vehicle, компилятор
  // должен знать как много места занимает каждый член данных Vehicle.
  // Для этого можно либо подключить соответствующий заголовочный файл, либо
  // использовать forward-декларацию. Если декларация VehicleCondition идёт после
  // дефиниции Vehicle, то компилятор откажется компилировать код т.к. он не
  // знает насколько большой VehicleCondition или даже какого он типа данных.
  // Простой декларации достаточно, чтобы сказать компилятору, что такое
  // VehicleCondition (enum class) и насколько оно большое. Enum классы по
  // умолчанию используют int в качестве поля, если не указано другое.
  // Если мы оставим это поле пустым, но потом где-нибудь скажем использовать
  // short или long или другой тип, тогда компилятор сгенерирует другое
  // сообщение об ошибке говорящее о множестве конфликтующих деклараций.

  // Forward-декларация:
  enum class VehicleCondition;
  // Можно либо использовать эту декларацию, либо подключить заголовочный файл
  // VehicleCondition.h.

  // Дефиниция класса Vehicle:
  class Vehicle {
    // Дефиниция включает декларацию членов (функций и переменных):
    public:

      // Тут не дефенируются члены функции:
      Vehicle(VehicleCondition condition, double pricePaid);
      virtual ~Vehicle(void);
      void SetVehicleCondition(VehicleCondition condition);

      // Эти функции-члены декларируются и дефенируются:
      VehicleCondition GetVehicleCondition(void) { return m_condition; }
      double GetBasis(void) { return m_basis; }
      // Такая комбинация декларации и дефиниции называется
      // inline member function. Это похоже на написание методов в C#, но делать
      // так за некоторым исключением не стоит. Компилятор при билде C++ проекта
      // проходит через каждый исходный файл только один раз. Компилятор может
      // много раз просматривать один файл оптимизируя его, но после того как он
      // закончит, он больше не возвращается к этому файлу. Для контраста,
      // компилятор возвращается к заголовочному файлу всякий раз, когда он
      // подключается в другой файл, независимо от того является ли этот файл
      // исходным файлом или заголовочным файлом. Т.е. компилятор может много
      // раз обращаться к заголовочному файлу в процессе сборки.

      // При inline-дефиниции функции-члена в заголовочном файле, компилятор
      // C++ может сделать данный код inline-овым в любом исходном файле в
      // котором используется данная функция. Это обычно приводит к ускорению
      // выполнения программы потому что вместо вызова функции программа просто
      // выполняет код на месте. В случаях когда просто получается значение
      // переменной-члена, inline-дефиниции могут улучшить скорость, особенно
      // если код выполняется в цикле.

      // Не стоит делать всё inline. Это замедлит время компиляции и ухудшит
      // продуктивность. Inline-вещи: простые геттеры и сеттеры для
      // переменных-членов. 

      // Область видимости (scope) сохраняется компилятором поэтому можно
      // не беспокоиться о коллизиях имён между определенными переменными в
      // inline-функции и в функции, где она используется.

    private:
      VehicleCondition m_condition;
      double           m_basis;
  };
}

// Альтернативный способ дефиниции inline функций-членов:

/*
namespace Inventory {
  enum class VehicleCondition;

  // Чистая дефиниция класса без дефиниций функций-членов, но всё равно с
  // inline функциями-членами:
  class Vehicle {
    public:
      Vehicle(VehicleCondition condition, double pricePaid);
      ~Vehicle(void);
      void SetVehicleCondition(VehicleCondition condition);

      // Перед декларациями функций в классе стоит ключевое слово inline:
      inline VehicleCondition GetVehicleCondition(void);
      inline double GetBasis(void);
      // Если убрать inline, то будут ошибки линкера:

      // Vehicle.obj
      // error LNK2005: "public: enum Inventory::VehicleCondition __thiscall
      // Inventory::Vehicle::GetVehicleCondition(void)" (?
      // GetVehicleCondition@Vehicle@Inventory@@QAE?AW4VehicleCondition@2@XZ)
      // already defined in Main.obj

      // SimpleClassExample.exe
      // error LNK1169: one or more multiply defined symbols found

      // Линкер не знает какие имена у переменных и функций в исходном файле.
      // Он только знает, что компилятор преобразовал эти имена так чтобы они
      // были уникальными. Сюда входят перегруженные методы, которые должны
      // иметь уникальные имена на стадии линковки, чтобы линкер мог соединить
      // вызов перегруженной функции-члена с корректной версией этой функции.

      // Ошибки говорят, что Inventory::Vehicle::GetVehicleCondition(void)
      // дефинирована больше одного раза. Мы знаем, что мы дефинировали её
      // один раз в заголовочном файле. Но мы подключаем заголовочный файл
      // в Vehicle.cpp и в Main.cpp. Т.к. мы не добавили inline, то компилятор
      // не сделал код inline-овым. Вместо этого код компилируется как
      // функция и в Main.cpp и в Vehicle.cpp.

      // Компилятор обрабатывает каждый исходный файл как отдельную единицу
      // компиляции. Компилятор получает код после препроцессора. Только когда
      // линкер получает скомпилированный код и пытается сопоставить всё вместе
      // процесс сборки завершается неудачно потому что есть другая версия
      // функции.

    private:
      VehicleCondition m_condition;
      double           m_basis;
  };

  // Дефиниции функций находятся в самом заголовочном файле:
  VehicleCondition Vehicle::GetVehicleCondition(void) { return m_condition; }
  double Vehicle::GetBasis(void) { return m_basis; }
  // Если оставить inline, но убрать эти дефиниции в исходный файл, то будет
  // ошибка линкера говорящая об отсутствии дефиниции.

}
*/
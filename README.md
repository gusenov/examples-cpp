# Пространства имён

- [Глобальные переменные в глобальном пространстве имён](syncfusion/cpp_succinctly/GlobalNamespaceSample/)
- [Определение вложенных пространств имён](syncfusion/cpp_succinctly/NamespacesSample/)


# Переменные

- [Время существования переменных](syncfusion/cpp_succinctly/StorageDurationSample/)


# Операторы

- [Написание оператора разрешения области видимости ::](double-colon-scope-resolution-operator-syntax/)


# Ввод / вывод

- [std::wcout, std::wcerr, std::wcin](syncfusion/cpp_succinctly/ConsoleSample)
- [std::ofstream никогда не создает папки](fs/out-to-file)
- [Создание каталога с помощью функции mkdir() из библиотеки C POSIX](fs/posix-create-dir-if-not-exists)

# Типы данных

- [Создание псевдонимов для типов с помощью typedef](syncfusion/cpp_succinctly/TypedefSample)
- [Кастинг типов данных](syncfusion/cpp_succinctly/CastingSample)

## Указатели

- [Создание разделяемых указателей через конструктор или std::make_shared](syncfusion/cpp_succinctly/SharedPtrSample)
- [Константные указатели и ссылки](syncfusion/cpp_succinctly/PointerSample)
- [Освобождение памяти через delete[] для указателя const char* const](ptr/const-char-str-ptr-delete)

## Перечисления

- [Scoped и un-scoped перечисления с указанием нижележащего интегрального (целочисленного) типа](syncfusion/cpp_succinctly/EnumSample)
- [Передача перечисления в функцию](enum/pass-enum-to-function)

## Объединения

- [Анонимное объединение внутри структуры с отслеживанием активного элемента](syncfusion/cpp_succinctly/UnionSample)
- [Передача объединения в функцию](union/pass-union-to-function)

## Классы

- [Особенности использования переменных из member initializer list для инициализации других переменных](member-initializer-list-params/)

### Конструкторы

- [Присваивание не вызывает конструктор копирования или деструктор](ctor/assignment-and-copy-ctor)
- [Конструктор преобразования](syncfusion/cpp_succinctly/ConversionConstructor)
- [Инициализация данных и суперклассов](syncfusion/cpp_succinctly/InitializationSample)
- [Делегирующий конструктор](syncfusion/cpp_succinctly/DelegatingConstructor)
- [Конструкторы копирования/перемещения и операторы присваивания копированием/перемещением](syncfusion/cpp_succinctly/ConstructorsSample)
- [Не вызывается конструктор копирования из-за return value optimization](ctor/return-optimization-copy-ctor)

### Деструкторы

- [Деструкторы](dtor/)
- [Можно ли использовать override для виртуального деструктора? Да.](dtor-virtual/example-1)
- [При выходе из скопа для ссылки деструктор не вызывается](ref/ref-dtor-out-of-scope)

### Наследование

- [Можно ли использовать override для невиртуальных методов? Нет.](override/example-1)
- [Виртуальное и невиртуальное наследование в сравнении](syncfusion/cpp_succinctly/InheritanceSample)
- [Перекрытие виртуального метода в производном классе методом с аргументом по умолчанию, что вызывает [-Woverloaded-virtual]](inheritance/override-method-with-default-param)

### Интерфейсы

- [Пример имитации интерфейса IWriteData абстрактным классом](syncfusion/cpp_succinctly/AbstractClassSample)
- [Декларация интерфейсов в C++](declare-interface-cpp/)
- [Способы декларировать интерфейс в C++11](way-to-declare-an-interface/)
- [Пример интерфейса автомобиля с использованием динамического полиморфизма и ключевого слова struct](interfaces/virtual/example-1)
- [Пример интерфейса генерации числа с использованием динамического полиморфизма и ключевого слова class](interfaces/virtual/example-2)


# Функции

- [Объявление и определение функции в разных местах](declaration-and-definition-of-stand-alone-function-in-different-places)
- [Декларация и дефиниция inline-функций в пространстве имён](syncfusion/cpp_succinctly/FunctionsSample)
- [Декларация и дефиниция inline-функций в классе](syncfusion/cpp_succinctly/SimpleClassSample)
- [Лямбда-выражения](syncfusion/cpp_succinctly/LambdaSample)


# Исключения

- [Наследование от std::exception своих исключений](syncfusion/cpp_succinctly/ExceptionsSample)


# Шаблоны

- [Пример шаблона класса для выполнения простых арифметических операций](syncfusion/cpp_succinctly/TemplatesSample)


# Кросс-платформенность

- [Портируемая точка входа](syncfusion/cpp_succinctly/pchar.h)


# Ошибки

- [Множественное определение stand-alone функции в исходных файлах](errors/multiple-definitions-of-stand-alone-function-in-source-files)
- [Множественное определение переменной в исходных файлах](errors/multiple-definitions-of-variables-in-source-files)


# Идиомы

## Curiously recurring template pattern (CRTP)

- [CRTP со статической функцией](crtp/example-1)
- [Пример одного и того же алгоритма с CRTP и без CRTP](crtp/example-2)

## Pimpl (Pointer to Implementation – указатель на реализацию)

- [Сэндвич](syncfusion/cpp_succinctly/PimplSample)


# Стандартная библиотека

## Коллекции

### Словари

- [std::unordered_map при своём разрушении не вызывает деструктор для значений хранящихся по указателю](std/collections/map/unordered-map-el-dtor)

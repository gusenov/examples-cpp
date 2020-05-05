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

## Примитивные типы данных

- [Размеры фундаментальных типов данных](fundamental/fundamental-type-sz)
- [Upcasting знаковых целых и их битовое представление](fundamental/upcasting-signed)
- [Бинарное представление char, unsigned char, short и unsigned short](fundamental/bin-repr-of-type-val)

## Строки

- [Присвоение экземпляру std::string массива char](str/assign-char-arr-to-string)
- [Сравнение std::string и литеральной строки](str/cmp-std-str-with-char-arr)
- [Преобразование std::string к float и обратно](fundamental/real2str)

## Указатели

- [Создание разделяемых указателей через конструктор или std::make_shared](syncfusion/cpp_succinctly/SharedPtrSample)
- [Константные указатели и ссылки](syncfusion/cpp_succinctly/PointerSample)
- [Освобождение памяти через delete[] для указателя const char* const](ptr/const-char-str-ptr-delete)
- [Передача указателей в функцию](ptr/pass-ptr-to-func)
- [Проверка shared_ptr на пустоту](ptr/shared_ptr-if)
- [Присваивание указателя переменной типа auto &](ptr/auto-ref-ptr)
- [Указатель на шаблонную функцию](ptr/fn-ptr-using)

## Ссылки

- [Присваивание и возврат ссылок](ref/assign-ref2ref)

## Перечисления

- [Scoped и un-scoped перечисления с указанием нижележащего интегрального (целочисленного) типа](syncfusion/cpp_succinctly/EnumSample)
- [Передача перечисления в функцию](enum/pass-enum-to-function)
- [Использование элементов перечисления в качестве флагов для битовой маски](enum/bit-mask-with-enum-as-flag)

## Объединения

- [Анонимное объединение внутри структуры с отслеживанием активного элемента](syncfusion/cpp_succinctly/UnionSample)
- [Передача объединения в функцию](union/pass-union-to-function)
- [Объединение указателей](union/union-of-ptr)

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
- [Переопределение уже определенного в суперклассе виртуального метода](inheritance/hide-virt-member-func)
- [Аргументы по умолчанию в виртуальных функциях](inheritance/def-arg-and-virt-func)
- [Переопределение в производном классе возвращаемого типа производным типом](override/override-method-return-value-with-subclass)
- [Последнее переопределение виртуального метода будет вызываться на всех уровнях иерархии](override/overrided-method-call)

### Интерфейсы

- [Пример имитации интерфейса IWriteData абстрактным классом](syncfusion/cpp_succinctly/AbstractClassSample)
- [Декларация интерфейсов в C++](declare-interface-cpp/)
- [Способы декларировать интерфейс в C++11](way-to-declare-an-interface/)
- [Пример интерфейса автомобиля с использованием динамического полиморфизма и ключевого слова struct](interfaces/virtual/example-1)
- [Пример интерфейса генерации числа с использованием динамического полиморфизма и ключевого слова class](interfaces/virtual/example-2)
- [Имплементация метода прямо в интерфейсе](interfaces/method-with-impl-in-interface)

### Методы

- [Виртуальный вариативный метод](virtual/virtual-variadic-method)


# Константность

- [Указатели и константность по данным и адресу](const/const-ptr)
- [Вектор указателей со спецификаторами константности](const/std-vector-with-const-el)
- [Два метода класса с одинаковыми именами, но один из них константный](const/methods-with-same-name-without-args)


# Функции

- [Объявление и определение функции в разных местах](declaration-and-definition-of-stand-alone-function-in-different-places)
- [Декларация и дефиниция inline-функций в пространстве имён](syncfusion/cpp_succinctly/FunctionsSample)
- [Декларация и дефиниция inline-функций в классе](syncfusion/cpp_succinctly/SimpleClassSample)
- [Лямбда-выражения](syncfusion/cpp_succinctly/LambdaSample)

## Шаблонные функции

- [Реализация функций с переменным числом аргументов через вариативные шаблоны](tpl/variadic-tpl)
- [Передача перегруженной шаблонной функции в другую функцию с помощью вспомогательной структуры](tpl/pass-tpl-fn-as-param)
- [Специализация шаблонных функций](fn/tpl-fn-spec)
- [Шаблонизация возвращаемого значения](tpl/tpl-fn-return)
- [Передача геттера в шаблонную функцию аргументом функции или параметром шаблона](tpl/tpl-struct-property-getter)


# Исключения

- [Наследование от std::exception своих исключений](syncfusion/cpp_succinctly/ExceptionsSample)


# Шаблоны

- [Пример шаблона класса для выполнения простых арифметических операций](syncfusion/cpp_succinctly/TemplatesSample)
- [Раздельная декларация и дефиниция шаблона класса](tpl/tpl-class-separate-def)
- [Частичная специализация шаблонных методов класса](tpl/tpl-method-spec)
- [Декларация и дефиниция явного инстанцирования шаблонов](tpl/fn-tpl-explicit-instantiation)
- [Шаблон класса параметрированный геттером массива](tpl/tpl-with-arr-getter)

## Свертка

- [Реализация функции печати с переменным числом аргументов с помощью выражения свертки](tpl/fold)
- [Передача переменного количества классов в функцию и их обработка с помощью выражений свертки](tpl/var-tpl-and-fold-expr)

## Трейты, характеристики, типажи, метафункции

- [Введение в трейты](tpl/intro-to-traits)

# Кросс-платформенность

- [Портируемая точка входа](syncfusion/cpp_succinctly/pchar.h)
- [Порядок от младшего к старшему - little-endian](endianness/little-endian)


# Ошибки

- [Множественное определение stand-alone функции в исходных файлах](errors/multiple-definitions-of-stand-alone-function-in-source-files)
- [Множественное определение переменной в исходных файлах](errors/multiple-definitions-of-variables-in-source-files)
- [Перекрытие лямбда-параметром захваченной переменной](errors/lambda-param-shadow-captured-entity)
- [Шаблонные методы не могут быть виртуальными](tpl/virtual-with-tpl)


# Идиомы

## Curiously recurring template pattern (CRTP)

- [CRTP со статической функцией](crtp/example-1)
- [Пример одного и того же алгоритма с CRTP и без CRTP](crtp/example-2)

## Pimpl (Pointer to Implementation – указатель на реализацию)

- [Сэндвич](syncfusion/cpp_succinctly/PimplSample)


# Стандартная библиотека

## Коллекции

### Векторы

- [Вставка элемента в std::vector в заданную позицию](std/collections/vector/vector-insert)

### Словари

- [std::unordered_map при своём разрушении не вызывает деструктор для значений хранящихся по указателю](std/collections/map/unordered-map-el-dtor)
- [Изменение значений в словаре путём операций на итератором](std/collections/map/change-map-item-value)
- [Метод insert у std::unordered_map не обновляет существующее значение](std/collections/map/map-insert)
- [Словарь из словарей со значением из класса по значению](std/collections/map/map-of-maps)
- [Словарь с ключом типа int и значением типа множество строк](std/collections/map/unordered-map-of-unordered-sets)
- [Получение значения по ссылке из std::unordered_map](std/collections/map/get-val-in-map-by-ref)
- [Обход словаря состоящего из словарей](std/collections/map/loop-through-map-of-maps)
- [Нельзя создать словарь со значением типа ссылки](std/collections/map/map-val-by-ref)

### Итераторы

- [Кастомный итератор по древовидной структуре](it/tree-iter)

## Потоки данных

- [Потоки из стандартной библиотеки](stream/streams)
- [Кастомный поточный буфер для чтения массива байтов из памяти](stream/custom-stream-buffer)

## Контейнеры

### std::any

- [std::any как параметр функции и передача в него значения с автоматическим преобразованием](std/containers/any/std-any-as-param)
- [Контейнер свойств на основе std::any](std/containers/any/property-container)

### std::unordered_set

- [Что будет если применить std::advance к std::unordered_set](std/containers/set/advance-on-set)

## Умные указатели

## std::shared_ptr

- [Сравнение shared_ptr](smart-ptr/shared_ptr/cmp-shared-ptr)
- [Простейшая реализация shared_from_this функциональности](smart-ptr/shared_ptr/shared-from-this)
- [Приведение типов умных указателей](smart-ptr/shared_ptr/shared-ptr-casting)
- [Сброс std::shared_ptr](smart-ptr/shared_ptr/shared-ptr-reset)
- [Удаление элемента из std::vector<std::shared_ptr<…>>](smart-ptr/shared_ptr/vec-with-shared-ptr-items)

## std::weak_ptr

- [Как работают методы expired() и lock() у std::weak_ptr](smart-ptr/weak_ptr/lock-weak-ptr)
- [Автоматическая инвалидация std::weak_ptr при выходе из области видимости](smart-ptr/weak_ptr/new-weak-ptr-expired)
- [Как работает weak_from_this()](smart-ptr/weak_ptr/weak-from-this)


# Макросы

- [Конкатенация частей в макросах](macro/macro-concat)


# Производительность

- [Примеры имплементации простого кэширования на уровне классов](cache)


# Генерация случайных чисел

- [Генерация случайного целого числа в заданном диапазоне](rnd/random-int-in-range)


# Регулярные выражения

- [Замена всех встреч слова в строке](regex/regex-repl-word)
- [Генерация нового имени при копировании](regex/inc-filename)

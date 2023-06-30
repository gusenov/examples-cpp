# Пространства имён

- [Глобальные переменные в глобальном пространстве имён](syncfusion/cpp_succinctly/GlobalNamespaceSample/)
- [Определение вложенных пространств имён](syncfusion/cpp_succinctly/NamespacesSample/)
- [Безымянные пространства имен внутри именованных](ns/unnamed-namespace-within-named)


# Переменные

- [Время существования переменных](syncfusion/cpp_succinctly/StorageDurationSample/)
- [Инициализация статической переменной в локальной области видимости происходит лишь однажды](static/static-var-in-local-scope)


# Операторы

- [Написание оператора разрешения области видимости ::](double-colon-scope-resolution-operator-syntax/)
- [Переопределение операторов new и delete для отслеживания аллокаций](memory/allocation-tracking)


# Ввод / вывод

- [std::wcout, std::wcerr, std::wcin](syncfusion/cpp_succinctly/ConsoleSample)
- [std::ofstream никогда не создает папки](fs/out-to-file)
- [Создание каталога с помощью функции mkdir() из библиотеки C POSIX](fs/posix-create-dir-if-not-exists)
- [Копирование папки](fs/copy-dir)

# Типы данных

- [Создание псевдонимов для типов с помощью typedef](syncfusion/cpp_succinctly/TypedefSample)
- [Кастинг типов данных](syncfusion/cpp_succinctly/CastingSample)
- [Forward declaration типов](type/fwd-dec)

## Примитивные типы данных

- [Размеры фундаментальных типов данных](fundamental/fundamental-type-sz)
- [Upcasting знаковых целых и их битовое представление](fundamental/upcasting-signed)
- [Бинарное представление char, unsigned char, short и unsigned short](fundamental/bin-repr-of-type-val)
- [Побитовое «ИЛИ» с bool](fundamental/bitwise-or-with-bool-type)
- [Присваивание ULONG_MAX float-переменной и обратно](fundamental/ulong-to-float)
- [Присваивание ```true```/```false``` int-переменной](fundamental/assign-bool-to-int)

## Строки

- [Присвоение экземпляру std::string массива char](str/assign-char-arr-to-string)
- [Сравнение std::string и литеральной строки](str/cmp-std-str-with-char-arr)
- [Преобразование std::string к float и обратно](fundamental/real2str)
- [Преобразование std::string в std::wstring и обратно](str/wstring_convert)

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
- [Const-ссылка на временный объект - life time временного объекта продлевается до времени жизни ссылки](ref/assign-val-to-const-ref)

## [Move semantics](move-semantics)

- [Перемещение лямбды](move-semantics/move-lambda-as-param)
- [Передача ```std::unique_ptr``` в функцию](move-semantics/pass-std-unique-ptr-to-fn)

## Перечисления

- [Scoped и un-scoped перечисления с указанием нижележащего интегрального (целочисленного) типа](syncfusion/cpp_succinctly/EnumSample)
- [Передача перечисления в функцию](enum/pass-enum-to-function)
- [Использование элементов перечисления в качестве флагов для битовой маски](enum/bit-mask-with-enum-as-flag)
- [Преобразование enum в строку и обратно](enum/enum-converter)
- [Передача массива enum-значений в функцию](enum/pass-enum-as-int-arr)

## Объединения

- [Анонимное объединение внутри структуры с отслеживанием активного элемента](syncfusion/cpp_succinctly/UnionSample)
- [Передача объединения в функцию](union/pass-union-to-function)
- [Объединение указателей](union/union-of-ptr)
- [Определение stream insertion оператора “<<” для объединения](union/union-and-stream-insertion-operator)

## Классы

- [Особенности использования переменных из member initializer list для инициализации других переменных](member-initializer-list-params/)
- [Возврат экземпляра приватного класса](class/return-private-class-instance)

### Конструкторы

- [Присваивание не вызывает конструктор копирования или деструктор](ctor/assignment-and-copy-ctor)
- [Конструктор преобразования](syncfusion/cpp_succinctly/ConversionConstructor)
- [Инициализация данных и суперклассов](syncfusion/cpp_succinctly/InitializationSample)
- [Делегирующий конструктор](syncfusion/cpp_succinctly/DelegatingConstructor)
- [Конструкторы копирования/перемещения и операторы присваивания копированием/перемещением](syncfusion/cpp_succinctly/ConstructorsSample)
- [Не вызывается конструктор копирования из-за return value optimization](ctor/return-optimization-copy-ctor)
- [Порядок инициализации членов класса](ctor/init-priority)
- [auto переменная не означает ссылку если ей присвоить ссылку](ctor/auto-return-copy-ctor)

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
- [dynamic_cast не может привести к результирующему типу если начальный тип не является потомком результирующего и не имеет с ним общего предка](inheritance/inheritance-dynamic-cast-to-other-branch)
- [dynamic_cast и виртуальное наследование](inheritance/virtual-inheritance-dynamic-cast)
- [Ковариантный возвращаемый тип виртуальной функции](virtual/chg-type-of-param-in-subclass-method)
- [Изменение модификатора доступа унаследованного метода](inheritance/change-access-modifier)
- [Будут ли перегружены от разных предков методы с одинаковыми именами и параметрами в наследнике? (по умолчанию нет)](override/same-super-methods)

### Интерфейсы

- [Research по статическим интерфейсам в C++](interfaces/static-interfaces)
- [Пример имитации интерфейса IWriteData абстрактным классом](syncfusion/cpp_succinctly/AbstractClassSample)
- [Декларация интерфейсов в C++](declare-interface-cpp/)
- [Способы декларировать интерфейс в C++11](way-to-declare-an-interface/)
- [Пример интерфейса автомобиля с использованием динамического полиморфизма и ключевого слова struct](interfaces/virtual/example-1)
- [Пример интерфейса генерации числа с использованием динамического полиморфизма и ключевого слова class](interfaces/virtual/example-2)
- [Имплементация метода прямо в интерфейсе](interfaces/method-with-impl-in-interface)
- [Сравнение наследования интерфейса в Java и С++](interfaces/iface-inheritance-cpp-vs-java)

### Методы

- [Виртуальный вариативный метод](virtual/virtual-variadic-method)
- [Перегрузка метода с std::shared_ptr-параметром](overloading/call-is-ambiguous)
- [Текучий интерфейс](method/fluent-interface)


# Константность

- [Указатели и константность по данным и адресу](const/const-ptr)
- [Вектор указателей со спецификаторами константности](const/std-vector-with-const-el)
- [Два метода класса с одинаковыми именами, но один из них константный](const/methods-with-same-name-without-args)
- [Удаление константности с типа](const/remove-const-from-type)
- [Взятие адреса ```mutable``` поля класса](const/mutable-and-reference-operator)


# Функции

- [Объявление и определение функции в разных местах](declaration-and-definition-of-stand-alone-function-in-different-places)
- [Декларация и дефиниция inline-функций в пространстве имён](syncfusion/cpp_succinctly/FunctionsSample)
- [Декларация и дефиниция inline-функций в классе](syncfusion/cpp_succinctly/SimpleClassSample)
- [Лямбда-выражения](syncfusion/cpp_succinctly/LambdaSample)
- [Передача статического массива указателей в функцию](fn/pass-static-arr-of-ptr-into-fn)
- [Проверка ```std::function``` на пустоту](std/std-function/std-function-empty)

## Анонимные функции

- [Захват parameter pack в лямбда-функцию](lambda/capture-variadic-parameter-pack)
- [При захвате this, переменные экземпляра класса не копируются](lambda/lambda-capture-this)
- [Перегрузка функций с лямбда-функцией в качестве аргумента](tpl/lambda-overloading)

## Шаблонные функции

- [Реализация функций с переменным числом аргументов через вариативные шаблоны](tpl/variadic-tpl)
- [Передача перегруженной шаблонной функции в другую функцию с помощью вспомогательной структуры](tpl/pass-tpl-fn-as-param)
- [Специализация шаблонных функций](fn/tpl-fn-spec)
- [Шаблонизация возвращаемого значения](tpl/tpl-fn-return)
- [Передача геттера в шаблонную функцию аргументом функции или параметром шаблона](tpl/tpl-struct-property-getter)
- [Передача лямбды в метод класса параметром шаблона](tpl/pass-fn-to-tpl)
- [Передача статической функции в шаблонную функцию параметром шаблона](tpl/stat-fn-as-tpl-param)
- [Передача нескольких типов в вариативную шаблонную функцию и обработка каждого типа внутри лямбды](tpl/var-tpl-lambda)


# Исключения

- [Наследование от std::exception своих исключений](syncfusion/cpp_succinctly/ExceptionsSample)


# Шаблоны

- [Пример шаблона класса для выполнения простых арифметических операций](syncfusion/cpp_succinctly/TemplatesSample)
- [Раздельная декларация и дефиниция шаблона класса](tpl/tpl-class-separate-def)
- [Частичная специализация шаблонных методов класса](tpl/tpl-method-spec)
- [Декларация и дефиниция явного инстанцирования шаблонов](tpl/fn-tpl-explicit-instantiation)
- [Шаблон класса параметрированный геттером массива](tpl/tpl-with-arr-getter)
- [Вызов у переданного указателя заданного метода с заданными аргументами](tpl/tpl-proxy)
- [override метода предка переданного аргументом в шаблонный класс](tpl/tpl-and-override)
- [Специализация шаблонного метода в .cpp файле](tpl/tpl-method-specialization-cpp)

## Свертка

- [Реализация функции печати с переменным числом аргументов с помощью выражения свертки](tpl/fold)
- [Передача переменного количества классов в функцию и их обработка с помощью выражений свертки](tpl/var-tpl-and-fold-expr)

## Трейты, характеристики, типажи, метафункции

- [Введение в трейты](tpl/intro-to-traits)
- [std::is_pointer_v<YOUR_TYPE*&> возвращает false](tpl/type-traits-is-pointer)

# Кросс-платформенность

- [Портируемая точка входа](syncfusion/cpp_succinctly/pchar.h)
- [Порядок от младшего к старшему - little-endian](endianness/little-endian)


# Ошибки

- [Множественное определение stand-alone функции в исходных файлах](errors/multiple-definitions-of-stand-alone-function-in-source-files)
- [Множественное определение переменной в исходных файлах](errors/multiple-definitions-of-variables-in-source-files)
- [Перекрытие лямбда-параметром захваченной переменной](errors/lambda-param-shadow-captured-entity)
- [Шаблонные методы не могут быть виртуальными](tpl/virtual-with-tpl)


# Идиомы

## [Curiously recurring template pattern (CRTP)](crtp)

- [CRTP со статической функцией](crtp/example-1)
- [Пример одного и того же алгоритма с CRTP и без CRTP](crtp/example-2)

## Pimpl (Pointer to Implementation – указатель на реализацию)

- [Сэндвич](syncfusion/cpp_succinctly/PimplSample)

## [Type Erasure](type-erasure)

- [RPG game](type-erasure/rpg-game)


# Стандартная библиотека

- [Пример использования std::clamp](std/std-clamp)




## Коллекции и контейнеры

### std::vector

- [Вставка элемента в std::vector в заданную позицию](std/collections/vector/vector-insert)
- [Упорядоченная вставка объектов с компаратором в вектор](std/collections/vector/ins-el-into-vec)
- [Как работает std::distance](std/collections/vector/std-vector-distance)
- [Как работает erase](std/collections/vector/std-vector-erase)

### std::list

- [Сравнение двух списков из std::pair<std::string, std::string>](std/collections/list/cmp-list-of-pairs)

### std::map и std::unordered_map

- [std::unordered_map при своём разрушении не вызывает деструктор для значений хранящихся по указателю](std/collections/map/unordered-map-el-dtor)
- [Изменение значений в словаре путём операций на итератором](std/collections/map/change-map-item-value)
- [Метод insert у std::unordered_map не обновляет существующее значение](std/collections/map/map-insert)
- [Словарь из словарей со значением из класса по значению](std/collections/map/map-of-maps)
- [Словарь с ключом типа int и значением типа множество строк](std/collections/map/unordered-map-of-unordered-sets)
- [Получение значения по ссылке из std::unordered_map](std/collections/map/get-val-in-map-by-ref)
- [Обход словаря состоящего из словарей](std/collections/map/loop-through-map-of-maps)
- [Нельзя создать словарь со значением типа ссылки](std/collections/map/map-val-by-ref)
- [Применение std::max_element к std::map](std/collections/map/map-int-str)
- [Использование указателя на класс как ключа для std::unordered_map](std/collections/map/ptr-as-key-in-map)
- [std::pair в качестве ключа для словаря](std/collections/map/pair-as-key)
- [Удаление из std::map](std/collections/map/map-erase)
- [Использование умного указателя в качестве ключа для словаря](std/collections/map/smart-ptr-as-key)

### std::set и std::unordered_set

- [Что будет если применить std::advance к std::unordered_set](std/containers/set/advance-on-set)
- [Изменение ключа у элемента множества не приводит к изменению порядка элемента](std/containers/set/set-with-cmp-el)

### std::tuple

- [std::tuple из статических методов](std/containers/tuple/tuple-of-static-methods)

### std::any

- [std::any как параметр функции и передача в него значения с автоматическим преобразованием](std/containers/any/std-any-as-param)
- [Контейнер свойств на основе std::any](std/containers/any/property-container)




## Итераторы

- [Кастомный итератор по древовидной структуре](it/tree-iter)




## Потоки данных

- [Потоки из стандартной библиотеки](stream/streams)
- [Кастомный поточный буфер для чтения массива байтов из памяти](stream/custom-stream-buffer)




## Умные указатели

### std::shared_ptr

- [Сравнение shared_ptr](smart-ptr/shared_ptr/cmp-shared-ptr)
- [Простейшая реализация shared_from_this функциональности](smart-ptr/shared_ptr/shared-from-this)
- [Приведение типов умных указателей](smart-ptr/shared_ptr/shared-ptr-casting)
- [Сброс std::shared_ptr](smart-ptr/shared_ptr/shared-ptr-reset)
- [Удаление элемента из std::vector<std::shared_ptr<…>>](smart-ptr/shared_ptr/vec-with-shared-ptr-items)
- [std::shared_ptr не вызывающий деструктор](smart-ptr/shared_ptr/null-deleter)
- [Различия в создании shared_ptr через конструктор и make_shared](smart-ptr/shared_ptr/shared_ptr-vs-make_shared)
- [Возврат std::shared_ptr<T> как std::shared_ptr<T const>](smart-ptr/shared_ptr/return-shared_ptr-const)

### std::weak_ptr

- [Как работают методы expired() и lock() у std::weak_ptr](smart-ptr/weak_ptr/lock-weak-ptr)
- [Автоматическая инвалидация std::weak_ptr при выходе из области видимости](smart-ptr/weak_ptr/new-weak-ptr-expired)
- [Как работает weak_from_this()](smart-ptr/weak_ptr/weak-from-this)
- [Приведение типа пустого std::weak_ptr](smart-ptr/weak_ptr/cast-weak-ptr)

### std::unique_ptr

- [При присваивании std::unique_ptr происходит деструкция содержимого](smart-ptr/unique_ptr/unique-ptr-assign)




## Многопоточность

- [Получение ID потока и сон (sleep) в потоке](multithreading/thread-id)
- [Использование std::async и std::future](multithreading/std-async-n-future)
- [std::condition_variable проверяет условие ожидания при запуске и при вызове notify](multithreading/cond-var-wait)




# Макросы

- [Конкатенация частей в макросах](macro/macro-concat)


# Производительность

- [Примеры имплементации простого кэширования на уровне классов](cache)
- [Сколько времени занимает выполнение циклов](performance/loop-time)


# Генерация случайных чисел

- [Генерация случайного целого числа в заданном диапазоне](rnd/random-int-in-range)
- [При использовании ```std::random_device``` может быть исключение ```libc++abi: terminating with uncaught exception of type std::__1::system_error: random_device failed to open /dev/urandom: Too many open files```](rnd/random-device-usage)


# Регулярные выражения

- [Замена всех встреч слова в строке](regex/regex-repl-word)
- [Генерация нового имени при копировании](regex/inc-filename)

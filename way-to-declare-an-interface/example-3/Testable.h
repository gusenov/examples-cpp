class Testable
{
public:
    virtual ~Testable() = default; // make dtor virtual
    // Виртуальный деструктор нужен для того чтобы правильно работали
    // delete или typeid на производных классах при доступе к ним по
    // указателю или ссылке на базовый класс.

    // User-declared destructor подавляет генерацию операций перемещения.
    // Поэтому для поддержки операций перемещения нужно добавить:

    Testable(Testable&&) = default;  // support moving
    Testable& operator=(Testable&&) = default;

    // Декларация операций перемещения выключает операции копирования.
    // Поэтому также нужно:

    Testable(const Testable&) = default; // support copying
    Testable& operator=(const Testable&) = default;

    virtual void test() = 0;

};

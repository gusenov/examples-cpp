// Curiously Recurring Template Pattern (CRTP):

// Вспомогательный helper класс для статического кастинга.
// Каждый статический интерфейс производится от этого класса.

template<typename Derived>
class enable_down_cast
{

  private:

    typedef enable_down_cast Base;

  public:

    // Автоматический down-casting от базового класса к производному
    // выполняется с помощью static_cast:

    Derived const* self() const
    {
      // casting "down" the inheritance hierarchy
      return static_cast<Derived const*>(this);
    }

    Derived* self()
    {
      return static_cast<Derived*>(this);
    }

  protected:

    // disable deletion of Derived* through Base*
    // enable deletion of Base* through Derived*
    ~enable_down_cast() = default; // C++11 only, use ~enable_down_cast() {} in C++98

};

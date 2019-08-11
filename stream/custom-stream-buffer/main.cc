#include <streambuf>
#include <iostream>
#include <cstdlib>
#include <cassert>
#include <cstring>

class char_array_buffer : public std::streambuf {
public:
  // Конструктор принимает два указателя задающих последовательность символов
  // в STL-стиле: [begin, end)
  char_array_buffer(const char *begin, const char *end):
    begin_(begin),
    end_(end),
    current_(begin_)
  {
    // setg(
    //   begin,  // eback
    //   begin,  // gptr
    //   end     // egptr
    // );
    // Не сработает потому что setg() принимает указатели на non-const chars.
    // Если в буфер нельзя писать, то нельзя обеспечить put-back функциональность.

    assert(std::less_equal<const char *>()(begin_, end_));
  }

  explicit char_array_buffer(const char *str):
    begin_(str),
    end_(begin_ + std::strlen(str)),
    current_(begin_)
  {}

private:

  // Возвращает текущий символ из источника, или traits_type::eof(), если
  // источник опустошен:
  int_type underflow() override {
    // return  gptr() == egptr() ? traits_type::eof() : traits_type::to_int_type(*gptr());

    if (current_ == end_)
      return traits_type::eof();

    return traits_type::to_int_type(*current_);
  }

  // Т.к. мы не можем вызвать setg(), то нужно переопределить некоторое
  // поведение в базовом классе чтобы он не думал, что мы постоянно в конце
  // буфера:

  // Возвращает текущий символ и потом инкрементирует буферный указатель:
  int_type uflow() override {
    // Имплементация по умолчанию std::streambuf::uflow() вызывает underflow()
    // и возвращает результат после инкремента get pointer-а (возвращаемого
    // gptr()). Однако мы не используем get pointer потому что не вызываем
    // setg() и поэтому имплементация по умолчанию не подходит.
    // Потребность в перекрытии uflow() обычно возникает, когда в массив
    // используемый в качестве промежуточного хранилища нельзя писать.

    if (current_ == end_)
        return traits_type::eof();

    return traits_type::to_int_type(*current_++);
  }


  // При вызове std::istream::unget() или std::istream::putback(some_character)
  // some_character по возможности возвращается в стрим. Буфер не может этого
  // сделать, если его end back pointer равен его end get pointer, т.е.
  // eback() == gptr().

  // В нашем char_array_buffer всегда выполняется условие eback() == gptr()
  // т.к. они оба инициализируются 0 по умолчанию. In this case, pbackfail(ch)
  // will be called as a last resort with ch having the value of the character
  // to put back in to the stream or traits_type::eof() if the character that
  // was already at the previous position should be left unchanged.

  // Если pbackfail() способен вернуть заданный символ, то нужно вернуть
  // что-то другое, а не traits_type::eof(). Имплементация по умолчанию
  // всегда возвращает traits_type::eof() поэтому ее нужно перекрыть:
  int_type pbackfail(int_type ch) override {
    // Мы не можем вернуть символ если current_ == begin_ или если символ
    // для возвращения в стрим не такой же как и current_[-1] (потому что символы
    // в массиве иммутабельны). Поэтому здесь проверяются эти условия:
    if (current_ == begin_ || (ch != traits_type::eof() && ch != current_[-1]))
      return traits_type::eof();

    // Иначе мы можем сделать декремент current_ и вернуть что-то отличное от
    // traits_type::eof() в качестве признака успеха:
    return traits_type::to_int_type(*--current_);
  }


  // Этот метод вызывается std::streambuf::in_avail() (который public) когда
  // gptr() == egptr() для того чтобы вернуть количество символов, которые
  // определенно могут быть извлечены из стрима до того как он заблокируется.
  // Т.к. мы всегда в ситуации, когда gptr() == egptr() нужно переопределить
  // showmanyc() чтобы возвращать что-то более значимое чем значение по умолчанию
  // или 0:
  std::streamsize showmanyc() override {
    assert(std::less_equal<const char *>()(current_, end_));
    return end_ - current_;
  }


  // Конструкторы копирования и присваивания не имплементированы;
  // копирование запрещено:
  char_array_buffer(const char_array_buffer &);
  char_array_buffer &operator= (const char_array_buffer &);

private:
  const char * const begin_;
  const char * const end_;
  const char * current_;
};


int main(int argc, char* argv[]) {
  const char text[] = "This is the contents of an array!";
  char_array_buffer buff(text); // -1 for \0
  std::istream in(&buff);

  std::string s;
  while (in >> s)
    std::cout << "echo: " << s << '\n';

  in.clear();
  for (unsigned i = 0; i != 3; ++i)
    in.unget();

  if (in >> s)
    std::cout << "final: " << s << '\n';

  return EXIT_SUCCESS;
}

#include <type_traits>




// Trait принимает произвольное количество типов и всегда возвращает void.
template <typename... Args>
struct t
{
    using type = void;
};
using result = typename t<int, double>::type;
static_assert(std::is_same<result, void>{}, "");




// t_t<int, double> становится синонимом для void:
template <typename... Args>
using t_t = typename t<Args...>::type;
// NOTE: C++14 standard library предоставляет _t alias templates
// для всех traits в standard library.
using result = t_t<int, double>;
static_assert(std::is_same<result, void>{}, "");




int main (int argc, char *argv[]) {
  return 0;
}

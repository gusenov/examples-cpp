#ifndef MostDerived_h
#define MostDerived_h

#include "Derived.h"


class MostDerived : public Derived {
public:
    ~MostDerived() override = default;

    // Это
    // void SaySomething();
    // то же самое, что и
    // void SaySomething() override;
    // только будет
    // warning: 'SaySomething' overrides a member function but is not marked 'override' [-Winconsistent-missing-override]


    // override выполняет проверку на то что ранее был уже такой же виртуальный
    // метод. В данном случае не находится метода с такой сигнатурой и проверка
    // не проходит:
    //
    // void SaySomething(char const *message) override;
    // error: non-virtual member function marked 'override' hides virtual member function
    //
    // void SaySomething(char const *message = nullptr) override;
    // error: non-virtual member function marked 'override' hides virtual member function


    // Это уже новая виртуальная фукнция:
    virtual void SaySomething(char const *message);
};

#endif /* MostDerived_h */

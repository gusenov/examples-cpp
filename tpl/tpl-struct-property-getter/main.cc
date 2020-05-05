#include <cstdlib>
#include <iostream>
#include <string>

template<class T, typename TFirstNameGeter, typename TLastNameGeter, typename TAgeGeter>
void Print(T person, TFirstNameGeter GetFirstName, TLastNameGeter GetLastName, TAgeGeter GetAge) {
    std::cout << person.*GetFirstName << " "
              << person.*GetLastName << ", "
              << person.*GetAge << std::endl;
}

template<class T, int (T::*AgeGetter)>
void PrintAge(T person) {
    std::cout << person.*AgeGetter << std::endl;
}

struct Person {
    std::string firstName;
    std::string lastName;
    int age;
};

int main(int argc, char **argv) {

    Person a { "Abbas", "Gussenov", 29 };

    Print<Person>(a, &Person::firstName, &Person::lastName, &Person::age);
    // Abbas Gussenov, 29

    PrintAge<Person, &Person::age>(a);
    // 29

    return EXIT_SUCCESS;
}

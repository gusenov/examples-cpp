#include <iostream>
#include "MyClass.hpp"

template<typename T>
MyClass<T>::MyClass() {
    std::cout << "MyClass()" << std::endl;
}

// When the compiler encounters a declaration of a MyClass object of some
// specific type, e.g., int, it must have access to the template implementation
// source. Otherwise, it will have no idea how to construct the MyClass member
// functions. And, if you have put the implementation in a source (MyClass.cpp)
// file and made it a separate part of the project, the compiler will not be
// able to find it when it is trying to compile the client source file.

// You can create an object of a template class in the same source file where it
// is implemented (MyClass.cpp). So, there is no need to link the object
// creation code with its actual implementation in some other file. This will
// cause the compiler to compile these particular types so the associated class
// member functions will be available at link time.

// No need to call this TemporaryFunction() function,
// it's just to avoid link error.
void TemporaryFunction ()
{
    MyClass<int> TempObj;
}

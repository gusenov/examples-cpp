#include "MyClass.h"
#include <iostream>


MyClass::MyClass(int param) :
	sz(param),
	//arr(create(sz))  // Тут sz == 0, будет HEAP CORRUPTION в деструкторе.
	arr(create(param))  // Тут ошибки не будет потом в деструкторе.
{
	arr[0] = 'A';
}


MyClass::~MyClass()
{
	delete[] arr;
}


char* MyClass::create(int sz)
{
	std::cout << "sz = " << sz << std::endl;
	return new char[sz];
}
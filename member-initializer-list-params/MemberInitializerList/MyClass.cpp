#include "MyClass.h"
#include <iostream>


MyClass::MyClass(int param) :
	sz(param),
	//arr(create(sz))  // ��� sz == 0, ����� HEAP CORRUPTION � �����������.
	arr(create(param))  // ��� ������ �� ����� ����� � �����������.
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
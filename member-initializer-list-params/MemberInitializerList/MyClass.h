#pragma once
class MyClass
{
public:
	MyClass(int param);
	~MyClass();
	static char* create(int sz);
private:
	char* arr;
	int sz;
};


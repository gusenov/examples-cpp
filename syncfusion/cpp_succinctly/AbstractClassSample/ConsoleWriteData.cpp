#include <iostream>
#include <ostream>
#include "ConsoleWriteData.h"

using namespace std;

void ConsoleWriteData::Write(const wchar_t* value)     { wcout << value; }
void ConsoleWriteData::Write(double value)             { wcout << value; }
void ConsoleWriteData::Write(int value)                { wcout << value; }
void ConsoleWriteData::WriteLine(void)                 { wcout << endl; }
void ConsoleWriteData::WriteLine(const wchar_t* value) { wcout << value << endl; }
void ConsoleWriteData::WriteLine(double value)         { wcout << value << endl; }
void ConsoleWriteData::WriteLine(int value)            { wcout << value << endl; }

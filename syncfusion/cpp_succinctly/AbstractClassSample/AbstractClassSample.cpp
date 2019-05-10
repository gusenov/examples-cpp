#include "IWriteData.h"
#include "ConsoleWriteData.h"
#include "../pchar.h"

int _pmain(int /*argc*/, _pchar* /*argv*/[]) {
	// Следующая строка недопустима, т.к. IWriteData абстрактен:
	//IWriteData iwd = IWriteData();

	// Следующая строка также недопустима, нельзя иметь экземпляр IWriteData:
	//IWriteData iwd = ConsoleWriteData();

	ConsoleWriteData cwd = ConsoleWriteData();

	// Можно создать IWriteData ссылку на экземпляр класса производного от
	// IWriteData:
	IWriteData& r_iwd = cwd;

	// Также можно создать IWriteData указатель на экземпляр класса производного
	// от IWriteData:
	IWriteData* p_iwd = &cwd;

	cwd.WriteLine(10);                           // 10
	r_iwd.WriteLine(14.6);                       // 14.6
	p_iwd->WriteLine(L"Hello Abstract World!");  // Hello Abstract World!

	return 0;
}

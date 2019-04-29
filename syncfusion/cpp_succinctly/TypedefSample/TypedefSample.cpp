#include <iostream>
#include <ostream>
#include <vector>
#include <algorithm>
#include "../pchar.h"

// Сделать WidgetIdVector псевдонимом для std::vector<int>.
// Это выглядит более понятно, чем просто std::vector<int>, т.к. ясно, что
// когда что-то использует такой псевдоним, то оно ожидает вектор
// идентификаторов виджетов, а не просто вектор целых чисел.
typedef std::vector<int> WidgetIdVector;

// На практике вышеприведённый typedef лучше поместить в namespace и подключать
// через заголовочный файл.

bool ContainsWidgetId(WidgetIdVector idVector, int id) {
	return (std::end(idVector) !=
		std::find(std::begin(idVector), std::end(idVector), id)
		);
}

int _pmain(int /*argc*/, _pchar* /*argv*/[]) {
	WidgetIdVector idVector;

	// Добавить несколько числовых идентификаторов в вектор:
	idVector.push_back(5);
	idVector.push_back(8);

	// Вывод результата принадлежности идентификатора к вектору WidgetIdVector:
	std::wcout << L"Contains 8: " <<
		(ContainsWidgetId(idVector, 8) ? L"true." : L"false.") <<
		std::endl;
	// Contains 8: true.

	return 0;
}

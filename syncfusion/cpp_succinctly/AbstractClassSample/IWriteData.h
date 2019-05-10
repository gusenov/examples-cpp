#pragma once

// Имитация C# интерфейса:

class IWriteData {

// От класса IWriteData может быть унаследован класс, который пишет данные
// в log-файл, в сетевое соединение или в любой другой вывод. Передавая
// туда-сюда указатель или ссылку на IWriteData можно легко переключать
// механизмы.

	public:
		// Абстрактный класс должен иметь хотя бы один чистый виртуальный метод
		// (функцию-член). Синтаксис для абстрактных функций-членов называется
		// чистой виртуальной функцией, он просто добавляет = 0 после декларации.
		// Не обязательно делать класс чисто абстрактным; можно имплементировать
		// функции-члены или включить члены данных общие для всех экземпляров
		// класса. Но если класс имеет хотя бы одну чистую виртуальную функцию,
		// то он рассматривается как абстрактный класс.

		// IWriteData(void) = 0;
		// virtual ~IWriteData(void) { }

		virtual void Write(const wchar_t* value) = 0;
		virtual void Write(double value) = 0;
		virtual void Write(int value) = 0;

		virtual void WriteLine(void) = 0;
		virtual void WriteLine(const wchar_t* value) = 0;
		virtual void WriteLine(double value) = 0;
		virtual void WriteLine(int value) = 0;
};

// Visual C++ предоставляет Microsoft-специфичный путь для определения
// интерфейсов http://msdn.microsoft.com/en-us/library/50h7kwtb(VS.110).aspx

// Вместо определения класса используется ключевое слово __interface.
// Нельзя определить конструктор, деструктор или функции-члены кроме как
// чистых виртуальных функций-членов. Также нельзя наследоваться ни от чего
// кроме как других интерфейсов. Не нужно указать спецификатор доступа public
// потому что все функции-члены публичные.

// __interface IWriteData {
// 	virtual void Write(const wchar_t* value) = 0;
// 	virtual void Write(double value) = 0;
// 	virtual void Write(int value) = 0;
//
// 	virtual void WriteLine(void) = 0;
// 	virtual void WriteLine(const wchar_t* value) = 0;
// 	virtual void WriteLine(double value) = 0;
// 	virtual void WriteLine(int value) = 0;
// };

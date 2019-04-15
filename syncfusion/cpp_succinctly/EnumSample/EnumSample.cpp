#include <iostream>
#include <ostream>
#include <string>
#include "../pchar.h"

enum class Color { Red, Orange, Yellow, Blue, Indigo, Violet };

// Можно указать любой подходящий интегральный тип для нижнего уровня:
enum Flavor : unsigned short int { Vanilla, Chocolate, Strawberry, Mint, };

int _pmain(int /*argc*/, _pchar* /*argv*/[]) {
	Flavor f = Vanilla;

	// Это допустимо т.к. Flavor enum является unscoped enum:
	f = Mint;

	Color c = Color::Orange;

	// Это недопустимо т.к. Color enum является scoped enum:
	//c = Orange;

	// :: - это в C++ scope resolution operator.
	// Можно думать о нём как об операторе . в C#.

	std::wstring flavor;
	std::wstring color;

	switch (c) {
	case Color::Red:    color = L"Red"; break;
	case Color::Orange: color = L"Orange"; break;
	case Color::Yellow: color = L"Yellow"; break;
	case Color::Blue:   color = L"Blue"; break;
	case Color::Indigo: color = L"Indigo"; break;
	case Color::Violet: color = L"Violet"; break;
	default:            color = L"Unknown"; break;
	}

	switch (f) {
	case Vanilla:    flavor = L"Vanilla"; break;
	case Chocolate:  flavor = L"Chocolate"; break;
	case Strawberry: flavor = L"Strawberry"; break;
	case Mint:       flavor = L"Mint"; break;
	default:         break;
	}

	std::wcout

  << L"Flavor is " << flavor.c_str() << L" (" << f << L"). Color is "
	<< color.c_str() << L" (" << static_cast<int>(c) << L")." << std::endl
  // Flavor is Mint (3). Color is Orange (1).

  << L"The size of Flavor is " << sizeof(Flavor) << L"." << std::endl
  // The size of Flavor is 2.

  << L"The size of Color is " << sizeof(Color) << L"." << std::endl;
  // The size of Color is 4.

	return 0;
}

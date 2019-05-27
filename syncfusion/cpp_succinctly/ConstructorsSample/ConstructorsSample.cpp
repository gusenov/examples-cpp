#include <iostream>
#include <ostream>
#include "IceCreamSundae.h"
#include "Flavor.h"
#include "Toppings.h"
#include "../pchar.h"

using namespace Desserts;
using namespace std;

typedef Desserts::Toppings::ToppingsList ToppingsList;

int _pmain(int /*argc*/, _pchar* /*argv*/[]) {
	const wchar_t* outputPrefixStr = L"Current Dessert: ";

	IceCreamSundae s1 = Flavor::Vanilla;
	// OUTPUT:
	// Conversion constructing IceCreamSundae(Flavor).

	wcout << outputPrefixStr << s1.GetSundaeDescription() << endl;
	// OUTPUT:
	// Current Dessert: A Vanilla sundae with the following toppings: None

	s1.AddTopping(ToppingsList::HotFudge);
	wcout << outputPrefixStr << s1.GetSundaeDescription() << endl;
	// OUTPUT:
	// Current Dessert: A Vanilla sundae with the following toppings: Hot Fudge

	s1.AddTopping(ToppingsList::Cherry);
	wcout << outputPrefixStr << s1.GetSundaeDescription() << endl;
	// OUTPUT:
	// Current Dessert: A Vanilla sundae with the following toppings:
	// Hot Fudge Cherry

	s1.AddTopping(ToppingsList::CrushedWalnuts);
	wcout << outputPrefixStr << s1.GetSundaeDescription() << endl;
	// OUTPUT:
	// Current Dessert: A Vanilla sundae with the following toppings:
	// Hot Fudge Crushed Walnuts Cherry

	s1.AddTopping(ToppingsList::WhippedCream);
	wcout << outputPrefixStr << s1.GetSundaeDescription() << endl;
	// OUTPUT:
	// Current Dessert: A Vanilla sundae with the following toppings:
	// Hot Fudge Crushed Walnuts Whipped Cream Cherry

	s1.RemoveTopping(ToppingsList::CrushedWalnuts);
	// OUTPUT:
	// Current Dessert: A Vanilla sundae with the following toppings:
	// Hot Fudge Whipped Cream Cherry
	wcout << outputPrefixStr << s1.GetSundaeDescription() << endl;

	wcout << endl << L"Copy constructing s2 from s1." << endl;
	// OUTPUT:
	// Copy constructing s2 from s1.
	IceCreamSundae s2(s1);
	// OUTPUT:
	// Copy constructing IceCreamSundae.

	wcout << endl << L"Copy assignment to s1 from s2." << endl;
	// OUTPUT:
	// Copy assignment to s1 from s2.
	s1 = s2;
	// OUTPUT:
	// Copy assigning IceCreamSundae.

	wcout << endl << L"Move constructing s3 from s1." << endl;
	// OUTPUT:
	// Move constructing s3 from s1.
	IceCreamSundae s3(std::move(s1));
	// OUTPUT:
	// Move constructing IceCreamSundae.
	// Move assigning IceCreamSundae.

	wcout << endl << L"Move assigning to s1 from s2." << endl;
	// OUTPUT:
	// Move assigning to s1 from s2.
	s1 = std::move(s2);
	// OUTPUT:
	// Move assigning IceCreamSundae.

	// Destroying IceCreamSundae.
	// Destroying IceCreamSundae.
	// Destroying IceCreamSundae.

	return 0;
}

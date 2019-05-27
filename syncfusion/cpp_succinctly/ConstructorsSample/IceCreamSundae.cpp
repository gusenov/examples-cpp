#include "IceCreamSundae.h"
#include <string>
#include <sstream>
#include <iostream>
#include <ostream>
#include <memory>

using namespace Desserts;
using namespace std;

IceCreamSundae::IceCreamSundae(void) : m_flavor(Flavor::None),
																			 m_toppings(Toppings::None),
																			 m_description() {
	wcout << L"Default constructing IceCreamSundae(void)." << endl;
}

IceCreamSundae::IceCreamSundae(Flavor flavor) : m_flavor(flavor),
																								m_toppings(Toppings::None),
																								m_description() {
	wcout << L"Conversion constructing IceCreamSundae(Flavor)." << endl;
}

IceCreamSundae::IceCreamSundae(Toppings::ToppingsList toppings) :
	m_flavor(Flavor::None), m_toppings(toppings), m_description() {
		wcout << L"Parameter constructing IceCreamSundae(\
			Toppings::ToppingsList)." << endl;
}

IceCreamSundae::IceCreamSundae(const IceCreamSundae& other) :
	m_flavor(other.m_flavor), m_toppings(other.m_toppings), m_description() {
		wcout << L"Copy constructing IceCreamSundae." << endl;
}

IceCreamSundae& IceCreamSundae::operator=(const IceCreamSundae& other) {
	wcout << L"Copy assigning IceCreamSundae." << endl;
	m_flavor = other.m_flavor;
	m_toppings = other.m_toppings;
	return *this;
}

IceCreamSundae::IceCreamSundae(IceCreamSundae&& other) : m_flavor(),
																												 m_toppings(),
																												 m_description() {
	wcout << L"Move constructing IceCreamSundae." << endl;
	*this = std::move(other);
}

IceCreamSundae& IceCreamSundae::operator=(IceCreamSundae&& other) {
	wcout << L"Move assigning IceCreamSundae." << endl;

	if (this != &other) {
		m_flavor = std::move(other.m_flavor);
		m_toppings = std::move(other.m_toppings);
		m_description = std::move(other.m_description);
		other.m_flavor = Flavor::None;
		other.m_toppings = Toppings::None;
		other.m_description = std::wstring();
	}
	return *this;
}

IceCreamSundae::~IceCreamSundae(void) {
	wcout << L"Destroying IceCreamSundae." << endl;
}

void IceCreamSundae::AddTopping(Toppings::ToppingsList topping) {
	m_toppings = m_toppings | topping;
}

void IceCreamSundae::RemoveTopping(Toppings::ToppingsList topping) {
	m_toppings = m_toppings & ~topping;
}

void IceCreamSundae::ChangeFlavor(Flavor flavor) {
	m_flavor = flavor;
}

const wchar_t* IceCreamSundae::GetSundaeDescription(void) {
	wstringstream str;
	str << L"A " << GetFlavorString(m_flavor)
			<< L" sundae with the following toppings: " << m_toppings.GetString();
	m_description = wstring(str.str());
	return m_description.c_str();
}

#pragma once
#include <string>
#include <sstream>

namespace Desserts {
	class Toppings {
		public:

			enum ToppingsList : unsigned int {
				None           = 0x00,
				HotFudge       = 0x01,
				RaspberrySyrup = 0x02,
				CrushedWalnuts = 0x04,
				WhippedCream   = 0x08,
				Cherry         = 0x10
			} m_toppings;

			Toppings(void) : m_toppings(None), m_toppingsString() {}
			Toppings(ToppingsList toppings) : m_toppings(toppings),
																				m_toppingsString() {}
			~Toppings(void) {}

			const wchar_t* GetString(void) {
				if (m_toppings == None) {
					m_toppingsString = L"None";
					return m_toppingsString.c_str();
				}

				bool addSpace = false;
				std::wstringstream wstrstream;

				if (m_toppings & HotFudge) {
					if (addSpace) { wstrstream << L" "; }
					wstrstream << L"Hot Fudge";
					addSpace = true;
				}

				if (m_toppings & RaspberrySyrup) {
					if (addSpace) { wstrstream << L" "; }
					wstrstream << L"Raspberry Syrup";
					addSpace = true;
				}

				if (m_toppings & CrushedWalnuts) {
					if (addSpace) { wstrstream << L" "; }
					wstrstream << L"Crushed Walnuts";
					addSpace = true;
				}

				if (m_toppings & WhippedCream) {
					if (addSpace) { wstrstream << L" "; }
					wstrstream << L"Whipped Cream";
					addSpace = true;
				}

				if (m_toppings & Cherry) {
					if (addSpace) { wstrstream << L" "; }
					wstrstream << L"Cherry";
					addSpace = true;
				}

				m_toppingsString = std::wstring(wstrstream.str());
				return m_toppingsString.c_str();
			}

		private:
			std::wstring m_toppingsString;
	};

	inline Toppings operator&(Toppings a, unsigned int b)	{
		a.m_toppings
			= static_cast<Toppings::ToppingsList>(static_cast<int>(a.m_toppings)
																							& b);
		return a;
	}

	inline Toppings::ToppingsList operator&(Toppings::ToppingsList a,
																					unsigned int b) {
		auto val
			= static_cast<Toppings::ToppingsList>(static_cast<unsigned int>(a)
																							& b);
		return val;
	}

	inline Toppings::ToppingsList operator|(Toppings::ToppingsList a,
																					Toppings::ToppingsList b) {
		return static_cast<Toppings::ToppingsList>(static_cast<int>(a)
			| static_cast<int>(b));
	}

	inline Toppings operator|(Toppings a, Toppings::ToppingsList b) {
		a.m_toppings
			= static_cast<Toppings::ToppingsList>(static_cast<int>(a.m_toppings)
				| static_cast<int>(b));
		return a;
	}
}

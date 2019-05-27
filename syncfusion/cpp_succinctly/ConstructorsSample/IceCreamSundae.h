
#pragma once
#include "Flavor.h"
#include "Toppings.h"
#include <string>

namespace Desserts {
	class IceCreamSundae {
	public:
		IceCreamSundae(void);

		IceCreamSundae(Flavor flavor);

		explicit IceCreamSundae(Toppings::ToppingsList toppings);

		IceCreamSundae(const IceCreamSundae& other);
		IceCreamSundae& operator=(const IceCreamSundae& other);

		IceCreamSundae(IceCreamSundae&& other);
		IceCreamSundae& operator=(IceCreamSundae&& other);

		~IceCreamSundae(void);

		void AddTopping(Toppings::ToppingsList topping);
		void RemoveTopping(Toppings::ToppingsList topping);

		void ChangeFlavor(Flavor flavor);

		const wchar_t* GetSundaeDescription(void);

	private:
		Flavor       m_flavor;
		Toppings     m_toppings;
		std::wstring m_description;
	};
}

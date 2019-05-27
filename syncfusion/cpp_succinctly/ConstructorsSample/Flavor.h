#pragma once

namespace Desserts {
	enum class Flavor { None, Vanilla, Chocolate, Strawberry };

	inline Flavor operator|=(Flavor a, Flavor b) {
		return static_cast<Flavor>(static_cast<int>(a) | static_cast<int>(b));
	}

	inline const wchar_t* GetFlavorString(Flavor flavor) {
		switch (flavor) {
			case Desserts::Flavor::None:       return L"No Flavor Selected"; break;
			case Desserts::Flavor::Vanilla:    return L"Vanilla";            break;
			case Desserts::Flavor::Chocolate:  return L"Chocolate";          break;
			case Desserts::Flavor::Strawberry: return L"Strawberry";         break;
			default:                           return L"Unknown";            break;
		}
	}
}

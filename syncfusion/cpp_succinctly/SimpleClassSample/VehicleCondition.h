#pragma once
#include <string>

namespace Inventory {
  enum class VehicleCondition { Excellent = 1, Good = 2, Fair = 3, Poor = 4 };

  inline const std::wstring GetVehicleConditionString(VehicleCondition condition) {
    std::wstring conditionString;
    switch (condition) {
      case Inventory::VehicleCondition::Excellent:
        conditionString = L"Excellent";
        break;
      case Inventory::VehicleCondition::Good:
        conditionString = L"Good";
        break;
      case Inventory::VehicleCondition::Fair:
        conditionString = L"Fair";
        break;
      case Inventory::VehicleCondition::Poor:
        conditionString = L"Poor";
        break;
      default:
        conditionString = L"Unknown Condition";
        break;
    }
    
    // Возвращает копию std::wstring созданную в этой inline-функции, а не само
    // локальное значение:
    return conditionString;
  }
}

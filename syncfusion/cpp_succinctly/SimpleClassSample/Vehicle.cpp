#include "Vehicle.h"
#include "VehicleCondition.h"

using namespace Inventory;
using namespace std;

// Дефиниция функций членов Vehicle:

// Конструктор:
Vehicle::Vehicle(VehicleCondition condition, double pricePaid) :
  m_condition(condition),
  m_basis(pricePaid) {}

// Деструктор:
Vehicle::~Vehicle(void) {}

// Обычно такие функции лучше делать inline:
void Vehicle::SetVehicleCondition(VehicleCondition condition) {
	m_condition = condition;
}
// Здесь функция дефенирована раздельно для иллюстрации того как дефинировать
// не inline функции.

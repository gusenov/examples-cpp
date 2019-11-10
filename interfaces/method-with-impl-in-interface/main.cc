#include <string>
#include "iostream"

struct IEmployee
{
  virtual ~IEmployee() = default;
  virtual std::string const& GetFirstName() const = 0;
  virtual std::string const& GetLastName() const = 0;

  virtual std::string GetFullName() const
  {
    return GetFirstName() + " " + GetLastName();
  }
};

class Employee : public IEmployee
{
public:
  Employee(std::string const& firstName, std::string const& lastName):
    firstName_(firstName), lastName_(lastName)
  {}

  ~Employee() override = default;

  std::string const& GetFirstName() const { return firstName_; }
  std::string const& GetLastName() const { return lastName_; }


private:
  std::string firstName_;
  std::string lastName_;
};

int main()
{
  IEmployee* employee = new Employee("John", "Smith");
  std::cout << employee->GetFullName() << std::endl;
  delete employee;
  return 0;
}

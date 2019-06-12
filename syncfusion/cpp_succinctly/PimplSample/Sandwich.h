#pragma once
#include <memory>

class SandwichImpl;

class Sandwich {
public:
  Sandwich(void);
  ~Sandwich(void);

  void AddIngredient(const wchar_t* ingredient);
  void RemoveIngredient(const wchar_t* ingredient);
  void SetBreadType(const wchar_t* breadType);
  const wchar_t* GetSandwich(void);

private:
  std::unique_ptr<SandwichImpl> m_pImpl;
};

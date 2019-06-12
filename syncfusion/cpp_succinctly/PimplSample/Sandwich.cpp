#include "Sandwich.h"
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Мы можем делать любые изменения, которые хотим в имплементации класса без
// необходимости рекомпиляции других исходных файлов подключающих Sandwich.h
// потому что SandwichImpl дефинирован только здесь в этом исходном файле и
// поэтому только этот исходный файл будет нуждаться в перекомпиляции, если
// сделать какие-то изменения в SandwichImpl:
class SandwichImpl {
public:
  SandwichImpl();
  ~SandwichImpl();

  void AddIngredient(const wchar_t* ingredient);
  void RemoveIngredient(const wchar_t* ingredient);
  void SetBreadType(const wchar_t* breadType);

  const wchar_t* GetSandwich(void);

private:
  vector<wstring> m_ingredients;
  wstring m_breadType;
  wstring m_description;
};

SandwichImpl::SandwichImpl() {}

SandwichImpl::~SandwichImpl() {}

void SandwichImpl::AddIngredient(const wchar_t* ingredient) {
  m_ingredients.emplace_back(ingredient);
}

void SandwichImpl::RemoveIngredient(const wchar_t* ingredient) {
  auto it = find_if(m_ingredients.begin(), m_ingredients.end(),
    [=] (wstring item) -> bool {
      return (item.compare(ingredient) == 0);
    }
  );

  if (it != m_ingredients.end()) { m_ingredients.erase(it); }
}

void SandwichImpl::SetBreadType(const wchar_t* breadType) {
  m_breadType = breadType;
}

const wchar_t* SandwichImpl::GetSandwich(void) {
  m_description.clear();
  m_description.append(L"A ");
  for (auto ingredient : m_ingredients) {
    m_description.append(ingredient);
    m_description.append(L", ");
  }
  m_description.erase(m_description.end() - 2, m_description.end());
  m_description.append(L" on ");
  m_description.append(m_breadType);
  m_description.append(L".");

  return m_description.c_str();
}

Sandwich::Sandwich(void) : m_pImpl(new SandwichImpl()) {}

Sandwich::~Sandwich(void) {}

void Sandwich::AddIngredient(const wchar_t* ingredient) {
  m_pImpl->AddIngredient(ingredient);
}

void Sandwich::RemoveIngredient(const wchar_t* ingredient) {
  m_pImpl->RemoveIngredient(ingredient);
}

void Sandwich::SetBreadType(const wchar_t* breadType) {
  m_pImpl->SetBreadType(breadType);
}

const wchar_t* Sandwich::GetSandwich(void) { return m_pImpl->GetSandwich(); }

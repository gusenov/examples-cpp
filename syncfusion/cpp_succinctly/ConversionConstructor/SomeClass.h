#include <string>

class SomeClass {
  public:
    SomeClass(const wchar_t* value) : m_strValue(value), m_intValue() {}
    explicit SomeClass(int value) : m_strValue(), m_intValue(value) {}
    ~SomeClass(void) {}
    const wchar_t* GetStringValue(void) { return m_strValue.c_str(); }
    int GetIntValue(void) { return m_intValue; }
  private:
    std::wstring m_strValue;
    int m_intValue;
};

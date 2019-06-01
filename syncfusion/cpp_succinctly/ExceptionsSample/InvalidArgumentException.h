#pragma once
#include <exception>
#include <stdexcept>
#include <string>
#include <sstream>

namespace CppForCsExceptions {
  class InvalidArgumentExceptionBase : public std::invalid_argument {
    public:
      InvalidArgumentExceptionBase(void) : std::invalid_argument("") { }
      virtual ~InvalidArgumentExceptionBase(void) throw() { }
      virtual const char* what(void) const throw() override = 0;
  };

  template <class T>
  class InvalidArgumentException : public InvalidArgumentExceptionBase {
    public:
      inline InvalidArgumentException(const char* className,
                                      const char* functionSignature,
                                      const char* parameterName,
                                      T parameterValue);
      inline virtual ~InvalidArgumentException(void) throw();
      inline virtual const char* what(void) const throw() override;
    private:
      std::string	m_whatMessage;
  };

  template<class T>
  InvalidArgumentException<T>::InvalidArgumentException(
    const char* className,
    const char* functionSignature,
    const char* parameterName,
    T parameterValue) : InvalidArgumentExceptionBase(), m_whatMessage() {
      std::stringstream msg;
      msg << className << "::" << functionSignature
          << " - parameter '" << parameterName
          << "' had invalid value '" << parameterValue << "'.";
      m_whatMessage = std::string(msg.str());
  }

  template<class T>
  InvalidArgumentException<T>::~InvalidArgumentException(void) throw() {}

  template<class T>
  const char* InvalidArgumentException<T>::what(void) const throw() {
    return m_whatMessage.c_str();
  }
}

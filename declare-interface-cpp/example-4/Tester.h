#include "IBase.h"

#include <string>

class Tester : public IBase {
  public:
    Tester(std::string name);
    virtual ~Tester();
    virtual void Describe();
  private:
    std::string privatename;
};

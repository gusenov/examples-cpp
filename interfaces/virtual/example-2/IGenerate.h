#ifndef IGENERATE_H
#define IGENERATE_H

class IGenerate {
  public:
    virtual ~IGenerate() = default;

    virtual int Generate(void) = 0;
};

#endif

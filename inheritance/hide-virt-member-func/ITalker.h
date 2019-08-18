#ifndef ITalker_h
#define ITalker_h

#include <iostream>


struct ITalker {
    virtual ~ITalker() = default;
    virtual void SaySomething() {
        std::cout << "something" << std::endl;
    }
};

#endif /* ITalker_h */

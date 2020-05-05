#include <cstdlib>
#include <random>
#include <limits>
#include <iostream>

struct Pair {
    float f[2];
};

struct Triple {
    double d[3];
};

template<typename T, typename U, std::size_t LEN, T (U::*DataGetter)[LEN]>
class Processor {
public:
    Processor(U const& dat) {
        dat_ = dat;
    }

    virtual ~Processor() = default;

    void Multiply(int factor) {
        for (std::size_t i = 0; i < LEN; ++i) {
            (dat_.*DataGetter)[i] *= factor;
        }
    }

    void Print() {
        std::cout << "{ ";
        for (std::size_t i = 0; i < LEN; ++i) {
            std::cout << (dat_.*DataGetter)[i] << " ";
        }
        std::cout << "}" << std::endl;
    }

protected:
    U dat_;
};

class PairProcessor: public Processor<float, Pair, 2, &Pair::f> {
public:
    PairProcessor(Pair const& p) : Processor<float, Pair, 2, &Pair::f>(p) {
    }

    ~PairProcessor() override = default;
};

class TripleProcessor: public Processor<double, Triple, 3, &Triple::d> {
public:
    TripleProcessor(Triple const &t) : Processor<double, Triple, 3, &Triple::d>(t) {
    }

    ~TripleProcessor() override = default;
};

int main() {

    PairProcessor pp({ .f = { 10, 20 } });
    pp.Multiply(2);
    pp.Print();  // { 20 40 }

    TripleProcessor tp({ .d = { 10, 20, 30 } });
    tp.Multiply(2);
    tp.Print();  // { 20 40 60 }

    return EXIT_SUCCESS;
}

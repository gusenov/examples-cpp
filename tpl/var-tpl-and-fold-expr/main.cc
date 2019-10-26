#include <iostream>




#define BR std::cout << "--" << std::endl;




struct IA {
    virtual ~IA() = default;

    virtual int GetValue1() = 0;

    static int Id() { return 0; }
    static void PrintId() { std::cout << Id() << std::endl; }
};

struct IB : IA {
    ~IB() override = default;

    virtual int GetValue2() = 0;

    static int Id() { return 1; }
    static void PrintId() { std::cout << Id() << std::endl; }
};

struct IC : IB {
    ~IC() override = default;

    virtual int GetValue3() = 0;

    static int Id() { return 2; }
    static void PrintId() { std::cout << Id() << std::endl; }
};

class C : public IC {
public:
    C() = default;
    ~C() override = default;

    int GetValue1() override { return 1; }
    int GetValue2() override { return 2; }
    int GetValue3() override { return 3; }
};

struct ID: IA {
    ~ID() override = default;
};

struct IE {
    virtual ~IE() = default;
};




template <class T>
void PrintId1() {
    std::cout << T::Id() << std::endl;
}

template<class ...TParams>
void PrintId2()
{
    (TParams::PrintId(), ...);
}

template<class ...TParams>
void PrintId3()
{
    (PrintId1<TParams>(), ...);
}

void test1() {
    PrintId1<IA>();
    // 0

    BR

    PrintId2<IA, IB, IC>();
    // 0
    // 1
    // 2

    BR

    PrintId3<IA, IB, IC>();
    // 0
    // 1
    // 2
}




void PrintValue(IA* a) {
    std::cout << "GetValue1() = " << a->GetValue1() << std::endl;
}

void PrintValue(IB* b) {
    std::cout << "GetValue2() = " << b->GetValue2() << std::endl;
}

void PrintValue(IC* c) {
    std::cout << "GetValue3() = " << c->GetValue3() << std::endl;
}

void PrintValue(ID* d) {
    std::cout << "PrintValue for ID ptr" << std::endl;
}

void PrintValue(IE* e) {
    std::cout << "PrintValue for IE ptr" << std::endl;
}

template<class ...TParams, class TClass>
void PrintAllValues(TClass *c)
{
    (
        (
            dynamic_cast<TParams *>(c) ? PrintValue(dynamic_cast<TParams *>(c))
                                       : static_cast<void>(0)
        )
        , ...
    );
}




int main(int argc, char const * argv[]) {
    IC *c = new C();

    PrintAllValues<IA, IB, IC, ID, IE>(c);

    delete c;

    return 0;
}

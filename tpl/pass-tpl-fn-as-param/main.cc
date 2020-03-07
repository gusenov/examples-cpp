#include <memory>
#include <iostream>

template<typename TDat>
class MyCls {
public:
    MyCls() = default;
    ~MyCls() = default;

    void SetDat(TDat dat) {
        dat_ = dat;
    }

    TDat GetDat() const {
        return dat_;
    }

private:
    TDat dat_;
};

template<class TDat, typename TProc>
void MyProcFunc(MyCls<TDat> &obj, TProc Proc) {
    Proc(obj, 33);
}

template<class TDat>
void Print(MyCls<TDat> &obj, int opt) {
    std::cout << "int opt" << std::endl;
    std::cout << obj.GetDat() << std::endl;
}

template<class TDat>
void Print(MyCls<TDat> &obj, float opt) {
    std::cout << "float opt" << std::endl;
    std::cout << obj.GetDat() << std::endl;
}

template<typename TProc>
void foo(TProc Proc) {
    MyCls<int> obj1;
    obj1.SetDat(2020);
    Proc(obj1, 20);

    MyCls<int> obj2;
    obj2.SetDat(29);
    Proc(obj2, 28.0f);
}

template<class TDat, typename TOpt>
using ExecFunc = void(*)(MyCls<TDat> &, TOpt opt);

struct Printer {
    template<typename TDat, typename TOpt>
    void operator()(MyCls<TDat> &obj, TOpt opt) const {
        Print(obj, opt);
    }
};

template<typename TProc>
void bar(TProc Proc) {
    MyCls<int> obj1;
    obj1.SetDat(2020);
    Proc(obj1, 20);

    MyCls<int> obj2;
    obj2.SetDat(29);
    Proc(obj2, 28.0f);
}

int main(int argc, char const * argv[]) {
    {
        std::cout << "Test # 1" << std::endl;

        MyCls<int> obj;
        obj.SetDat(2020);
        ExecFunc<int, int> fnPtr = &Print<int>;
        MyProcFunc(obj, fnPtr);
        // Test # 1
        // int opt
        // 2020
    }

    {
        std::cout << "Test # 2" << std::endl;

        ExecFunc<int, float> fnPtr = &Print<int>;
        foo(fnPtr);
        // Test # 2
        // float opt
        // 2020
        // float opt
        // 29
    }

    {
        std::cout << "Test # 3" << std::endl;

        ExecFunc<int, float> fnPtr = &Print<int>;
        bar(Printer());
        // Test # 3
        // int opt
        // 2020
        // float opt
        // 29
    }

    return 0;
}

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

template<class TDat>
using ProcFunc = void(*)(MyCls<TDat> &);

template<class TDat>
void MyProcFunc(MyCls<TDat> &obj) {
    std::cout << obj.GetDat() << std::endl;
}

int main(int argc, char const * argv[]) {
    MyCls<int> obj;
    obj.SetDat(2020);

    //MyProcFunc(obj);
    // 2020

    ProcFunc<int> fnPtr = &MyProcFunc;
    fnPtr(obj);
    // 2020

    return 0;
}

#include <cstdlib>
#include <iostream>

class MyClass {
public:
    MyClass(int data): data_(data) {
        std::clog << "MyClass() # " << data_ << std::endl;
    }

    ~MyClass() {
        std::clog << "~MyClass() # " << data_ << std::endl;
    }

    void Print() {
        std::cout << "# " << data_ << std::endl;
    }

private:
    int data_;
};

void fn(MyClass** objects, int const sz) {
    for (int j = 0; j < sz; ++j) {
        objects[j]->Print();
    }
}

int main(int argc, char const* argv[]) {
    int const N = 3;

    MyClass* objects[N] = {};
    for (int i = 0; i < N; ++i) {
        objects[i] = new MyClass(i);
    }
    // MyClass() # 0
    // MyClass() # 1
    // MyClass() # 2

    fn(objects, N);
    // # 0
    // # 1
    // # 2

    for (int i = 0; i < N; ++i)
        delete objects[i];
    // ~MyClass() # 0
    // ~MyClass() # 1
    // ~MyClass() # 2

    return EXIT_SUCCESS;
}

#include <vector>
#include <iostream>

class Model {
public:
    Model(int i) : i_(i) {};
    int GetInt() const {
        return i_;
    }
private:
    int i_;
};

void PrintVector(std::vector<const Model*>* v) {
    for (std::vector<const Model* const>::size_type i = 0; i != v->size(); ++i) {
        std::cout << (*v)[i]->GetInt() << std::endl;
    }

}

int main(int argc, char* argv[]) {
    // std::vector<const Model* const> v;
    // const Model* const a = new Model(1);
    // error: cannot initialize a parameter of type 'void *' with an lvalue of type
    // 'const Model *const *'

    // The vector is probably the only container that requires the elements to
    // be copy assignable. This is because the elements are guaranteed to be
    // stored contiguously in memory. So if you exceed the capacity, a new
    // chunk has to be allocated and elements re-assigned. You cannot do
    // this with const elements.
    // https://stackoverflow.com/a/29378601

    std::vector<const Model*> v;
    const Model* const a = new Model(1);
    v.push_back(a);

    PrintVector(&v);
    // 1

    std::vector<Model*> v2;
    Model* const b = new Model(2);
    // v2.push_back(a);  // error: no matching member function for call to 'push_back'
    v2.push_back(b);
    // PrintVector(&v2);  // error: no matching function for call to 'PrintVector'

    return 0;
}

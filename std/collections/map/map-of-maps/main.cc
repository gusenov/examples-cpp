#include <iostream>
#include <string>
#include <unordered_map>




class MyClass {
public:
    MyClass() {
        id_ = ++id;
        std::cout << "MyClass()  #" << id_ << std::endl;
    }

    // Конструктор копирования:
    MyClass(MyClass const &other) {
        id_ = ++id;
        std::cout << "MyClass const &other  #" << id_ << std::endl;
    }

    // Конструктор перемещения,
    // noexcept - для оптимизации при использовании стандартных контейнеров:
    MyClass(MyClass &&other) noexcept {
        id_ = ++id;
        std::cout << "MyClass(MyClass &&other)  self.#" << id_ << ", other.#" << other.GetId() << std::endl;
    }

    // Деструктор:
    ~MyClass() {
        std::cout << "~MyClass()  #" << id_ << std::endl;
    }

    // Оператор присваивания копированием (copy assignment):
    MyClass & operator=(MyClass const &other) {
        std::cout << "MyClass & operator=(MyClass const &other)" << std::endl;

        if (this == &other)
            return *this;

        return *this;
    }

    // Оператор присваивания перемещением (move assignment):
    MyClass & operator=(MyClass &&other) {
        std::cout << "MyClass & operator=(MyClass &&other)  #" << id_ << " = #" << other.GetId() << std::endl;

        if (this == &other)
            return *this;

        return *this;
    }

    int GetId() const {
        return id_;
    }

private:
    int id_ = 0;
    static int id;
};


// non-const static data member must be initialized out of line:
int MyClass::id = 0;




void test1() {
    std::unordered_map < std::string,
                         std::unordered_map<std::string, MyClass> > mainMap;

    std::unordered_map<std::string, MyClass> innerMap1;

        MyClass innerMap1_value1;
        // MyClass()  #1

        std::pair<std::string, MyClass> innerMap1_pair1("innerMap1_key1",
                                                         innerMap1_value1);
        // MyClass const &other  #2
        // При добавлении MyClass в STL-контейнеры вызывается copy constructor.

        innerMap1.insert( innerMap1_pair1 );
        // MyClass const &other  #3
}
// ~MyClass()  #2
// ~MyClass()  #1
// ~MyClass()  #3




void test2() {
    std::unordered_map < std::string,
                         std::unordered_map<std::string, MyClass> > mainMap;

    mainMap["mainMap_key1"]["innerMap1_key1"] = MyClass();
    // MyClass()  #1
    // MyClass()  #2
    // MyClass & operator=(MyClass &&other)  #2 = #1
    // ~MyClass()  #1

    assert(mainMap["mainMap_key1"]["innerMap1_key1"].GetId() == 2);

    std::cout << "end;" << std::endl;
    // end;
}
// ~MyClass()  #2




void test3() {
    std::unordered_map<std::string, MyClass> map;
    assert(map.size() == 0);  // true

    map["key1"];
    // MyClass()  #1

    assert(map.size() == 1);  // true

    std::cout << map["key1"].GetId() << std::endl;
    // 1
}
// ~MyClass()  #1




void test4() {
    std::unordered_map<std::string, MyClass> map;
    map.insert( { "key1", MyClass() } );
    // MyClass()  #1
    // MyClass(MyClass &&other)  self.#2, other.#1
    // MyClass(MyClass &&other)  self.#3, other.#2
    // ~MyClass()  #2
    // ~MyClass()  #1

    std::cout << "end;" << std::endl;
    // end;
}
// ~MyClass()  #3




int main(int argc, char const * argv[]) {
    //test1();
    //test2();
    //test3();
    //test4();
    std::cout << "end." << std::endl;
    return 0;
}

#include <memory>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <limits>




class Item {
public:
    Item(float weight = 0.0f): weight_(weight) {
        std::cout << "Item(" << weight_ << ")" << std::endl;
    }

    ~Item() {
        std::cout << "~Item()  // weight=" << weight_ << std::endl;
    }

    float GetWeight() const {
        return weight_;
    }

    void SetWeight(float weight) {
        weight_ = weight;
    }

private:
    float weight_;
};




void test1() {
    std::vector<std::shared_ptr<Item>> items;

    std::shared_ptr<Item> item;

    item = std::make_shared<Item>(1.0f);
    // Item(1)
    items.push_back(item);

    item = std::make_shared<Item>(2.0f);
    // Item(2)
    items.push_back(item);

    item = std::make_shared<Item>(3.0f);
    // Item(3)
    items.push_back(item);

    auto it = std::begin(items);
    while (it != std::end(items)) {
        auto i = *it;
        assert(i == *it);  // TRUE
        // *it возвращает ссылку.
        // Здесь эта ссылка копируется в значение.
        // Поэтому удаляемые элемент будеет жить до конца итерации.

        if (2.0f == i->GetWeight()) {
            it = items.erase(it);
            std::cout << "erase" << std::endl;
            // erase
        } else {
            ++it;
        }
        // ~Item()  // weight=2
    }

    std::cout << "end;" << std::endl;
    // end;
}
// ~Item()  // weight=3
// ~Item()  // weight=1




void test2() {
    std::vector<std::shared_ptr<Item>> items;

    std::shared_ptr<Item> item;

    item = std::make_shared<Item>(1.0f);
    // Item(1)
    items.push_back(item);

    item = std::make_shared<Item>(2.0f);
    // Item(2)
    items.push_back(item);

    item = std::make_shared<Item>(3.0f);
    // Item(3)
    items.push_back(item);

    auto it = std::begin(items);
    while (it != std::end(items)) {
        auto &i = *it;
        assert(i == *it);  // TRUE
        // *it возвращает ссылку.
        // Здесь эта ссылка остается ссылкой.

        if (2.0f == i->GetWeight()) {
            it = items.erase(it);
            // ~Item()  // weight=2
            // Элемент сразу удаляется потому что на него больше нет умных указателей.

            std::cout << "erase" << std::endl;
            // erase
        } else {
            ++it;
        }

        // i->SetWeight(std::numeric_limits<float>::max());  // !
    }
    std::cout << "end;" << std::endl;
    // end;
}
// ~Item()  // weight=3
// ~Item()  // weight=1




int main(int argc, char const * argv[]) {
    //test1();
    test2();

    std::cout << "end." << std::endl;
    // end.
    return EXIT_SUCCESS;
}

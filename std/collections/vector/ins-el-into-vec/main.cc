#include <iostream>
#include <cstdlib>
#include <vector>

class Item {
public:
    Item(float val) : val_(val) {
    }
    
    ~Item() {
    }
    
    float GetValue() const {
        return val_;
    }
    
    void SetValue(float val) {
        val_ = val;
    }
    
private:
    float val_;
};

template<typename TIt>
bool ItemCmp(TIt* a, TIt* b) {
    return a->GetValue() < b->GetValue();
};

class ItemCol {
public:
    ItemCol() {
    }
    
    ~ItemCol() {
    }
    
    void Add(Item* newItem) {
        auto itPos = std::find_if(items_.begin(), items_.end(), [newItem] (auto const& item) {
            return !ItemCmp(item, newItem);
            // Ищем случай, когда существующий элемент станет НЕ МЕНЬШЕ (или >=) нового элемента. 
            // В эту позицию будет вставка.
            // Существующий элемент сдвинется вправо.
        });

        // assert(itPos == items_.end());
        // При пустом items_ переменная itPos будет равна items_.end() и 
        // вставка все же произойдет.
        
        items_.insert(itPos, newItem);
    }
    
    void Print() {
        for (auto const& item : items_) {
            std::cout << item->GetValue() << " ";
        }
        std::cout << std::endl;
    }
    
    bool IsEquals(std::vector<float> const& otherVec) {
        bool result = items_.size() == otherVec.size();
        if (!result)
            return result;
        
        for (int i = 0; i < items_.size(); ++i)
            if (items_.at(i)->GetValue() != otherVec.at(i)) {
                result = false;
                break;
            }
        
        return result;
    }
    
private:
    std::vector<Item*> items_;
};

int main(int argc, char* argv[]) {
    ItemCol itemCol;
    
    itemCol.Add(new Item(5));
    assert(itemCol.IsEquals({5}));

    itemCol.Add(new Item(10));
    assert(itemCol.IsEquals({5, 10}));
    
    itemCol.Add(new Item(7));
    assert(itemCol.IsEquals({5, 7, 10}));

    itemCol.Add(new Item(6));
    assert(itemCol.IsEquals({5, 6, 7, 10}));

    itemCol.Add(new Item(8));
    assert(itemCol.IsEquals({5, 6, 7, 8, 10}));

    return EXIT_SUCCESS;
}

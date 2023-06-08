#include <iostream>
#include <vector>

class Item
{
public:
    Item(int aData)
        : m_data(aData)
    {}

    Item(Item const& aOther)
        : m_data(aOther.m_data)
    {
        std::cout << "Item ctor" << std::endl;
    }

    int GetData() const
    {
        return m_data;
    }

private:
    int m_data;
};

class Collection
{
public:
    Collection()
    {}

    Collection(Collection const& aOther)
        : m_items(aOther.m_items)
    {
        std::cout << "Collection ctor" << std::endl;
    }

    std::vector<Item> const& GetItems() const
    {
        return m_items;
    }

    void AddItem(Item const& aItem)
    {
        m_items.push_back(aItem);
    }

private:
    std::vector<Item> m_items;
};

int main()
{
    Collection collection;

    Item item(10);
    collection.AddItem(item);

    collection.AddItem(Item(20));

    std::cout << "Test # 1" << std::endl;
    auto items1 = collection.GetItems();

    std::cout << "Test # 2" << std::endl;
    auto const& items2 = collection.GetItems();

    std::cout << "end." << std::endl;
    return 0;
}

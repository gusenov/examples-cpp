#include <unordered_map>

enum class Key {
    k1,
    k2,
    k3,
};

struct Value {
    int i;
    Value(): i(0) {}
};

Value GetValue(std::unordered_map<Key, Value> &umap, Key key) {
    auto pos = umap.find(key);
    return pos == umap.end() ? Value() : pos->second;
}

int main(int argc, char const * argv[]) {
    std::unordered_map<Key, Value> umap;


    Value v1;
    v1.i = 1;
    umap.insert({ Key::k1, v1 });
    assert ( GetValue(umap, Key::k1).i == 1 );  // TRUE


    Value v2;
    v2.i = 2;
    umap.insert({ Key::k1, v2 });
    assert ( GetValue(umap, Key::k1).i == 1 );  // TRUE!


    Value v3;
    v3.i = 3;
    umap[Key::k1] = v3;
    assert ( GetValue(umap, Key::k1).i == 3 );  // TRUE


    Value v4;
    v4.i = 4;
    umap[Key::k2] = v4;
    assert ( GetValue(umap, Key::k2).i == 4 );  // TRUE


    umap.erase(Key::k3);
    Value v5;
    v5.i = 5;
    umap.insert({ Key::k3, v5 });
    assert ( GetValue(umap, Key::k3).i == 5 );  // TRUE


    umap.erase(Key::k3);
    Value v6;
    v6.i = 6;
    umap.insert({ Key::k3, v6 });
    assert ( GetValue(umap, Key::k3).i == 6 );  // TRUE


    return 0;
}

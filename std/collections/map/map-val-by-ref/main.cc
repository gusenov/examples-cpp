#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

struct Record {
    int value = 0;
};

int main() {

    std::vector<Record> vec;

    Record &rec = vec.emplace_back();
    rec.value = 2306;

    std::unordered_map<std::string, Record &> map;
    // map["A"] = rec;
    // error: reference to type 'Record' requires an initializer

    // STL container value types need to be assignable.
    // References are not assignable.
    // You cannot assign them a different object to reference.
    // https://stackoverflow.com/a/4239291/12847278

    return 0;
}

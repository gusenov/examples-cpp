#include <string>
#include <sstream>
#include <iostream>

class Date {
public:

    Date(int d, int m, int y) : d_(d), m_(m), y_(y) {}

    std::string string_rep() const {  // string representation
        if (!cache_valid) {
            compute_cache_value();
            cache_valid = true;
        }
        return cache;
    }

private:

    mutable bool cache_valid;
    mutable std::string cache;

    void compute_cache_value() const {
        std::stringstream strstream;
        strstream << d_ << "/" << m_ << "/" << y_;
        cache = strstream.str();
    }

    int d_, m_, y_;
};

void f(Date d, const Date cd) {
    std::string s1 = d.string_rep();
    std::string s2 = cd.string_rep();
    assert(s1 == s2);
    std::cout << s1 << std::endl;
}

int main() {
    Date d(14, 1, 2020);
    f(d, d);
    return 0;
}

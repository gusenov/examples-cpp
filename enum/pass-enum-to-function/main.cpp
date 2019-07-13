//---------------------------------------------------------------------------
// Демонстрация передачи перечисления в функцию.
//---------------------------------------------------------------------------

#include <iostream>

using namespace std;

// Scoped enumeration:
enum class Color { Red, Orange, Yellow, Blue, Indigo, Violet };

// Unscoped enumeration:
enum Flavor : unsigned short int { Vanilla, Chocolate, Strawberry, Mint };

void print(int usi) {
    cout << "void print(int usi)" << endl;
    switch (usi) {
        case Vanilla: cout << "Vanilla" << endl; break;
        case Chocolate: cout << "Chocolate" << endl; break;
        case Strawberry: cout << "Strawberry" << endl; break;
        case Mint: cout << "Mint" << endl; break;
    }
}

/*
// При определении этой функции она возьмет на себя вызов функции:
// Flavor f = Mint;
// print(f);
void print(Flavor& f) {
    cout << "void print(Flavor& f)" << endl;
    switch (f) {
        case Vanilla: cout << "Vanilla" << endl; break;
        case Chocolate: cout << "Chocolate" << endl; break;
        case Strawberry: cout << "Strawberry" << endl; break;
        case Mint: cout << "Mint" << endl; break;
    }
}
*/

int main(int argc, char** argv) {
    Flavor f = Mint;
    print(f);
    // void print(int usi)
    // Mint

    return 0;
}

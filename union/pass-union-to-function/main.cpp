//---------------------------------------------------------------------------
// Демонстрация передачи объединения в функцию.
//---------------------------------------------------------------------------

#include <iostream>

using namespace std;

//---------------------------------------------------------------------------
// The general syntax for a struct declaration in C is:
struct tag_name {
   int member1;
   float member2;
   /* declare as many members as desired,
      but the entire structure size must be known to the compiler. */
};
// Here tag_name is optional in some contexts.

// Such a struct declaration may also appear in the context of a typedef
// declaration of a type alias or the declaration or definition of a variable:
// typedef struct tag_name {
//    type member1;
//    type member2;
// } struct_alias;
// Often, such entities are better declared separately, as in:
typedef struct tag_name struct_alias;
// These two statements now have the same meaning:
// struct tag_name struct_instance;
// struct_alias struct_instance;

// For example:
struct account {
   int account_number;
   char *first_name;
   char *last_name;
   float balance;
};
// defines a type, referred to as struct account.
// To create a new variable of this type, we can write
struct account s;
//---------------------------------------------------------------------------

union MyUnion_ {
    struct { float a, b, c; };
    bool d;
    struct { float e, f, g; };
    float arr[3];

    // Когда в объединении хранятся три float-а, то все эквивалентные им
    // элементы можно рассматривать как псевдонимы.

    MyUnion_() {
        arr[0] = arr[1] = arr[2] = 0;
    }
};

typedef union MyUnion_ MyUnion;

void PrintArr(MyUnion u) {
    cout << ".arr[0] = " << u.arr[0]
         << " .arr[1] = " << u.arr[1]
         << " .arr[2] = " << u.arr[2]
         << endl;
}

void Inc(union MyUnion_& u) {
    ++u.a;
    u.b++;
    u.c += 1;
}

void Dec(MyUnion* u) {
    --u->e;
    u->f--;
    u->g -= 1;
}

bool operator==(const MyUnion& lhs, const MyUnion& rhs){
    return lhs.arr[0] == rhs.arr[0] &&
           lhs.arr[1] == rhs.arr[1] &&
           lhs.arr[2] == rhs.arr[2];
}

int main(int argc, char* argv[]) {
    MyUnion u1;

    std::cout << "sizeof" << std::endl;
    std::cout << "\tbool = " << sizeof(bool) << std::endl;  // 1
    std::cout << "\tfloat = " << sizeof(float) << std::endl;  // 4
    std::cout << "\tMyUnion = " << sizeof(MyUnion) << std::endl;  // 12
    std::cout << "\tu1 = " << sizeof(u1) << std::endl;  // 12
    std::cout << "\tu1.d = " << sizeof(u1.d) << std::endl;  // 1
    std::cout << "\tu1.arr = " << sizeof(u1.arr) << std::endl;  // 12
    std::cout << std::endl;

    u1.a = 1;
    u1.b = 2;
    u1.c = 3;

    cout << "u1.a = " << u1.a << " u1.b = " << u1.b << " u1.c = " << u1.c << endl;
    // .a = 1 .b = 2 .c = 3
    cout << "u1.e = " << u1.e << " u1.f = " << u1.f << " u1.g = " << u1.g << endl;
    // .e = 1 .f = 2 .g = 3
    PrintArr(u1);
    // .arr[0] = 1 .arr[1] = 2 .arr[2] = 3

    u1.e = 4;
    u1.f = 5;
    u1.g = 6;

    cout << "u1.a = " << u1.a << " u1.b = " << u1.b << " u1.c = " << u1.c << endl;
    // .a = 4 .b = 5 .c = 6
    cout << "u1.e = " << u1.e << " u1.f = " << u1.f << " u1.g = " << u1.g << endl;
    // .e = 4 .f = 5 .g = 6
    PrintArr(u1);
    // .arr[0] = 4 .arr[1] = 5 .arr[2] = 6

    Inc(u1);
    PrintArr(u1);
    // .arr[0] = 5 .arr[1] = 6 .arr[2] = 7

    Dec(&u1);
    PrintArr(u1);
    // .arr[0] = 4 .arr[1] = 5 .arr[2] = 6

    std::cout << std::endl;

    MyUnion u2;
    u2 = u1;

    cout << "u2.e = " << u2.e << " u2.f = " << u2.f << " u2.g = " << u2.g << endl;
    // u2.e = 4 u2.f = 5 u2.g = 6

    // Работает только при переопределенном операторе ==:
    if (u1 == u2) {
        cout << "u1 == u2" << endl;
        // u1 == u2
    }

    u2.e = 40;
    u2.f = 50;
    u2.g = 60;

    return 0;
}

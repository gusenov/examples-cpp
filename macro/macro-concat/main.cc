#if SYSTEM_HEADERS
#include <iostream>
#endif

using namespace std;

//---------------------------------------------------------------------------

#define SIGNAL1 SignalName1
#define SIGNAL2 SignalName2

#define MAKE_FN_NAME(x) void  Callback_ ## x (void)
#define FUNCTION_NAME(signal) MAKE_FN_NAME(signal)

FUNCTION_NAME(SIGNAL1) {
    return;
}

//---------------------------------------------------------------------------

#define MAKE_CLASS(Abc) \
class My##Abc { \
};

MAKE_CLASS(Example)

#define TEST_NAME Test
MAKE_CLASS(TEST_NAME)

#define MAKE_CLASS_WITH_MACRO_ARG(x) MAKE_CLASS(x)
MAKE_CLASS_WITH_MACRO_ARG(TEST_NAME)

//---------------------------------------------------------------------------

#define PRINT(msg) \
cout << msg << endl;

#define PRINTWORD(msg) \
cout << #msg << endl;

//---------------------------------------------------------------------------

int main(int argc, const char * argv[]) {
    Callback_SignalName1();

    MyExample myExample;
    MyTEST_NAME somethingWrong;
    MyTest myTest;

    PRINT("Hello, World!")
    PRINTWORD(hello)

    return 0;
}

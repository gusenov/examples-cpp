#include <iostream>
// /Library/Developer/CommandLineTools/usr/include/c++/v1/iostream

// #include <filesystem>

#include <cstring>


// #include <dirent.h>  // Allows the opening and listing of directories
// /Library/Developer/CommandLineTools/SDKs/MacOSX10.14.sdk/usr/include/dirent.h

// #include <unistd.h>  // Various essential POSIX functions and constants
// /Library/Developer/CommandLineTools/SDKs/MacOSX10.14.sdk/usr/include/unistd.h

// #include <sys/types.h>  // Various data types used elsewhere
// /Library/Developer/CommandLineTools/SDKs/MacOSX10.14.sdk/usr/include/sys/types.h

#include <sys/stat.h>  // File information (stat et al.)
// /Library/Developer/CommandLineTools/SDKs/MacOSX10.14.sdk/usr/include/sys/stat.h

#include <errno.h>

using namespace std;




void test_posix() {
    // $ mkdir test
    // $ stat test
    // drwxr-xr-x

    int status = mkdir("test/b/c", S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH);
    std::cout << "status = " << status << std::endl;
    if (0 != status) {
        int errnum = errno;
        std::cerr << "Ошибка при создании папки:\n\t" << strerror(errnum) << std::endl;

        switch (errnum) {
            case EEXIST:
                std::cerr << "\tПапка уже сущетвует!" << std::endl;
                break;
        }
    }
    
    // Для пути a/b/c выдаст:
    // status = -1
    // Ошибка при создании папки:
    //         No such file or directory
    // Вывод: mkdir не может создавать промежуточные папки.
    
    // Для пути просто test создаст папку:
    // $ stat test
    // drwxr-xr-x
}




void check_os() {
    std::cout << "OS:" << std::endl;

#ifdef __linux__
    std::cout << "\tLinux and Linux-derived" << std::endl;
#endif

#ifdef __ANDROID__
    std::cout << "\tAndroid (заключает в себе __linux__)" << std::endl;
#endif

#if defined(__linux__) && !defined(__ANDROID__)
    std::cout << "\tLinux (non-Android)" << std::endl;
#endif

#ifdef __APPLE__
    std::cout << "\tDarwin (Mac OS X and iOS)" << std::endl;
#endif

#ifdef __ros__
    std::cout << "\tAkaros (http://akaros.org)" << std::endl;
#endif

#ifdef _WIN64
    std::cout << "\tWindows 64 bit (заключает в себе _WIN32)" << std::endl;
#endif

#ifdef _WIN32
    std::cout << "\tWindows" << std::endl;
#endif

#ifdef __native_client__
    std::cout << "\tNaCL" << std::endl;
#endif

#ifdef __asmjs__
    std::cout << "\tAsmJS" << std::endl;
#endif

#ifdef __Fuchsia__
    std::cout << "\tFuschia" << std::endl;
#endif
}




void check_compiler() {
    std::cout << "Compiler:" << std::endl;

#ifdef _MSC_VER
    std::cout << "\tVisual Studio" << std::endl;
#endif

#ifdef __clang__
    std::cout << "\tclang" << std::endl;
#endif

#ifdef __GNUC__
    std::cout << "\tgcc" << std::endl;
#endif

#ifdef __EMSCRIPTEN__
    std::cout << "\temscripten (for asm.js and webassembly)" << std::endl;
#endif

#ifdef __MINGW32__
    std::cout << "\tMinGW 32 или MinGW-w64 32bit" << std::endl;
#endif

#ifdef __MINGW64__
    std::cout << "\tMinGW-w64 64bit" << std::endl;
#endif
}




int main(int argc, char* argv[]) {
    check_os();
    // OS:
    // 	Darwin (Mac OS X and iOS)

    check_compiler();
    // Compiler:
    // 	clang
    // 	gcc

    test_posix();

    return 0;
}

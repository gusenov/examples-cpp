#include <iostream>
#include <fstream>
#include <cstring>

void hello() {
    std::ofstream fout("hello.txt");
    fout << "Hello, World!" << std::endl;
    fout.close();

    // Создаст в текущей папке файл hello.txt и запишет в него строку:
    // Hello, World!\n
}

void hello_world() {
    // ofstream никогда не создает папки!

    std::ofstream fout;

    // Выбрасывать исключение при установке failbit:
    std::ios_base::iostate exception_mask = fout.exceptions() | std::ios::failbit;
    fout.exceptions(exception_mask);

    try {
        fout.open("hello/world.txt", std::fstream::out);
        fout << "Hello, World!" << std::endl;
        fout.close();
    } catch (std::ios_base::failure& e) {
        std::cerr << e.what() << '\n';
        std::cerr << "Error: " << strerror(errno) << std::endl;
    }
    // OUTPUT:
    // basic_ios::clear: iostream error
    // Error: No such file or directory
}

int main(int argc, char* argv[]) {
    hello();
    hello_world();
    return 0;
}

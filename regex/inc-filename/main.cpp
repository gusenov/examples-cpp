#include <iostream>
#include <string>
#include <sstream>
#include <regex>
#include <cstdlib>
#include <cstring>

enum CopyType : unsigned short int {
    FromSameFolder,
    FromAnotherFolder
};

template<typename T, size_t N>
size_t ArraySize(T(&)[N]) {
    return N;
}

std::string files[] = {
      "example.txt"

// Что происходит при copy-paste одного и того же файла в одной и той же папке:
    , "example — копия.txt"
    , "example — копия 2.txt"
    , "example — копия 4.txt"
    , "example — копия 40.txt"
    , "example — копия 100.txt"
    , "example — копия 100500.txt"

// Что происходит при copy-paste файла из другой папки в папку, где уже есть
// файл с таким именем:
    , "example 2.txt"
    , "example 3.txt"
    , "example 5.txt"
    , "example 40.txt"
    , "example 100.txt"
    , "example 100500.txt"

    , "another.txt"

    , "two.txt"
    , "two — копия.txt"

    , "t 3.txt"

    // Скопировать example.txt два раза в одной папке.
    // Скопировать example — копия 2.txt в другую папку.
    // Скопировать обратно.
    , "example — копия 2 2.txt"

    , "b копия 2.txt"
    , "b копия 2 2.txt"

};

std::string GetExtensionFromFileName(const std::string &filename) {
    size_t lastdot = filename.find_last_of(".");
    if (lastdot == std::string::npos)
        return "";
    return filename.substr(lastdot);
}

std::string RemoveExtensionFromFileName(const std::string &filename) {
    size_t lastdot = filename.find_last_of(".");
    if (lastdot == std::string::npos)
        return filename;
    return filename.substr(0, lastdot);
}

template<size_t N>
bool Exists(std::string filename, std::string (&filelist)[N]) {
    for (size_t i = 0; i < N; ++i)
        if (filename == filelist[i])
            return true;
    return false;
}

template<size_t N>
std::string MakeFileName(std::string filename, std::string (&filelist)[N], CopyType type) {
    static const std::regex PATTERN_DUPLICATE(R"(^(.* — копия)( ?)(\d*)$)");
    static const std::regex PATTERN_COPY(R"(^(.*?)( ?)(\d*)$)");

    const std::regex &pattern = type == FromSameFolder ? PATTERN_DUPLICATE : PATTERN_COPY;
    std::smatch match;

    std::string ext = GetExtensionFromFileName(filename);
    std::string resultname = RemoveExtensionFromFileName(filename);

    if (Exists(filename, filelist)) {
        if (type == FromAnotherFolder) {
            resultname += " 2";
        } else if (type == FromSameFolder) {
            if (!std::regex_search(resultname, match, pattern)) {
                resultname += " — копия";
            }
        }
    } else {
        return filename;
    }

    int i = 2;
    while (Exists(resultname + ext, filelist)) {
        if (std::regex_search(resultname, match, pattern)) {
            const std::string num = match[3];
            if (!num.empty()) ++i;
            std::stringstream replace;
            replace << "$1 " << i;
            resultname = std::regex_replace(resultname, pattern, replace.str());
        }
    }

    return resultname + ext;
}

int main(int argc, const char * argv[]) {
    std::cout << "" << std::endl;

    assert("example — копия 3.txt" == MakeFileName("example.txt", files, FromSameFolder));
    assert("example — копия 3.txt" == MakeFileName("example — копия 3.txt", files, FromSameFolder));
    assert("example — копия 3.txt" == MakeFileName("example — копия 4.txt", files, FromSameFolder));

    assert("unique.txt" == MakeFileName("unique.txt", files, FromSameFolder));
    assert("another — копия.txt" == MakeFileName("another.txt", files, FromSameFolder));
    assert("two — копия 2.txt" == MakeFileName("two.txt", files, FromSameFolder));

    assert("t 3 2.txt" == MakeFileName("t 3.txt", files, FromAnotherFolder));

    assert("example — копия 2 2 — копия.txt" == MakeFileName("example — копия 2 2.txt", files, FromSameFolder));
    assert("example — копия 2 2 2.txt" == MakeFileName("example — копия 2 2.txt", files, FromAnotherFolder));
    assert("b копия 2 3.txt" == MakeFileName("b копия 2.txt", files, FromAnotherFolder));

    assert("example 4.txt" == MakeFileName("example.txt", files, FromAnotherFolder));
    assert("example 5 2.txt" == MakeFileName("example 5.txt", files, FromAnotherFolder));

    return EXIT_SUCCESS;
}

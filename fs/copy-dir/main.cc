#include <cstdlib>
#include <string>

#ifdef __APPLE__
#include "filesystem.hpp"
#else
#include <filesystem>
namespace filesystem = std::filesystem;
#endif

int main(int argc, char* argv[])
{
    filesystem::path from(L"/examples-cpp/copy-dir/a");
    filesystem::path to(L"/examples-cpp/copy-dir/b");
    filesystem::copy(from, to, filesystem::copy_options::recursive);

    return EXIT_SUCCESS;
}

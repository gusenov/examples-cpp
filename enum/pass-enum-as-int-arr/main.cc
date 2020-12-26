#include <cstdlib>
#include <iostream>
#include <memory>

namespace Color {
    enum Key : int {
        Red = 3,
        Green = 1,
        Blue = 9,
    };
    
    static const Key RGB[] = {
        Red,
        Green,
        Blue,
    };
    
    static const int iRGB[] = {
        Red,
        Green,
        Blue,
    };
}

void way1(int const *rgb)
{
    std::cout << rgb[0] << rgb[1] << rgb[2] << std::endl;
}

void way2(int const rgb[3])
{
    std::cout << rgb[0] << rgb[1] << rgb[2] << std::endl;
}
    
void way3(int const rgb[])
{
    std::cout << rgb[0] << rgb[1] << rgb[2] << std::endl;
}

int main(int argc, char const* argv[]) {
    // way1(Color::RGB);
    // note: candidate function not viable: no known conversion from 'const Color::Key [3]' to 'const int *' for 1st argument
    
    // way2(Color::RGB);
    // note: candidate function not viable: no known conversion from 'const Color::Key [3]' to 'const int *' for 1st argument
    
    // way3(Color::RGB);
    // note: candidate function not viable: no known conversion from 'const Color::Key [3]' to 'const int *' for 1st argument
    
    // way1(Color::iRGB);  // 319
    // way2(Color::iRGB);  // 319
    // way3(Color::iRGB);  // 319
    
    return EXIT_SUCCESS;
}

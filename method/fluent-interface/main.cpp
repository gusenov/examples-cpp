#include <iostream>
#include <sstream>

class Color
{
public:
    Color()
        : m_red(0)
        , m_green(0)
        , m_blue(0)
    {}

    Color(int r, int g, int b)
        : m_red(r)
        , m_green(g)
        , m_blue(b)
    {
        std::cout << "Color(int r, int g, int b)" << std::endl;
    }

    int GetRed() const { return m_red; }
    int GetGreen() const { return m_green; }
    int GetBlue() const { return m_blue; }

    void SetRGB(int r, int g, int b)
    {
        m_red = r;
        m_green = g;
        m_blue = b;
    }

    std::string ToString() const
    {
        std::stringstream strstream;
        strstream << m_red << " " << m_green << " " << m_blue;
        return strstream.str();
    }

private:
    int m_red;
    int m_green;
    int m_blue;
};

class Fluent
{
public:
    Fluent()
        : m_height(0)
    {}

    int GetHeight() const
    {
        return m_height;
    }

    Fluent& SetHeight(int h)
    {
        std::cout << "SetHeight" << std::endl;

        m_height = h;
        return *this;
    }

    Fluent& ChangeColor(Color& c, int r, int g, int b)
    {
        std::cout << "ChangeColor" << std::endl;

        c.SetRGB(r, g, b);
        return *this;
    }

    Color const& GetColor() const
    {
        return m_color;
    }

    Fluent& SetColor(Color const c)
    {
        std::cout << "SetColor" << std::endl;

        m_color = c;
        return *this;
    }

private:
    int m_height;
    Color m_color;
};

void test1()
{
    Color c;

    Fluent fluent;
    fluent
        .ChangeColor(c, 255, 0, 0)
        .SetHeight(61207)
        .SetColor(c)
    ;

    std::cout << "color = " << fluent.GetColor().ToString() << std::endl;
}
// ChangeColor
// SetHeight
// SetColor
// color = 255 0 0

void test2()
{
    Color c;

    Fluent fluent;
    fluent
        .ChangeColor(c, 255, 0, 0)
        .SetHeight(61207)
        .SetColor( Color(c.GetRed(), c.GetGreen(), c.GetBlue()) )
    ;

    std::cout << "color = " << fluent.GetColor().ToString() << std::endl;
}
// ChangeColor
// SetHeight
// Color(int r, int g, int b)
// SetColor
// color = 255 0 0

int main()
{
    test2();
    return 0;
}

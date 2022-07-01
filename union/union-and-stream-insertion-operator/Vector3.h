#pragma once
#include <type_traits>

union _Vector3
{
    struct { float x, y, z; };

    struct { float r, g, b; };

    float v[3];

    _Vector3(){v[0] = 0.0f; v[1] = 0.0f; v[2] = 0.0f;}

    // Из-за этих двух конструкторов при выводе символа в std::stringstream получим ошибку компиляции:
    // Use of overloaded operator '<<' is ambiguous (with operand types 'std::stringstream' (aka 'basic_stringstream<char>') and 'char')
    _Vector3(int _v){v[0] = (float)_v; v[1] = (float)_v; v[2] = (float)_v;}
    _Vector3(float _v){v[0] = _v; v[1] = _v; v[2] = _v;}

    _Vector3(float x, float y, float z){v[0] = x; v[1] = y; v[2] = z;}
};

typedef union _Vector3 Vector3;

static_assert(std::is_same_v<Vector3, _Vector3>);

static_assert(!std::is_same_v<Vector3, float[]>);
static_assert(!std::is_same_v<Vector3, float[3]>);
static_assert(!std::is_same_v<Vector3, float*>);

/*
template<typename TOutputStream>
TOutputStream& operator<<(TOutputStream& aOutputStream, Vector3 const& aVector3)
{
    aOutputStream << "(" << aVector3.x << ", " << aVector3.y << ", " << aVector3.z << ")";
    return aOutputStream;
}
//*/

//* FIX:
template<typename TOutputStream, typename T>
typename std::enable_if<std::is_same<T, Vector3>::value, TOutputStream&>::type
operator<<(TOutputStream& aOutputStream, T const& aVector3)
{
    aOutputStream << "(" << aVector3.x << ", " << aVector3.y << ", " << aVector3.z << ")";
    return aOutputStream;
}
//*/
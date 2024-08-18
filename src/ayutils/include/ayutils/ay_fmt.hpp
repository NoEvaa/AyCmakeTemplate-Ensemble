#pragma once
#include <string>

namespace iin {

using std::string;

template <class T, typename = void>
struct AyFmt
{
    string toStr(const T&)
    {
        return string();
    }
};

template <class T>
auto ayFmt(const T& v)
{
    return AyFmt<T>().toStr(v);
}
}

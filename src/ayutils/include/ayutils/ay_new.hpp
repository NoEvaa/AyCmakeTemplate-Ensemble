#pragma once
#include <memory>

namespace iin {

using std::shared_ptr;

template <class T, typename = void>
struct AyNew
{
    template <typename... Args>
    shared_ptr<T> make(Args... args)
    {
        return std::make_shared<T>(std::forward<Args>(args)...);
    }
};

template <class T, typename... Args>
auto ayNew(Args... args)
{
    return AyNew<T>().make(std::forward<Args>(args)...);
}
}

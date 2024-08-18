#pragma once
#include <ayutils/ay_new.hpp>
#include <ayutils/ay_fmt.hpp>

#if defined(__GNUC__)
    #define AY_CORE_API __attribute__((visibility("default")))
#elif defined(_WIN32)
    #define AY_CORE_API __declspec(dllexport)
#else
    #define AY_CORE_API
#endif

namespace iin {

template <typename T>
struct AyMatrixPvtData;

class AY_CORE_API AyIntMatrix
{
public:
    int rowSize() const;
    int colSize() const;
    
    int& operator()(int row, int col);
    int operator()(int row, int col) const;

private:
    shared_ptr<AyMatrixPvtData<int>> _p_data;
};

template<>
struct AyFmt<AyIntMatrix>
{
    string toStr(const AyIntMatrix& mx)
    {
        
        return string();
    }
};
}

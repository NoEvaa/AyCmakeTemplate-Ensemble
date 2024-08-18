#pragma once
#include <ayutils/ay_new.hpp>
#include <ayutils/ay_fmt.hpp>
#include <vector>

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

    void reshape(int row, int col, int v = 0);
    
    void fillAll(int v = 0);
    void fillDiag(int v = 1);
    void fillVect(const std::vector<int>&);
    
    operator bool() const;
    
    int& operator()(int row, int col);
    int operator()(int row, int col) const;

private:
    shared_ptr<AyMatrixPvtData<int>> _p_data;
};

AY_CORE_API string _ayToStr(const AyIntMatrix&);

template <>
struct AyFmt<AyIntMatrix>
{
    string toStr(const AyIntMatrix& mx)
    {
        return _ayToStr(mx);
    }
};
}

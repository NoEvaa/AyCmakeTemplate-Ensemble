#pragma once
#include <aypvt/export.h>
#include <cassert>
#include <vector>
#include <algorithm>
#include <string>

namespace iin {
template <typename T>
struct AyMatrixPvtData
{
    using value_type = T;
    using array_type = std::vector<value_type>;

    std::size_t row_ = 0;
    std::size_t col_ = 0;

    array_type data_;

    void init(const value_type& v)
    {
        std::size_t s = row_ * col_;
        data_.reserve(s);
        data_.resize(s, v);
    }

    void fill(const value_type& v)
    {
        std::fill(data_.begin(), data_.end(), v);
    }

    value_type& operator()(std::size_t i, std::size_t j)
    {
        assert(i < row_ && j < col_);
        return data_[i * col_ + j];
    }

    const value_type& operator()(std::size_t i, std::size_t j) const
    {
        assert(i < row_ && j < col_);
        return data_[i * col_ + j];
    }
};

AYPVT_EXPORT std::string ayMatrixName();
}

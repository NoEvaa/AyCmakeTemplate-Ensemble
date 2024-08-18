#include "aycore/ay_core.h"
#include "aypvt/ay_pvt.h"
#include <sstream>

using namespace iin;

string iin::_ayToStr(const AyIntMatrix& mx)
{
    if (!mx)
        return string();

    std::stringstream ss;
    ss << ayMatrixName();
    ss << " shape: ("
        << mx.rowSize()
        << ", "
        << mx.colSize()
        << ")";
    ss << "\n";

    ss << "[";
    for (int r = 0; r < mx.rowSize(); ++r)
    {
        if (r != 0)
        {
            ss << " ";
        }
        ss << "[";
        for(int c = 0; c < mx.colSize(); ++c)
        {
            ss << " ";
            ss << mx(r, c);
        }
        ss << "]\n";
    }
    ss << "]";
    return ss.str();
}

int AyIntMatrix::rowSize() const
{
    if (!_p_data)
        return 0;
    return _p_data->row_;
}

int AyIntMatrix::colSize() const
{
     if (!_p_data)
        return 0;
    return _p_data->col_;
}

void AyIntMatrix::reshape(int row, int col, int v)
{
    if (!_p_data)
    {
        _p_data = ayNew<AyMatrixPvtData<int>>();
    }
    _p_data->row_ = row;
    _p_data->col_ = col;
    _p_data->init(v);
}
    
void AyIntMatrix::fillAll(int v)
{
    if (!_p_data)
        return;
    _p_data->fill(v);
}

void AyIntMatrix::fillDiag(int v)
{
    if (!_p_data)
        return;
    int i = 0;
    while (i < colSize() && i < rowSize())
    {
        (*_p_data)(i, i) = v;
        ++i;
    }
}

void AyIntMatrix::fillVect(const std::vector<int>& vec)
{
    if (!_p_data)
        return;
    int s = colSize() * rowSize();
    if (s > vec.size())
    {
        s = vec.size();
    }
    _p_data->data_ = std::vector(vec.begin(), vec.begin() + s);
}
 
AyIntMatrix::operator bool() const
{
    return bool(_p_data);
}
    
int& AyIntMatrix::operator()(int row, int col)
{
    assert(_p_data);
    return (*_p_data)(row, col);
}

int AyIntMatrix::operator()(int row, int col) const
{
    assert(_p_data);
    return (*_p_data)(row, col);
}


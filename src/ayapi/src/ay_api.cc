#include "ayapi/ay_api.h"

using namespace iin;

AyIntMatrix iin::ayMtxZeros(int row, int col)
{
    AyIntMatrix ret;
    ret.reshape(row, col, 0);
    return ret;
}

AyIntMatrix iin::ayMtxOnes(int row, int col)
{
    AyIntMatrix ret;
    ret.reshape(row, col, 0);
    ret.fillDiag(1);
    return ret;
}


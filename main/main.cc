#include "ayapi/ay_api.h"
#include <iostream>

int main()
{
    std::cout << iin::ayFmt(iin::ayMtxOnes(0, 0)) << std::endl;
    std::cout << iin::ayFmt(iin::ayMtxZeros(1, 1)) << std::endl;
    std::cout << iin::ayFmt(iin::ayMtxZeros(2, 2)) << std::endl;
    std::cout << iin::ayFmt(iin::ayMtxOnes(3, 3)) << std::endl;
    std::cout << iin::ayFmt(iin::ayMtxOnes(2, 4)) << std::endl;
    return 0;
}


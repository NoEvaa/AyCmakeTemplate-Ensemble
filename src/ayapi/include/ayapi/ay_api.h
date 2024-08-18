#pragma once
#include <aycore/ay_core.h>

#define AY_API_API AY_CORE_API

namespace iin {
AY_API_API AyIntMatrix ayMtxZeros(int row, int col);
AY_API_API AyIntMatrix ayMtxOnes(int row, int col);
}

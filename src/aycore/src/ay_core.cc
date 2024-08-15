#include "ay_core/ay_core.h"
#include "ay_pvt/ay_pvt.h"

int iin::ayAdd(int l, int r)
{
    return l + r;
}

bool iin::ayAdd(bool l, bool r)
{
    return l ? !r : r;
}


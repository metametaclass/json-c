
#include "stdafx.h"
#include "math_compat.h"

int main_test_floating()
{
    printf("_fpclass(INFINITY)=%x\n", _fpclass(INFINITY));
    printf("_fpclass(INFINITY1)=%x\n", _fpclass(INFINITY1));

    printf("_fpclass(NAN)=%x\n", _fpclass(NAN));
    printf("isinf(INFINITY)=%d\n", isinf(INFINITY));
    printf("isinf(-INFINITY)=%d\n", isinf(-INFINITY));
    printf("isnan(INFINITY)=%d\n", isnan(INFINITY));
    printf("isnan(-INFINITY)=%d\n", isnan(-INFINITY));

    printf("isinf(NAN)=%d\n", isinf(NAN));    
    printf("isnan(NAN)=%d\n", isnan(NAN));    
    return 0;
}
#include "stdio.h"

int main()
{
    int x = 4, y = -5;
    int result;
    int strong_x = x; 
    int strong_y = y; 

    asm (R"(
        xor %%eax, %%eax
        for: 
            cmp $0, %[X] 
            jz goToEnd 
            shr $1, %[X] 
            jnc checkEven 
            add %[Y], %%eax 
        checkEven: 
            add %[Y], %[Y] 
            jnz for 
            dec %%eax
        goToEnd:
            movl %%eax, %[result]
    )"  : [result]"=m" (result),[X]"+r" (x),[Y]"+r"(y)
        :: "cc", "%eax"
    );

    printf("%d * %d = %d\n", strong_x, strong_y, result);
    return 0;
}

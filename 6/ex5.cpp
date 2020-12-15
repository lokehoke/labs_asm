#include "stdio.h"

int main()
{
    int x = 3, y = 6;
    int result;
    int strong_x = x;
    int strong_y = y;

    asm (R"(
        xor %%eax, %%eax

        for:
            cmp $0, %[X] 
            jz goToEnd 
            sar $1, %[X] 
            jnc ccheckToEven 
            add %[Y], %%eax 

        ccheckToEven: 
            add %[Y], %[Y]
            jnz for 
            cmp $0, %[X] 
            jbe incrIfOdd 
            dec %%eax
        incrIfOdd: 
            inc %%eax
        goToEnd:
            movl %%eax, %[result]
    )"
        : [result]"=m" (result),[X]"+r" (x),[Y]"+r"(y) :: "cc","%eax"
    );

    printf("%d * %d = %d\n", strong_x, strong_y, result);
    return 0;
}

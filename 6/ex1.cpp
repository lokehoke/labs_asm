#include <stdio.h>
int main(){
    unsigned int x = 10, y=0;

    asm
    (R"(
        movl %[X], %[Y]
        lea 1(%[Y], %[Y], 2), %[Y]
        shrl $1, %[X]
        cmovncl %[X], %[Y]
    )"  : [Y]"+r"(y)
        : [X]"rm"(x)
        : "cc"
    );
    printf("%d\n", y);
    return 0;
}

#include <stdio.h>
int main(){
    int x = 10, y=0;

    asm
    (R"(
        movl %[X], %[Y]
        imull $3, %[Y]
        incl %[Y]
        shrl $1, %[X]
        cmovncl %[X], %[Y]
    )"  : [Y]"+r"(y)
        : [X]"rm"(x)
        : "cc"
    );
    printf("%d\n", y);
    return 0;
}

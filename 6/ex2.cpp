#include <stdio.h>
int main(){
    double c = 3,d=2,f=15, x=102, y=0;

    asm(R"(
        fldl %[X] 
        fldl %[d]
        fmulp  
        fldl %[c]
        fdivrp 
        fldl %[f]
        faddp  

        fldl %[X] 
        fldz
        fcomi

        fcmovbe %%st(2), %%st(0) 

        fstpl %[Y] 
        )" : [Y]"=m"(y)
           : [X]"rm"(x), [c]"m"(c), [d]"m"(d), [f]"m"(f)
           : "cc"
    );
    printf("%f\n", y);
    return 0;
}


#include <stdio.h>
#include "math.h"

// 1.2+x / x^2
double calc(double x) {
    return (1.2+x) / pow (x, 2);
}

int main() {
    double c = 1.2, x=10, y;

    asm(
        "fldl %[x]\n"   // загрузка x в стек(в стеке x)
        "fldl %[x]\n"   // загрузка x в стек(в стеке x,x)
        "fmulp\n"       // пермножить x и x(в стеке x^2)
        "fldl %[x]\n"   // загрузка x в стек(в стеке x,x^2)
        "fldl %[c]\n"   // загрузка константы в стек(в стеке 1.2,x,x^2)
 
        "faddp\n"       // сложить константу и x(в стеке 1.2+x,x^2)
        "fdivp\n"       // деление (в стеке 1.2+x / x^2)

        "fstpl %[y]\n"  // кладем значение в y, стек пуст
        :[y]"=m"(y)
        :[x]"m"(x), [c]"m"(c)
        :"cc"
    );

    printf("ASSEMBLER: %f\n",y);
    printf("C++: %f\n", calc(x));
}

#include "stdio.h"
#include "math.h"

template<typename T> 
T Difference(T a, T b) {
    return (a-b);
}

int main() {
    float  a1f=123456789, b1f=123456788, a2f=123456788, b2f=123456787;
    double a1d=123456789, b1d=123456788, a2d=123456788, b2d=123456787;
    printf("a1f: %f\n", a1f);
    printf("b1f: %f\n", b1f);
    printf("a2f: %f\n", a2f);
    printf("b2f: %f\n", b2f);
    printf("a1d: %f\n", a1d);
    printf("b1d: %f\n", b1d);
    printf("a2d: %f\n", a2d);
    printf("b2d: %f\n", b2d);

    printf("FIRST   FLOAT:%f\n", Difference(a1f,b1f));
    printf("SECOND  FLOAT:%f\n", Difference(a2f,b2f));
    printf("FIRST  DOUBLE:%f\n", Difference(a1d,b1d));
    printf("SECOND DOUBLE:%f\n", Difference(a2d,b2d));
    
    return 0;
}

#include <stdio.h>

extern "C" double tass(double x, double c);

int main() {
    printf("%f\n", tass(10,1.2));
    return 0;
}

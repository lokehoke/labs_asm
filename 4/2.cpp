#include <iostream>

using namespace std;

int tass(int x) {
    int y;
    
    asm volatile (R"(
            mov %[x],    %%eax
            shr $1,      %%eax
            add $1,      %%eax
            mov %%eax,   %[y]
        )"
        : [y]"=r"(y)
        : [x]"r"(x)
        : "cc", "%eax"
    );
    
    return y;
};


int main() {
    int x = 10;
    int y = tass(x);
    cout << y << endl;
    return 0;
}

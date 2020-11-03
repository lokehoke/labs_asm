#include <iostream>

using namespace std;

int tass(int x) {
    int y;
    
    asm volatile (R"(
            mov %[x],    %[y]
            shr $1,      %[y]
            add $1,      %[y]
        )"
        : [y]"=r"(y)
        : [x]"r"(x)
        : "cc"
    );
    
    return y;
};


int main() {
    int x = 10;
    int y = tass(x);
    cout << y << endl;
    return 0;
}

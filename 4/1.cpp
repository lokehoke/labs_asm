#include <iostream>

using namespace std;

int main() {
    unsigned p1 = 1;
    unsigned p2 = 2147483600;
    asm goto (
        "add %[p1], %[p2]\n\t"
        "jo  %l2         \n\t"
        ::  [p1]"r"(p1),
            [p2]"r"(p2)
        : "cc"
        : carry
    );
    cout<<"Result is right"<<endl;
    return 0;

    carry: cout<<"Result is wrong"<<endl;
    return 1;
}

#include <iostream>

int main() {
    int N ,ai,x;
    int an0 = 1, an1=1;
    std:: cout << "Enter N: ";
    std::cin >> N;
    
    int * array = new int [N];

    for (int i = 0; i < N; ++i) {
        array[i] = 0;
    }

    asm(R"(
        movl $0, %%ebx
        begin: 
        cmpl %[N], %%ebx
        jz end
        movl %[an0],%%eax
        movl %[array], %%ecx
        movl %%eax,(%%ecx, %%ebx, 4)
        movl %[an1],%%edx
        addl %%edx,%%eax
        movl %[an0],%%edx
        movl %%eax, %[an0]
        movl %%edx, %[an1]
        incl %%ebx
        jmp begin
        end: 
    )"
        :[ai]"+r"(ai),[x]"+r"(x),[N]"+r"(N)
        :[array]"m"(array),[an0]"rm"(an0),[an1]"rm"(an1)
        :"cc","%eax","%ecx","%ebx","memory"
    );
    
    for (int i = 0; i < N; ++i) {
        std::cout << " " << array[i];
    }

    std::cout << std::endl;
    return 0;
}

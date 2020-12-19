#include <iostream>

struct KeyValuePair {
    int key;
    int value;
};

int main() {
    srand(100);
    int N = 15;
    struct KeyValuePair * array = new struct KeyValuePair[N];

    for (int i = 0 ; i < N ; i++) {
        array[i].key=rand()%5;
        array[i].value=rand()%(100)+1;
        printf("Key = %d, Value = %d\n",array[i].key,array[i].value);
    }

    int key = 4;
    int min = 0;
    int max = 1000;

    asm (R"(
        movl $1, %%eax
        movl %[max], %%edx
        movl $0, %%eax
        Start:
        cmpl %[N], %%eax
        je Exit
        movl %[array], %%ecx
        leal (%%ecx, %%eax, 8), %%ecx
        movl (%%ecx),%%ecx
        cmpl %[key],%%ecx
        jne isOurKey
        movl %[array], %%ecx
        leal 4(%%ecx, %%eax, 8), %%ecx
        movl (%%ecx),%%ecx
        cmpl %%edx,%%ecx
        ja isOurKey
        movl %%ecx,%%edx
        isOurKey: 
        incl %%eax
        jmp Start
        Exit:
        movl %%edx, %[min]
    )"
        : [min]"=m" (min)
        : [array]"rm" (array), [N]"m"(N),[key]"m"(key),[max]"m"(max)
        : "cc","%eax","%edx","%ecx"
    );

    if (min == max) {
        std::cout << "No such elements:" << key << std::endl;
    } else {
        std::cout << "MIN (with key "<< key << ") = " << min << std::endl;
    }

    delete [] array;
    return 0;
}

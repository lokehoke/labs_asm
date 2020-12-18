#include <iostream> 
#include <ctime> 
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 

int main() { 
    srand(time(0)); 
    int N = 0; 
    std::cout  <<  "Enter array size: "; 
    std::cin >> N;
    int* array = new int [N]; 
    std::cout << "Size of one element:" << sizeof(array[0]) << std::endl; 
    std::cout << "Random int array:" << std::endl; 
    for(size_t i=0 ; i < N; i++) { 
        array[i] = rand() % N; 
        std::cout << " " << array[i]; 
    } 
    std::cout << "\n"; 
    int min = 0; 
    asm (R"(
        push %%eax
        push %%ebx
        push %%ecx
        movl $1, %%eax
        movl %[array], %%ebx
        movl (%%ebx), %%ebx
        Start:
        cmpl %[N], %%eax
        je Exit
        movl %[array], %%ecx
        leal (%%ecx, %%eax, 4), %%ecx
        movl (%%ecx),%%ecx
        cmpl %%ebx, %%ecx
        jnbe lable
        movl %%ecx, %%ebx
        lable:
        incl %%eax
        jmp Start
        Exit:
        movl %%ebx, %[min]
        pop %%ecx
        pop %%ebx
        pop %%eax
    )"
    : [min]"+m" (min) 
    : [array]"m" (array), [N]"m"(N) 
    : "cc" 
    ); 
    std::cout << "Minimum:" << min << std::endl;
    delete [] array; 
    return 0; 
}

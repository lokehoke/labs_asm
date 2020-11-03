#include <stdio.h>

// 1
void ASCIIToNumber(unsigned int ascii_number) {
    unsigned int result;
    asm ( "and $0x0F, %[a]" : "=r" (result) :  [a]"r"(ascii_number));
    printf("0x%X ASCII is %u\n", ascii_number, result);
}

// 2
void NumberToASCII(unsigned int ascii_number) {
    unsigned int result;
    asm ( "xor $0x30, %[a]" : "=r" (result) : [a]"r"(ascii_number));
    printf("%u is ASCII 0x%X \n",ascii_number, result);
}

// 3
void ToLower(unsigned int symbol) {
    unsigned int result;
    asm ( "xor $0x20, %[a]" : "=r" (result) : [a]"r"(symbol));
    printf("%c to lower is: %c \n", symbol, result);
}
// 4
void ToUpper(unsigned int symbol) {
    unsigned int result;
    asm ( "xor $0x20, %[a]" : "=r" (result) : [a]"r"(symbol));
    printf("%c to upper is: %c \n", symbol, result);
}

int main() {
    ASCIIToNumber(0x30);
    ASCIIToNumber(0x34);
    ASCIIToNumber(0x39);

    printf("\n");

    NumberToASCII(0);
    NumberToASCII(2);
    NumberToASCII(9);

    printf("\n");

    ToLower('A');
    ToLower('O');
    ToLower('X');

    printf("\n");

    ToUpper('a');
    ToUpper('o');
    ToUpper('x');
    return 0;
}

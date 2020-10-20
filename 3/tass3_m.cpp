#include <stdio.h>

extern "C" void Watch(int first, int second)
{
    printf("First number  %d\n",first);
     printf("Second number  %d\n",second);
}

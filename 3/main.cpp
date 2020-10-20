#include <stdio.h>
using namespace std;

extern "C" int tass(int x);

int main()
{
        for (int i = 0; i < 28; i+=4)
        {
                printf("x = %d  ;  y= %d ",i, tass(i));
                printf("\n");
        }

        return 0;
}

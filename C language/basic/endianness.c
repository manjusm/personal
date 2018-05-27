#include <stdio.h>


int main()
{
    int x = 0x2030;
    char *ptr = (char *)&x;

    if (*ptr == 0x30){
        printf("Little Endian\n");
    } else {
        printf("Big Endian\n");
    }
    return;
}

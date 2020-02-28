#include <stdio.h>

int main()
{
    unsigned int x = 0xAABBCCDD;
    printf("Original value : 0x%x\n", x);
    unsigned char *s = (unsigned char *)&x;
    x = (unsigned int)( s[0] << 24 | s[1] << 16 | s[2] << 8 | s[3]);
    printf("Converted value : 0x%x\n", x);
    return;
}

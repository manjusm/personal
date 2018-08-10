#include <stdio.h>

int main()
{
    extern int x;
    x = 100;
    return;
}

static int x;

#include <stdio.h>

int main(int c, char *argv[])
{
    printf("Number of Parameters : %d\n", c);
    printf("%s\t%s\n", argv[0], argv[1]);
    
    int n = 0;
    int i = 0;
    while(*(argv[1]+i) >= '0' && *(argv[1]+i) <= '9'){
        n = (10 * n) + (*(argv[1] + i) - '0');
        i++;
    }
    printf("%d\n", n);
    return;
}

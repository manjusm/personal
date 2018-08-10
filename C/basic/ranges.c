#include <stdio.h>

/* Get the range of different data types on this machine */

int main()
{
    printf("Minimum signed char %d\n", -(char)((unsigned char) ~0 >> 1) - 1);
    printf("Maximum signed char %d\n", (char)((unsigned char) ~0 >> 1));
    
    printf("Minimum unsigned char %d\n", ((unsigned char) 0 ));
    printf("Maximum unsigned char %d\n", (unsigned char) ~0 );
    printf("Sizeof int : %d\n", sizeof(int)); 
    printf("Minimum signed int %d\n", -(int)((unsigned int) ~0 >> 1) - 1);
    printf("Maximum signed int %d\n", (int)((unsigned int) ~0 >> 1));
    
    return;
}

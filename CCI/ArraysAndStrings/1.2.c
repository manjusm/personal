/* An algorithm to determine the duplicate element in a string */

#include <stdio.h>

int main()
{
    char str[] = "Hello";
    int len = 0;
    char *end = str;
    int i = 0;
    char temp;

    while(*end++){
        len++;
    }
    
    for (i = 0; i < len/2; i++){
        temp = str[len-1-i];
        str[len-1-i] = str[i];
        str[i] = temp;
    }
    printf("%s\n", str);
    return 0;    
}

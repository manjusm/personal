/* Reverse words in a given string */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void reverseWords(char *str, char *rev, int len)
{
    int i = 0, j = 0, k;
    int count = 0;
    char *temp = rev;
    for (j = 0, k = 0, i = len -1; i >= 0; i--, j++){
        if (' ' == str[i]){
            memcpy((temp+k), (str+i+1), count);
            temp[j] = ' ';
            k = j+1;
            count = 0;
        } else {
            count++;
        }
    }
    if (count){
        memcpy((temp+k), (str+i+1), count);
    }
    rev[len] = '\0';
    return;
}


int main()
{
    char *str = "I love programming very much";
    char *rev = NULL;

    int len = strlen(str);

    if (len){
        rev = (char*)malloc(len+1);
        if (NULL == rev){
            printf("Malloc() failed\n");
            exit(0);
        }
    }
    printf("%s\n", str);
    reverseWords(str, rev, len);
    printf("%s\n", rev);
    return 0;
}

/* Reverse input string */
/* 1. Get the lenth of the input string.
 * 2. Exchange characters at the beginning with the end ones.
 * 3. Do it till the beginning index is less than the end index.
 * */
#include <stdio.h>

#define MAXSIZE 120

void reverse(char [], int len);
int getLine(char [], int );

void reverse(char str[], int length){
    int i = 0;
    int len = length -1; 
    char temp;
    while(i <= len){
        temp = str[i];
        str[i] = str[len];
        str[len] = temp;
        i++; len--;
    }

    str[length] = '\0';
}

int getLine(char str[], int limit){
    int i = 0;
    int c;
    while(i < limit -1 && ((c = getchar()) != EOF && c != '\n')){
        str[i] = c;
        i++;
    }
    if (c == '\n'){
        str[i] = c;
        i++;
    }
    str[i] = c;
    i++;
    return i;
}

int main()
{
    char str[MAXSIZE];
    int len, i = 0;
    while (len = getLine(str, MAXSIZE)){
        printf("%s\n", str);
        reverse(str, len);
        printf("%s\n", str);
    }
    return;
}


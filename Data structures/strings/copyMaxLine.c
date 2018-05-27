#include <stdio.h>

#define MAXLINE 120

/* while (there's another line)
    if (it's longer than the previous longest)
        (save it)
        (save its length)
    print longest line */

void copy(char [], char []);
int getLine(char [], int );

void copy(char dest[], char source[]){
    int i = 0;
    while((dest[i] = source[i]) != '\0'){
        i++;
    }
    return;
}

int getLine(char input[], int limit){
    int c;
    int i = 0;

    while( i < limit - 1 && ((c = getchar()) != EOF && c != '\n')){
        input[i] = c;
        i++;
    }

    if (c == '\n'){
        input[i] = c;
        i++;
    }
    input[i] = '\0';
    return i;
}

int main()
{
    char input[MAXLINE];
    char longLine[MAXLINE];

    int len = 0;
    int max = 0;
    while((len = getLine(input, MAXLINE)) > 0){
        if (len > max){
            max = len;
            copy(longLine, input);
        }
    }
    if (max > 0) {
        printf("%s\n", longLine);
    }
    return;
}

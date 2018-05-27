#include <stdio.h>
#include "calc.h"

int isdigit(int c){
    return(c >= '0' && c <= '9');
}

/* Get next character or numeric operand */
int getop(char s[]){
    int i, c;

    while((s[0] = c = getch()) == ' ' || c == '\t');
    s[1] = '\0';
    if (!isdigit(c)){
        return c;
    }
    i = 0;
    while ( isdigit(c)){
        s[++i] = c = getch();
    }
    s[i] = '\0';
    if (c != EOF){
        ungetch(c);
    }
    return NUMBER;
}

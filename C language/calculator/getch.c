#include <stdio.h>
#include "calc.h"

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

/* Get a character : Possibly a pushed back character */
int getch(void){

    return ((bufp > 0) ? buf[--bufp] : getchar());
}

/* Push character back to the input */
void ungetch(int c){
    if (bufp >= BUFSIZE){
        printf("ungetch: too many characters \n");
    } else {
        buf[bufp++] = c;
    }
    return;
}

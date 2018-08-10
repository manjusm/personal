#include <stdio.h>
#include "calc.h"
#include <ctype.h>
#include <stdlib.h>

int main(){
    int type;
    char s[MAXOP];
    int op2;

    while((type = getop(s)) != EOF){
        switch(type){
            case NUMBER:
                /* Push the operands to the stack */
                push(atoi(s));
                break;
            case '+':
                /* Pop the operand and perform operation */
                push(pop() + pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '*':
                push(pop() * pop());
                break;
            case '/':
                op2 = pop();
                if (0 == op2){
                    printf("Divide by 0 error\n");
                    exit(0);
                }
                push(pop() / op2);
                break;
            case '\n':
                printf("Result : %d\n", pop());
                break;
            default:
                printf("Unsupported Operation\n");
                exit(0);
        }
    }

    return;
}

#include <stdio.h>

int add (int, int);
int sub (int, int);

int (*func_ptr)(int, int);

int add (int a, int b) {
    return a + b;
}

int sub (int a, int b) {
    return a - b;
}

int main () 
{
    int a = 20;
    int b = 30;

    int sum;

    func_ptr = &add;
    sum = func_ptr(a, b);

    printf("%d\n", sum);

    func_ptr = &sub;

    sum = func_ptr(a, b);

    printf("%d\n", sum);

    return 0;
}

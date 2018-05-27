#include <stdio.h>
#include <time.h>

int fibonacciRecursion(int n)
{
    if (n <= 1) {   
        return n;
    }
    
    return (fibonacciRecursion(n-1) + fibonacciRecursion(n-2));
}

int fibonacciIterative(int n)
{

    int previous = 0;
    int current = 1;
    int i; 
    for( i = 2; i <= n; i++)
    {
        int temp = previous;
        previous = current;
        current = current + temp;
    }

    return current;

}


int main()
{
    int n = 50;
    clock_t start, end;
    double cpu_time_used;
    start = clock();

    int fib = fibonacciRecursion(n);    

    end = clock();
    cpu_time_used = ((double)(end-start))/CLOCKS_PER_SEC;    
    printf("%lf\n", cpu_time_used);

    start = clock();
    
    fib = fibonacciIterative(n);

    end = clock();
    cpu_time_used = ((double)(end - start))/CLOCKS_PER_SEC;
    printf("%lf\n", cpu_time_used);
    return;
}

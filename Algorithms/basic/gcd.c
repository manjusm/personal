#include <stdio.h>
#include <time.h>

int getgcd(int a, int b)
{
    int gcd, i, loop;

    if (a == 0 || b == 0) {
        return a+b;
    }
    gcd = 0; 
    loop = (a < b) ? (a) : (b);
    for (i = 1; i<= loop; i++) {
        if (!(a%i) && !(b%i)) {
            gcd = i;
        }
    }

    return gcd;
}

int euclidGcd(int a, int b)
{
    if (a == 0 || b == 0) {
        return a+b;
    }
    a = a % b;
    return euclidGcd(b, a);
}

int main()
{
    int a = 92000005;
    int b = 92999945;

    clock_t start, end;
    double cpu_time_used;

    start = clock();
    int gcd = getgcd(a, b);
    end = clock();
    cpu_time_used = ((double)(end - start))/CLOCKS_PER_SEC;
    printf("%lf\n", cpu_time_used);
    
    start = clock();
    gcd = euclidGcd(a, b);
    end = clock();
    cpu_time_used = ((double)(end - start))/CLOCKS_PER_SEC;
    printf("%lf\n", cpu_time_used);
    printf("%d\n", gcd);    
    return;
}

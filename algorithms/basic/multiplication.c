/* 
 * This algorithm is known an a la russe, resembles the one used 
 * in the hardware of a binary computer.
 * All we need to know is how to add up and divide a number by 2.
 * We don't have to memorize the multiplication table.
 */

#include <stdio.h>

int main()
{
    int m, n, result;
    printf("Enter pisitive Multiplicand:");
    scanf("%d", &m);
    printf("Enter positive Multiplier:");
    scanf("%d", &n);

    result = 0;
    if (!m || !n) {
        return result;
    }
    while (m >= 1) {
        if ( m % 2 ) {  // if m is odd, add n to result. 
            result += n;
        }
        m = m / 2; // Divide m by 2.
        n = n + n; // add n to itself
    }
    printf("%d\n", result);
    return;
}

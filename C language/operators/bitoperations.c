#include <stdio.h>

/* getbits(x, p, n)
 * returns the (right adjusted) n-bit field of x that begins at position p.
 * We assume that bit position 0 is at the right end and that n and p are sensible positive values.
 */
int getbits(int x, int position, int nBits){

    return ((x >> (position + 1 - nBits)) & ~(~0 << nBits));
}

/* setbits(x,p,n,y)
 * returns x with the n bits that begin at position p set to the 
 * rightmost n bits of y, leaving the other bits unchanged.
 */

int setbits(int x, int position, int nBits, int y){
    return x;
}

/* invert(x, p, n)
 * returns x with the n bits that begin at position p inverted 
 * (i.e., 1 changed into 0 and vice versa), leaving the others unchanged
 */

int invert (int x, int position, int nBits){
    return x;
}

/* rightrot(x, n)
 * returns the value of the integer x rotated to the right by n positions.
 */
int rightrot(int x, int nBits){
    return x;
}

int main()
{
    int x = 0x33;
    int y = 0x12;
    printf("getbits(x, p, n) : %d\n", getbits(x, 6, 3));
    printf("setbitsbits(x, p, n, y) : %d\n", setbits(x, 6, 3, y));
    printf("invert(x, p, n) : %d\n", invert(x, 6, 3));
    printf("rightrot(x, n) : %d\n", rightrot(x, 3));
    return;
}

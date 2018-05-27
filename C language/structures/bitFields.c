#include <stdio.h>
#include <stdlib.h>

/* A bit-field shall have a type that is a qualified or unqualified version of
 * _Bool, signed int, unsigned int, or some other implementation defined type */

/* Any operator that works at BYTE level cannot applied for bit fields.
 * Some of the example are, &, sizeof, const and volatile */

typedef struct int_s
{
    unsigned int sign:1;
    int exponent:8;
    unsigned int mantissa:23;
    char x;
    char y;
    short z;
    char x1;
} int_t; //12 bytes

typedef struct short_s
{   
    unsigned short x:12;
    char c;
    unsigned short y:12;
    int b;
} short_t; // 12 bytes

typedef struct chat_s
{
    char x:4;
    char y:5;
    char z:8;
    short a;
} char_t; // 3 bytes

typedef struct test_s
{
    short xy;
    int yx;
    char v;
}test_t;

int main()
{
    printf("sizeof(fp_t) : %d\nsizeof(short_t) : %d\nsizeof(char_t) : %d\n sizeof(test_t) : %d\n", 
            sizeof(int_t), sizeof(short_t), sizeof(char_t), sizeof(test_t));
    return;
}

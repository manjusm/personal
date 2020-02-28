/* Merge sort */

#include <stdio.h>

int main()
{
    int input[] = {10, 7, 4, 12, 8, 2, 13};
    int output[7] = {0};
    int i, j, size;

    size = sizeof(input)/sizeof(input[0]);

    printf("Before sorting : ");
    for (int i = 0; i < size; i++){
        printf("%d\t", input[i]);
    }
    printf("\n");

    printf("After sorting : ");
    for (int i = 0; i < size; i++){
        printf("%d\t", output[i]);
    }
    printf("\n");

    return 0;

}

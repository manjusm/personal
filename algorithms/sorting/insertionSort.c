
/* Insertion sort */

#include <stdio.h>

int main()
{
    int input[] = {10, 7, 8, 4, 11, 23, 1};
    int i, j, y;
    int size = sizeof(input)/sizeof(input[0]);
    
    printf("Before sorting : ");
    for (i = 0; i < size; i++){
        printf("%d\t", input[i]);
    }
    printf("\n");

    for (i = 1; i < size; i++){

        y = input[i];
        /* insert y at the right position */
        for(j = i-1; j >= 0 && y < input[j]; j--){
            input[j+1] = input[j];
        }
        /* value of would have been decremented by now. so j+1*/
        input[j+1] = y;
    }

    printf("After sorting : ");
    for (i = 0; i < size; i++){
        printf("%d\t", input[i]);
    }
    printf("\n");
    return 0;
}

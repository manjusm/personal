/* Selection sort */

#include <stdio.h>

int main()
{
    int input[] = {50, 40, 30, 20, 60, 70, 25};
    
    int n = sizeof(input)/sizeof(input[0]);
    int i, j, min, index;
    int temp;

    printf("input : ");
    for (int i = 0; i < n; i++){
        printf("%d\t", input[i]);
    }
    printf("\n");

    /* pick the minimum element and place it properly at the beginning */
    for (i = 0; i < n; i++){
        min = input[i];
        index = -1;
        for (j = i+1; j < n; j++){
            if (min > input[j]){
                min = input[j];
                index = j;
            }
        }
        if (-1 != index){
            input[index] = input[i];
            input[i] = min;
        }
    }

    printf("output : ");
    for (int i = 0; i < n; i++){
        printf("%d\t", input[i]);
    }
    printf("\n");

    return 0;
}

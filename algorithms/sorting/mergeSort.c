/* Merge sort */

#include <stdio.h>

void merge(int input[], int low, int mid, int high)
{
    int i, j, k;
    i = low;
    j = mid + 1;
    k = 0;
    int temp[10] = {0};

    while(i <= mid && j <= high) {
        if (input[i] <= input[j]){
            temp[k++] = input[i++];
        } else {
            temp[k++] = input[j++];
        }
    }

    while(i <= mid){
        temp[k++] = input[i++];
    }

    while(j <= high){
        temp[k++] = input[j++];
    }

    for (i = low, j = 0; i <= high; i++, j++){
        input[i] = temp[j];
    }

    return;
}

int mergeSort(int input[], int low, int high)
{
    int mid;
    if(low < high) {
        mid = (low + high)/2;
        /* Divide and conquor */
        mergeSort(input, low, mid);
        mergeSort(input, mid+1, high);
        /* Combine */
        merge(input, low, mid, high);
    }

    return 0;
}

int main()
{
    int input[] = {10, 7, 4, 12, 8, 2, 13};
    int i, j, size;

    size = sizeof(input)/sizeof(input[0]);

    printf("Before sorting : ");
    for (int i = 0; i < size; i++){
        printf("%d\t", input[i]);
    }
    printf("\n");

    mergeSort(input, 0, size-1);

    printf("After sorting : ");
    for (int i = 0; i < size; i++){
        printf("%d\t", input[i]);
    }
    printf("\n");

    return 0;
}

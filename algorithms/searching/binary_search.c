#include <stdio.h>

int binarySearch(int input[], int low, int high, int element)
{
    int mid = (high + low)/2;

    if (low > high){
        return -1;
    }

    if (element == input[mid]){
        return mid;
    }

    if (element < input[mid]){
        binarySearch(input, low, mid-1, element);
    } else {
        binarySearch(input, mid+1, high, element);
    }
}

int main()
{
    int input[] = {10, 20, 30, 40, 50};
    
    int low = 0;
    int high = (sizeof(input)/sizeof(input[0])) - 1;
    int element = 10;

    int index = binarySearch(input, low, high, element);
    if (-1 != index){
        printf("element is found at index : %d\n", index);
    } else {
        printf("Element is not found in the input array\n");
    }

    return 0;
}

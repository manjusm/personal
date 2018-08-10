/* Sort an array of names or strings */

#include <stdio.h>

int mycompare(const void *a, const void *b)
{
    return strcmp(*(const char **)a, *(const char **)b);
}

void sort(const char * arr[], int n)
{
    qsort(arr, n, sizeof(const char *), mycompare);
    return;
}

int main()
{
    const char *arr[] = {"Geeks", "Manju", "abc", "xyz"};
    int n = sizeof(arr)/sizeof(arr[0]);

    int i = 0;
    for (i = 0; i < n; i++) {
        printf("%s\t", arr[i]);
    }
    printf("\n");

    /* Sort the strings */ 
    sort(arr, n);

    for (i = 0; i < n; i++) {
        printf("%s\t", arr[i]);
    }
    printf("\n");
    return;

}

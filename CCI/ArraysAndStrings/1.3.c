/* Given 2 strings, write an algorithm to determine whether one is permutation of the other */

#include <stdio.h>
#include <string.h>

int main()
{
    char *str1 = "Something is important";
    char *str2 = "Something is important ";
    
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    
    int arr[256] = {0};
    int i = 0;
    int index = 0;

    if (len1 != len2){
        printf("Strings are not permutations of each other\n");
        return 0;
    }

    for(i = 0; i < len1; i++){
        index = str1[i];
        arr[index]++;
    }

    for (i = 0; i < len2; i++){
        index = str2[i];
        arr[index]--;
    }

    for (i = 0; i < 256; i++){
        if (arr[i] != 0){
            printf("Strings are not permutation of each other\n");
            return 0;
        }
    }

    printf("Strings are permutation of each other\n");
    return 0;
}

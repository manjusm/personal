#include <stdio.h>
#include <string.h>

int patternSearch(char string[], char pattern[]) {

    int stringLength = strlen(string);
    int patternLength = strlen(pattern);
    
    printf("string length : %d\npattern length : %d\n", stringLength, patternLength);

    int i = 0;
    int j = 0;
    int k = 0;
    int matchedLength = 0;

    for (i = 0; i < stringLength; i++) {
        matchedLength = 0;
        k = i;
        for (j = 0; j < patternLength; j++) {
            if (pattern[j] == string[k]) {
                matchedLength++;
                if (patternLength == matchedLength) {
                    return i;
                }
                k++;
            } else {
                break;
            }
        }     
    }

    return -1;
}

int main() 
{
    char string[] = "Manjunatha S M";
    char pattern[] = "tha S M";
    
    int ret = patternSearch(string, pattern);
    if (ret != -1) {
        printf("Pattern is found at position %d\n", ret);
    } else {
        printf("Pattern is not present in string\n");
    }

    return 0;
}

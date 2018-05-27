#include <stdio.h>

void swap(char **str1, char **str2)
{
    char *temp = *str1;
    *str1 = *str2;
    *str2 = temp;
    return;
}

int main()
{
    char *str1 = "Manju";
    char *str2 = "SM";
    swap(&str1, &str2);
    printf("%s %s\n", str1, str2);
    return;
}

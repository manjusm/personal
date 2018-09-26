#include <iostream>
#include <string.h>

using namespace std;

int main() {
    char str[] = "Manju";
    const char *str1 = "Manju";

    cout<<sizeof(str)<<endl;
    cout<<strlen(str1)<<endl;

    return 0;
}

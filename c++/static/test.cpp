#include "math.h"
#include <iostream>

using namespace std;

int Math::pow(int base, int exp){
    int res=1;
    while(exp--){
        res *= base;
    }

    return res;
}

int main(){
    Math *math = new Math();
    int res = math->pow(2, 5);
    cout<<res<<endl;
}

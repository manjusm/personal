#include <iostream>
#include "mymath.h"
#include <math.h>

using namespace MyMath;
using namespace std;

int main(){

    int result = math::pow(2, -5);
    cout<<result<<endl;

    result = math::pow(2, 5);
    cout<<result<<endl;

    result = pow(2, 5);
    cout<<result<<endl;
    return 0;

}

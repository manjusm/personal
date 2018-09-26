#include <iostream>

using namespace std;

float simpleIntrest(int, int, float r = 2.5);

float simpleIntrest(int p, int t, float r) {
    float si = (p * t * r) / 100;
    return si;
}

int main()
{
    int si = simpleIntrest(1000, 12);
    cout<<"si : "<<si<<endl;
    return 0;
}

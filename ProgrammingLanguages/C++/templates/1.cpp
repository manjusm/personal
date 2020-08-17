#include <iostream>

using namespace std;

template <class T> T sum (T a, T b)
{
    return (a + b);
}


int main()
{
    int x = 10, y = 20;
    int s = sum(x, y);
    cout << s <<endl;
    double l = 20.5, m = 21.5;
    double d = sum(l, m);
    cout << d << endl;
    return 0;
}

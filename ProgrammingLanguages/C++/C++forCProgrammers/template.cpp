#include <iostream>

using namespace std;

template <class T>
void myswap(T& i, T& j)
{
    T temp = i;
    i = j;
    j = temp;
}

int main()
{
    int x = 10;
    int y = 20;
    myswap(x, y);

    double i = 12.2;
    double j = 22.3;
    myswap(i, j);

    cout<<"x = "<<x<<" y = "<<y<<endl;

    cout<<"i = "<<i<<" j = "<<j<<endl;

    return 0;
}

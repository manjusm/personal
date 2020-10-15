#include <iostream>

using namespace std;

inline void swap(int& i, int& j)
{
    int temp = i;
    i = j;
    j = temp;
}

inline void swap(double& i, double& j)
{
    double temp = i;
    i = j;
    j = temp;
}

int main()
{
    int x = 10;
    int y = 20;
    swap(x, y);

    double i = 12.2;
    double j = 22.3;
    swap(i, j);

    cout<<"x = "<<x<<" y = "<<y<<endl;

    cout<<"i = "<<i<<" j = "<<j<<endl;

    return 0;
}

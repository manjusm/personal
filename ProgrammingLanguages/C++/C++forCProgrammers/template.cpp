#include <iostream>

using namespace std;

template <class T>
void myswap(T& i, T& j)
{
    T temp = i;
    i = j;
    j = temp;
}

// Sum an array - Const, default parameter, variable number of arguements.
template <class T>
T arraySum( const T array[], int size, T sum = 0)
{
    for (int i = 0; i < size; i++)
    {
        sum += array[i];
    }
    return sum;
}

int main()
{
    int x = 10;
    int y = 20;
    myswap(x, y);

    double i = 12.2;
    double j = 22.3;
    myswap(i, j);

    double array[] = {5.25, 5.25, 5.25, 5.25};
    int size = (int) (sizeof(array)/sizeof(array[0]));
    cout<<"size = "<<size<<endl;
    double sum = arraySum(array, size);

    cout<<"x = "<<x<<" y = "<<y<<endl;

    cout<<"i = "<<i<<" j = "<<j<<endl;

    cout<<"Sum = "<<sum<<endl;

    return 0;
}

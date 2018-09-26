#include <iostream>

using namespace std;

int & max(int &x, int &y)
{
    if (x > y) {
        return x;
    } 
    return y;
}

int main()
{
    int x = 10;
    int y = 20;
    max(x,y) = -1;

    cout<<"x :"<<x<<"\n"<<"y :"<<y<<endl;

    return 0;
}

#include <iostream>

using namespace std;

int m = 100;

int main()
{

    int m = 200;
    while(1)
    {
        int m = 300;
        cout<<"::m = "<<::m<<endl;
        break;
    }
    
    cout<<"::m = "<<::m<<endl;
    return 0;
}

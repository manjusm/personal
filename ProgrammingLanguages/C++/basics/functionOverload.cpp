#include <iostream>

using namespace std;

float area(float);
float area(float, float);

float area(float side) {
    return side * side;
}

float area(float length, float breadth) {
    return length * breadth;
}

int main()
{
    float square = area(5);
    float rectangle = area(5, 4);

    cout<<"square : "<<square<<"\n"<<"rectangle :"<<rectangle<<endl;
    return 0;
}

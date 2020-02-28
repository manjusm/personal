#include "unaryOperator.h"

Test::Test() {
    cout<<"default constructor"<<endl;
}

Test::Test(int x, int y, int z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

void Test::operator -() {
    x = -x;
    y = -y;
    z = -z;
}

Test::~Test() {
    cout<<"destructor"<<endl;
}

void Test::showTest() {
    cout<<this->x<<endl;
    cout<<this->y<<endl;
    cout<<this->z<<endl;
}

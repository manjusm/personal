#include "unaryOperator.h"

int main() 
{
    Test t1(10, 20, -30);
    t1.showTest();
    -t1;
    t1.showTest();
    return 0;
}

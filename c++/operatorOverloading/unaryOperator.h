#include <iostream>

using namespace std;

class Test
{
    private:
        int x;
        int y;
        int z;
    public:
        Test();
        Test(int, int, int);
        void operator -();
        void showTest();
        ~Test();
};

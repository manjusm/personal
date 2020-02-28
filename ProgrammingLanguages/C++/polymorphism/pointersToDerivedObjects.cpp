#include <iostream>

using namespace std;


class Base
{
    public:
        int x;

        Base() {
            cout<<"Base constructor"<<endl;
        }

        void show (void) {
            cout<<"Base"<<endl;
            return;
        }

        ~Base() {
            cout<<"Base destructor"<<endl;
        }
};

class Derived : public Base
{
    public:
        int y;

        Derived() {
            cout<<"Derived constructor"<<endl;
        }

        void show (void)
        {
            cout<<"Derived"<<endl;
            return;
        }

        ~Derived() {
            cout<<"Derived destructor"<<endl;
        }
};

int main()
{
    Base *bptr = NULL;
    Derived *dptr = NULL; 

    Derived d;
    bptr = &d;
    bptr->show();

    return 0;
}

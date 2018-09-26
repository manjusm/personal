#include <iostream>

using namespace std;


class Base
{
    public:
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
    Derived d;
    d.show();
    d.Base::show();

    return 0;
}

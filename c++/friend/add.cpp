#include <iostream>

using namespace std;

class B;   //forward declaration

class A
{   
    private:
        int data;
    public:
        void setData(int data) {
            this->data = data;
        }
    friend int add(A, B);
};

class B
{
    private:
        int data;
    public:
        void setData(int data) {
            this->data = data;
        }
    friend int add(A, B);
};

int add (A a, B b) {

    return a.data + b.data;
}

int main()
{
    A a;
    B b;

    a.setData(10);
    b.setData(20);

    cout<<add(a, b)<<endl;

    return 0;
}

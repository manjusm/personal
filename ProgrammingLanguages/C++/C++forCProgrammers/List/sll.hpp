#include <iostream>

using namespace std;

class listElement
{
    public:
        listElement(int data = 0, listElement *ptr = nullptr)
        {
            cout<<"ListElement constructor"<<endl;
            this->data = data;
            this->next = ptr;
        }
        ~listElement()
        {
            cout<<"ListElement destructor"<<endl;
        }
        int data;
        listElement *next;
};

class sll
{
    public:
        sll(listElement *h = nullptr, listElement *c = nullptr):head(h), cursor(c)
        {
            cout<<"sll Constructor"<<endl;
        }
        void prepend(int n);
        int getElement() { return cursor->data; }
        void reverse();
        void print();
        ~sll();
    private:
        listElement *head;
        listElement *cursor;
};

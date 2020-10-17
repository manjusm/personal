#include "sll.hpp"

sll::~sll()
{
    cout<<"SLL destructor"<<endl;
    cursor = head;
    while(nullptr != cursor)
    {
        cursor = head->next;
        delete head;
        head = cursor;
    }
}

void sll::print()
{
    listElement *temp = head;
    while(temp != nullptr)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
    return;
}

void sll::prepend(int n)
{
    head = new listElement(n, head);

    cursor = head;
    return;
}

void sll::reverse()
{
    if ((nullptr == head) || (nullptr == head->next))
    {
        return;
    }
    listElement *prev = nullptr;
    listElement *current = head;
    listElement *next;

    while(current)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    head = prev;
    cursor = head;
    return;
}

int main()
{
    //Create SLL
    sll *list = new sll(nullptr, nullptr);

    //Insert elements
    for (int i = 0; i < 10; i++)
    list->prepend(i*i);

    //Display list
    cout<<"Display list :";
    list->print();

    //get one element
    cout<<"Head element is "<<list->getElement()<<endl;

    //reverse list
    cout<<"Reverse list :"<<endl;
    list->reverse();

    //Display list
    cout<<"Display list :";
    list->print();

    //get one element
    cout<<"Head element is "<<list->getElement()<<endl;
    delete list;

    return 0;
}

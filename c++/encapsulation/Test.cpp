#include "person.h"
#include <string>
#include <iostream>

using namespace std;

int main()
{
    Person *p = new Person("Manju", "Architect", 33);
    cout<<p->getName()<<endl;
    cout<<p->getProfession()<<endl;
    cout<<p->getAge()<<endl;

    p->setName("Manju SM");
    cout<<p->getName()<<endl;
    p->setAge(-10);
    return 0;
}

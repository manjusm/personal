#include "constructors.h"

int main() {
    
    Person p1;
    //Test Block scope
    {
        Person p2(30, "SM");
        p2.showPerson();
    }
    p1.showPerson();
    return 0;
}

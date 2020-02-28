#include <iostream>
#include "person.h"
#include "student.h"

using namespace std;

int main() {
    
    student *stu = new student("Manju", 30, "c++", 2000);
    stu->setAge(25); 
    stu->getNameAge();
    stu->getDetails();
    delete stu;

    return 0;
}

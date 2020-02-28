#include <string>
#include "person.h"

using namespace std;

Person::Person()
{
    //default constructor
}

Person::Person(string name, string profession, int age)
{
    this->name = name;
    this->profession = profession;
    this->age = age;
}

void Person::setAge(int age)
{
    if (age < 0) {
        printf("Invalid entry for age\n");
        return;
    }
    this->age = age;
}

int Person::getAge()
{
    return this->age;
}

void Person::setName(string name)
{
    this->name = name;
}

string Person::getName()
{
    return this->name;
}

void Person::setProfession(string profession)
{
    this->profession = profession;
}

string Person::getProfession()
{
    return this->profession;
}

Person::~Person()
{
    //default destructor
}


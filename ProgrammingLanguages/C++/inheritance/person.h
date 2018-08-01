#pragma once

#include <string>

using namespace std;

class person
{
    private:
        string name;

    protected:
    int age;

    public:
    person();
    person(string name, int age);
    void setAge(int age);
    void getNameAge() const;
};

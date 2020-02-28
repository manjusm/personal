#include <string>

#pragma once

using namespace std;

class Person {

    private:
        int age;
        string name;
        string profession;

    public:
        
        Person();
        Person(string, string, int);

        void setAge(int);
        int getAge();

        void setName(string);
        string getName();

        void setProfession(string);
        string getProfession();

        ~Person();
};

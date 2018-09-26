#include <string>
#include <iostream>

using namespace std;

class Person
{
    private:
        int age;
        string name;

    public:
        Person();
        Person(int, string);
        ~Person();
        void showPerson(void);
};

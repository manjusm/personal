#pragma once

#include <string>

using namespace std;

class Person{
	public :
	    Person();
	    Person(string firstname, string lastname);
	    Person(string firstname, string lastname, int age);
	    ~Person();
	    void sayHello();
	    int getAge();

	private:
	    std::string firstname;
	    std::string lastname;
	    int age;
};

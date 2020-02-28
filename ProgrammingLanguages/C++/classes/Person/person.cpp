#include "person.h"
#include <iostream>

using namespace std;

Person::Person(){

	/* default constructor */

}

Person::Person(string fname, string lname){
	this->firstname = fname;
	this->lastname = lname;
}


Person::Person(string fname, string lname, int age){
	this->firstname = fname;
	this->lastname = lname;
	this->age = age;
}

int Person::getAge(){
	return this->age;
}

Person::~Person(){
	
	/* Default destructor */

}

void Person::sayHello(){
	cout<<"Hello"<<this->lastname<<endl;
}

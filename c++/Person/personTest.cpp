#include "person.h"
#include <iostream>

using namespace std;

int main(){
	Person *pOne = new Person();
	cout<<"Age : "<<pOne->getAge()<<endl;

    Person *ptwo = new Person("Manju", "SM");
    cout<<"Age : "<<ptwo->getAge()<<endl;

    Person *pthree = new Person("Manju", "SM", 30);
    cout<<"Age : "<<pthree->getAge()<<endl;

	//delete calls destructor
	delete pOne;
    delete ptwo;
    delete pthree;
}

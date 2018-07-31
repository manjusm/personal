#include "person.h"
#include <iostream>

using namespace std;

int main(){
	Person *pOne = new Person("Manjunatha", "SM", 30);
	cout<<"Age : "<<pOne->getAge()<<endl;
	//delete calls destructor
	delete pOne;
}

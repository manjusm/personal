#include "vehicle.h"

Vehicle::Vehicle() {
    cout<<"Default constructor"<<endl;
}

void Vehicle::setDetails(int regNumber, int wheels, string manufacturer) {
    this->regNumber = regNumber;
    this->wheels = wheels;
    this->manufacturer = manufacturer;
}

void Vehicle::getDetails(void) {
    cout<<this->regNumber<<endl;
    cout<<this->wheels<<endl;
    cout<<this->manufacturer<<endl;
}

Vehicle::~Vehicle() {
    cout<<"Destructor"<<endl;
}

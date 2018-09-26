#include "bike.h"

Bike::Bike() {
    cout<<"default constructor"<<endl;
}

void Bike::setDetails(int engineCapacity, int tankCapacity, string coolingTech) {
    this->engineCapacity = engineCapacity;
    this->tankCapacity = tankCapacity;
    this->coolingTech = coolingTech;
}

void Bike::getDetails(void) {
    cout<<this->engineCapacity<<endl;
    cout<<this->tankCapacity<<endl;
    cout<<this->coolingTech<<endl;
}

Bike::~Bike() {
    cout<<"destructor"<<endl;
}

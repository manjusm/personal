#include<iostream>

#include "body.h"
#include "handle.h"

Handle::Handle() {

    //Default constructor
    body = new Body;

}

Handle::~Handle() {
    
    //Default destructor
    delete body;

}

void Handle::someDataOperation() {
    
    body->someData = 45;

}

int Handle::getData() const {

    return body->someData;

}

#pragma once

#include "body.h"

using namespace std;

class Handle {

    private:
    Body *body;

    public:
    Handle();
    ~Handle();

    void someDataOperation();
    int getData() const;
};

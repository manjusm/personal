#include <iostream>

#include "handle.h"

using namespace std;

int main() {
    
    Handle h;
    h.someDataOperation();
    cout<<h.getData()<<endl;    
    return 0;
}

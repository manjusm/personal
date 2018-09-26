#include "bike.h"

int main() {
    Bike bike;
    Vehicle vehicle;
    bike.setDetails(123, 4, "Hello");
    bike.getDetails();
    cout<<sizeof(bike)<<endl;
    cout<<sizeof(vehicle)<<endl;

    return 0;
}

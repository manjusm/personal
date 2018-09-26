#include "vehicle.h"

class Bike : public Vehicle
{
    private:
        int engineCapacity;
        int tankCapacity;
        string coolingTech;

    public:
        Bike();
        void setDetails(int, int, string);
        void getDetails(void);
        ~Bike();
};

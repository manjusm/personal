#include <iostream>
#include <string>

using namespace std;

class Vehicle
{
    private:
        int regNumber;
        int wheels;
        string manufacturer;

    public:
        Vehicle();
        void setDetails(int, int, string);
        void getDetails(void);
        ~Vehicle();
};

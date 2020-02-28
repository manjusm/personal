#include <iostream>

using namespace std;

class Time
{
    private:
        int hours;
        int minutes;
    public:
        void setTime(int h, int m) {
            this->hours = h;
            this->minutes = m;
        }

        void showTime(void) {
            cout<<this->hours<<" "<<this->minutes<<endl;
        }

        void sum(Time, Time);
};

void Time::sum(Time t1, Time t2) 
{
    this->minutes = t1.minutes + t2.minutes;
    this->hours = this->minutes/60;
    this->hours += (t1.hours + t2.hours); 
    this->minutes = this->minutes % 60;
}

int main()
{
    Time T1, T2, T3;
    T1.setTime(2, 30);

    T1.showTime();
    T2.setTime(3, 45);

    T2.showTime();
    T3.sum(T1, T2);
    T3.showTime();
    return 0;
}

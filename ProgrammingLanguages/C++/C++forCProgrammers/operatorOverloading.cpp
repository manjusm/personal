#include <iostream>

using namespace std;

typedef enum days {SUN, MON, TUE, WED, THU, FRI, SAT} days;

days operator++(days d)
{
    return static_cast<days>((static_cast<int> (d) + 1) % 7);
}

ostream& operator<<(ostream& out, const days& d)
{
    switch(d)
    {
        case  MON:
            out<<"MONDAY";
            break;

        case  TUE:
            out<<"TUESDAY";
            break;

        case  WED:
            out<<"WEDNESDAY";
            break;

        case  THU:
            out<<"THURSDAY";
            break;

        case  FRI:
            out<<"FRIDAY";
            break;

        case  SAT:
            out<<"SATDAY";
            break;

        case  SUN:
            out<<"SUNDAY";
            break;

        default:
            break;
    }
    return out;
}

int main()
{
    days d = SUN, e;

    e = ++d;

    cout<<e<<endl;

    return 0;
}

#include <iostream>

using namespace std;


class point
{
    public:
        point(double x = 0, double y = 0) { this->x = x; this->y = y;}
        void setPoint(double a, double b) { x = a; y = b;}
        double getX() const { return x;}
        double getY() const { return y;}

    private:
        double x;
        double y;
};

ostream& operator<< (ostream& out, const point& p)
{
    out << "( " <<p.getX()<<", "<<p.getY()<<" )";
    return out;
}

point operator+ (const point& p1, const point& p2)
{
    point sum;
    sum.setPoint(p1.getX()+p2.getX(), p1.getY()+p2.getY());
    return sum;
}

int main()
{
    point p1, p2;
    cout<<"P1 "<<p1<<endl;
    cout<<"P1 "<<p2<<endl;
    p1.setPoint(1.5, 2.5);
    p2.setPoint(1.5, 2.5);

    cout<<"P1 = "<<p1<<endl;
    cout<<"P2 = "<<p2<<endl;
    cout<<"Sum = "<<p1+p2<<endl;
    return 0;
}

#include <iostream>

using namespace std;

class Class
{
    public:
        int getAge() {
            return this->age;
        }
        void setAge(int age) {
            this->age = age;
            count++;
        }
        static int getCount() {
            return count;
        }

    private:
        static int count;
        int age;
};

int Class::count = 10;

int main()
{
    Class a, b, c;
    a.setAge(15);
    b.setAge(20);
    c.setAge(25);

    cout<<c.getAge()<<endl;
    cout<<Class::getCount()<<endl;
    return 0;
}

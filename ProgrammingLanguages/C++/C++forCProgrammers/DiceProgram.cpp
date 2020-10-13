#include <iostream>

#include <ctime>
#include <cstdlib>

const int sides = 6;
inline int r_sides() { return (rand() % sides) + 1; }

using namespace std;

int main()
{
    srand(clock()); // seed rand() with clock(). It is 1 bu default.
    int trials;
    cout<<"Enter number of trials"<<endl;
    cin>>trials;

    int outcomes[12] = {0};
    for (int i = 0; i < trials; i++)
    {
        outcomes[r_sides() + r_sides()]++;
    }

    for (int j = 2; j <= 12; j++)
    {
        cout << "j = " << j <<"Probability = " <<static_cast <double>(outcomes[j])/trials<<endl;
    }
    return 0;
}

// Converted to C++
// changed to C++ io
// changed to one line comments
// changed defines of constants to const
// changed array to vector<>
// inline if any short function

#include <iostream>
#include <vector>

using namespace std;

const int N = 40;

template <class T> void sum(int n, vector <T> data, T& p)

{
    p = 0;
    for(int i = 0; i < data.size(); ++i)
    {
        p = p + data[i];
    }
}

int main()
{
    int accum = 0;
    vector <int> data;
    for(int i = 0; i < N; ++i)
    {
        data.push_back(i);
    }
    sum(N, data, accum);
    cout << "sum is "<< accum << endl;
    return 0;
}

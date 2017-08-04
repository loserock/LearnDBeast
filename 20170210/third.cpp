#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    unsigned int t = 0, n = 0;
    cin >> t;

    for (unsigned int i = 0; i < t; ++i)
    {
        cin >> n;
        if ((n == 1) || (n % 2 == 0))
        {
            cout << "Kitty" << endl;
        }
        else
        {
            cout << "Katty" << endl;
        }
    }

    return 0;
}

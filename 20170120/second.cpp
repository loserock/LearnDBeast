#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++)
    {
        long n;
        cin >> n;
        if (isLucky(n))
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    return 0;
}

bool isLucky(long n)
{
    if (n < 4)
    {
        return false;
    }
    else if (n >= 18)
    {
        return true;
    }
    else if (n == 5 || n == 6 || n == 9 || n == 10 || n == 13 || n == 17)
    {
        return false;
    }
    return true;
}

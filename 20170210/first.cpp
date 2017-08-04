#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    unsigned int n = 0, k = 0;
    vector<unsigned int> t;

    // read params
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
    {
        unsigned int ti;
        cin >> ti;
        t.push_back(ti);
    }

    // calc special problems
    unsigned int pageChap = 1, chap = 1;
    unsigned int specProblems = 0;
    while (chap <= n)
    {
        for (unsigned int j = 1; j <= t[chap-1]; ++j)
        {
            if (pageChap + (j - 1)/k == j)
            {
                ++specProblems;
            }
        }
        pageChap += t[chap-1] / k + ((t[chap-1] % k > 0)?1:0);
        ++chap;
    }
    cout << specProblems << endl;

    return 0;
}

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

unsigned long long prodOfDivs(unsigned long long N)
{
    unsigned long long checkLimit = (unsigned long long)sqrt(N);
    unsigned long long i = 1;
    unsigned long long i2 = 1;
    unsigned long long prod = 1;
    while (i <= checkLimit)
    {
        if (N % i == 0)
        {
            prod *= i;
            i2 = N / i;
            if (i2 != i)
            {
                prod *= i2;
            }
        }
        ++i;
    }
    return prod;
}


int main()
{
    unsigned int T = 0;
    cin >> T;
    vector<unsigned long long> nums(T);
    vector<long long> sols(T);
    unsigned long long X = 0;
    for (unsigned int i = 0; i < T; ++i)
    {
        cin >> X;
        nums[i] = X;
        sols[i] = -1;
    }

    double limit = sqrt(*max_element(nums.begin(), nums.end()));
    long unsolved = T;
    for (unsigned long long N = 1; N <= limit + 1; ++N)
    {
        unsigned long long prod = prodOfDivs(N);
        for (unsigned int i = 0; i < T; ++i)
        {
            if ((sols[i] == -1) && (nums[i] == prod))
            {
                sols[i] = N;
                --unsolved;
            }
        }
        if (unsolved <= 0)
        {
            break;
        }
    }

    for (unsigned int i = 0; i < T; ++i)
    {
        cout << sols[i] << endl;
    }

    return 0;
}

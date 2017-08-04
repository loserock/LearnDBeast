#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

unsigned long long gcd(unsigned long long a, unsigned long long b)
{
    return b == 0 ? a : gcd(b, a % b);
}

int main()
{
    unsigned long long N, a, b;
    cin >> N >> a >> b;
    if (a < b)
    {
        swap(a, b);
    }
    unsigned long long abGCD = gcd(a,b);

    for (unsigned long long i = abGCD; i > 0; --i)
    {
        cout << N;
    }

    return 0;
}

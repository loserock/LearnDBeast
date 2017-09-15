#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// #define DEBUG

int getLowerPowerOfTwo(uint64_t N)
{
    int i = 0;
    while (N != 1)
    {
        N >>= 1;
        ++i;
    }
    return i;
}

int gameRounds(uint64_t N)
{
    int i = getLowerPowerOfTwo(N);
    uint64_t lp = 1;
    lp <<= i;
#ifdef DEBUG
    cout << N << " >= 2 ^ " << i << " = " << lp << endl;
#endif
    if (lp == N)
        return i;
    return 1 + gameRounds(N - lp);
}

int main()
{
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i)
    {
        uint64_t N;
        cin >> N;
        if (gameRounds(N) & 1)
            cout << "Louise" << endl;
        else
            cout << "Richard" << endl;
    }
    return 0;
}

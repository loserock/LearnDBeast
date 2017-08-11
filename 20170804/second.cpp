#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

template <typename T>
T modpow(T base, T exp, T modulus)
{
    base %= modulus;
    T result = 1;
    while (exp > 0)
    {
        if (exp & 1)
            result = (result * base) % modulus;
        base = (base * base) % modulus;
        exp >>= 1;
    }
    return result;
}

unsigned long long numberOfAntiPalidromicStrings(int N, int M)
{
    // TODO fix it for small numbers!
    return M * (M-1) * modpow(M-2, N-2, 1000000007);
}

int main()
{
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i)
    {
        int N, M;
        cin >> N >> M;
        cout << numberOfAntiPalidromicStrings(N, M) % 1000000007 << endl;
    }

    return 0;
}

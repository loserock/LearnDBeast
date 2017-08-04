#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

unsigned long long numberOfAntiPalidromicStrings(int N, int M)
{
    // TODO
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

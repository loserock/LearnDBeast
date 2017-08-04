#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    unsigned int N = 0;
    cin >> N;
    unsigned int B[N];
    unsigned int numOfOdd = 0;
    for (unsigned int i = 0; i < N; ++i)
    {
        cin >> B[i];
        numOfOdd += (B[i] & 1);
    }
    if (numOfOdd & 1)
    {
        cout << "NO";
        return 0;
    }
    unsigned int rations = 0;
    for (unsigned int i = 0; i < N-1; ++i)
    {
        if (B[i] & 1)
        {
            ++B[i];
            ++B[i+1];
            rations += 2;
        }
    }
    cout << rations;

    return 0;
}

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int whoGetsTheCatch(int n, int x, vector<int> X, vector<int> V)
{
    const static int _MAXVAL = 9999;
    vector<int> T(n);
    auto X_i = X.cbegin(), V_i = V.cbegin();
    auto T_i = T.begin();
    int currMinValue = _MAXVAL;
    int currMinIndex = -1;
    for (; X_i != X.cend(); ++X_i, ++V_i, ++T_i)
    {
        *T_i = abs(x - *X_i) / *V_i;
        if (*T_i < currMinValue)
        {
            currMinValue = *T_i;
            currMinIndex = T_i - T.begin();
        }
        else if (*T_i == currMinValue)
        {
            currMinIndex = -1;
        }
    }
    return currMinIndex;
}

int main()
{
    //  Return the index of the catcher who gets the catch, or -1 if no one gets the catch.
    int n;
    int x;
    cin >> n >> x;
    vector<int> X(n);
    for (int X_i = 0; X_i < n; ++X_i)
    {
        cin >> X[X_i];
    }
    vector<int> V(n);
    for (int V_i = 0; V_i < n; ++V_i)
    {
        cin >> V[V_i];
    }
    int result = whoGetsTheCatch(n, x, X, V);
    cout << result << endl;
    return 0;
}
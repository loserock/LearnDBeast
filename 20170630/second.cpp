#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <memory>

using namespace std;

long getMaxBridges(long x1, long y1, long x2, long y2, long xC, long yC)
{
    long rx = min(xC - x1, x2 - xC);
    long ry = min(yC - y1, y2 - yC);
    return 2 * rx * ry + rx + ry;
}

int main()
{
    //  Return the maximum number of bridges the Rulers will commission.
    long x1, y1, x2, y2, xC, yC;
    cin >> x1 >> y1;
    cin >> x2 >> y2;
    cin >> xC >> yC;
    long result = getMaxBridges(x1, y1, x2, y2, xC, yC);
    cout << result << endl;
    return 0;
}
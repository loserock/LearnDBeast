#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int solveDay = 0;
    unsigned int score = 0;
    for (unsigned int probNum = 1; probNum <= 5; probNum++)
    {
        cin >> solveDay;
        int diffDay = solveDay - probNum;
        score += diffDay < 10 ? (10 - diffDay) * 10 : 0;
    }
    cout << score;

    return 0;
}

#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

//#define DEBUG

unsigned long bubbleSort(vector<int> &D)
{
    unsigned long count = 0;
    bool wasSwap = true;
    int firstSwapped = 0;
    int lastSwapped = 0;
#ifdef DEBUG
    clock_t clk = clock();
    long long cycCount = 0;
    unsigned long lastCount = 0;
    long cycMod = 100;
#endif
    while (wasSwap)
    {
        wasSwap = false;
        for (auto it = D.begin() + firstSwapped + 1; it != D.end() /* TODO add dynamic limit */; ++it)
        {
            if (*it < *(it - 1))
            {
                iter_swap(it, it - 1);
                ++count;
                if (!wasSwap)
                {
                    firstSwapped = it - D.begin() - 1;
                    wasSwap = true;
                }
                lastSwapped = D.end() - it - 1;
            }
        }
        if (!wasSwap)
            break;
        wasSwap = false;
        for (auto it = D.rbegin() + lastSwapped + 1; it != D.rend() /* TODO add dynamic limit */; ++it)
        {
            if (*it > *(it - 1))
            {
                iter_swap(it, it - 1);
                ++count;
                if (!wasSwap)
                {
                    lastSwapped = it - D.rbegin() - 1;
                    wasSwap = true;
                }
                firstSwapped = D.rend() - it - 1;
            }
        }
#ifdef DEBUG
        if (!(++cycCount % cycMod))
        {
            cout << "#" << cycCount << "th cycle end time: " << double(clock() - clk) / CLOCKS_PER_SEC
                 << "\t count diff: " << count - lastCount << "\t first: " << firstSwapped
                 << "\t last: " << lastSwapped << endl;
            lastCount = count;
        }
#endif
    }
    return count;
}

int main()
{
    int n;
    cin >> n;
    vector<int> d(n);
    for (int d_i = 0; d_i < n; ++d_i)
    {
        cin >> d[d_i];
    }

    unsigned long count = bubbleSort(d);

    cout << count << endl;

    return 0;
}
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

//#define DEBUG

class IceCream
{

  public:
    int flavor;
    int index;

    IceCream(int flavor, int index) : flavor(flavor), index(index) {}
};

int binarySearch(int first, int last, const vector<IceCream> &arr, int search)
{
    if (arr[first].flavor > search || arr[last].flavor < search)
        return -1;
    while (first < last)
    {
        const int i = (first + last) / 2;
        const int v = arr[i].flavor;
        if (v == search)
        {
            return arr[i].index;
        }
        else if (search < v)
        {
            last = i - 1;
        }
        else
        {
            first = i + 1;
        }
    }
    if (arr[first].flavor == search)
    {
        return arr[first].index;
    }
    return -1;
}

int main()
{
    int t;
    int n, m;
    cin >> t;
    for (int test = 0; test < t; ++test)
    {
        cin >> m >> n;
        vector<IceCream> arr;
        arr.reserve(n);

        for (int i = 0; i < n; i++)
        {
            int cost;
            cin >> cost;
            arr.push_back(IceCream(cost, i + 1));
        }
        auto compare = [](const IceCream &i, const IceCream &j) -> bool { return i.flavor <= j.flavor; };
        sort(arr.begin(), arr.end(), compare);
        //int firstIndex = 100000, secondIndex = 100000;
        for (int i = 0; i < n - 1; i++)
        {
            int search = m - arr[i].flavor;
#ifdef DEBUG
            cout << "#Search for " << i << " " << arr[i].flavor << " ; " << search << endl;
#endif
            if (search >= arr[i].flavor)
            {
#ifdef DEBUG
                cout << "#Binary " << i + 1 << " " << n - 1 << " " << search << endl;
#endif
                int index = binarySearch(i + 1, n - 1, arr, search);
                if (index != -1)
                {
                    cout << min(arr[i].index, index) << " " << max(arr[i].index, index) << endl;
                    break;
                }
            }
#ifdef DEBUG
            else
            {
                cout << "#Not Found for " << i << " " << arr[i].flavor << endl;
            }
#endif
        }
#ifdef DEBUG
        cout << "#End of an issue!" << endl;
#endif
    }
}

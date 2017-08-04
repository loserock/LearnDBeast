// task source:
//  https://www.hackerrank.com/challenges/ctci-find-the-running-median

#include <cmath>
#include <cstdio>
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

//improvements:
// - use multiset (optimized insertion, and stored allways back/front/middle iterator)
// - usr O(N) unsorted selection algorith, there is many:
//    -- https://en.wikipedia.org/wiki/Selection_algorithm
//    -- http://stackoverflow.com/questions/10930732/c-efficiently-calculating-a-running-median
//    -- https://discuss.codechef.com/questions/1489/find-median-in-an-unsorted-array-without-sorting-it
//    -- http://stackoverflow.com/questions/11065066/find-median-with-minimum-time-in-an-array

int main()
{
	int n;
	cin >> n;
	vector<int> a;
	a.reserve(n);
	cout << fixed << setprecision(1);
	int el;
	for (int a_i = 0; a_i < n; a_i++)
	{
		cin >> el;
		a.push_back(el);
		int medPos = (a_i) / 2;
		nth_element(a.begin(), a.begin() + medPos, a.end());
		double med1 = a[medPos];
		if (a_i & 1) // paros (indexing)
		{
			nth_element(a.begin(), a.begin() + medPos + 1, a.end());
			double med2 = a[medPos + 1];
			cout << (med1 + med2) / 2.0 << endl;
		}
		else // paratlan (indexing)
		{
			cout << med1 << endl;
		}
		// cout << "size: " << a.size() << " medPos: " << medPos << "; ";
		// for (const auto e : a)
		// {
		//  cout << e << " ";
		// }
		// cout << endl;
	}
	return 0;
}

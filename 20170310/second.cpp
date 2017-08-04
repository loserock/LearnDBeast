#include <cmath>
#include <cstdio>
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	unsigned int T = 0;
	cin >> T;
	for (unsigned int t = 0; t < T; ++t)
	{
		// test case cycle

		unsigned int N = 0;
		cin >> N;
		vector<unsigned long> H;
		H.resize(N);
		//multiset<unsigned long> H;
		//unsigned long Hi;
		//std::multiset<unsigned long>::iterator it = H.end();
		//for (unsigned int i = 0; i < N; ++i)
		for (auto i = H.begin(); i != H.end(); ++i)
		{
			//cin >> H[i];
			cin >> *i;
			//cin >> Hi;
			//it = H.insert(it, Hi);
		}

		sort(H.begin(), H.end());
		unsigned long long P = 0;
		unsigned long long tmpSum = 0;

		for (long i = N - 1; i >= 0; --i)
		{
			// tactics iteration cycle

			tmpSum += H[i];
			unsigned long long Pc = tmpSum * (i + 1);

			// unsigned long long Sc = 1 + i;
			// unsigned long long Pc = 0;
			// //auto itLim = prev(H.crend(), i);
			// auto itLim = next(H.crbegin(), N-i);
			// for (auto mi = H.crbegin(); mi != itLim; ++mi)
			// {
			//  Pc += Sc * (*mi);
			// }
			if (Pc < P)
			{
				break;
			}
			else
			{
				P = Pc;
			}
		}

		// print test case result
		cout << P << endl;
	}


	return 0;
}

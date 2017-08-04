#include <cmath>
#include <cstdio>
//#include <vector>
#include <iostream>
//#include <algorithm>

using namespace std;

int main()
{
	unsigned int n = 0;
	unsigned int i = 0;
	unsigned int m = 0;
	cin >> n;
	while (i < n)
	{
		unsigned int toSkip;
		cin >> toSkip;
		++m;
		i += 1 + toSkip;
		cin.ignore(20, ' ');
		for (size_t j = toSkip; j > 0; --j)
		{
			cin.ignore(20, ' ');
		}
	}
	cout << m << endl;

	return 0;
}

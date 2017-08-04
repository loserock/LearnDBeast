#include <cmath>
#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
	unsigned int n = 0;
	cin >> n;
	if (n <= 3)
	{
		cout << 1;
		return 0;
	}
	unsigned int w = n / 3;
	unsigned int h = (n - w) / 2;
	unsigned int l = n - w - h;
	cout << w * h * l;
	return 0;
}

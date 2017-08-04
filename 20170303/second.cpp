#include <cmath>
#include <cstdio>
#include <iostream>

using namespace std;

unsigned long long xorray(unsigned long long i)
{
	switch (i%4)
	{
	case 0:
		return i;
	case 1:
		return 1;
	case 2:
		return i+1;
	case 3:
	default:
		return 0;
	}
}

int main()
{
	unsigned int Q = 0;
	unsigned long long L = 0, R = 0;
	cin >> Q;
	for (unsigned int Qi = 0; Qi < Q; ++Qi)
	{
		cin >> L >> R;
		unsigned long long result = 0;
		if (R - L < 8)
		{
			result = xorray(L);
			for (unsigned long long j = L + 1; j <= R; result ^= xorray(j++)) ;
		}
		else
		{
			unsigned long long Lu = ((L%4)==0) ? L : (L+4-(L%4));
			unsigned long long Rd = (R>>2)<<2;
			result = (((Rd-Lu)/4)&1)<<1;
			for (unsigned long long j = Lu - 1; j >= L; result ^= xorray(j--)) ;
			for (unsigned long long j = Rd; j <= R; result ^= xorray(j++)) ;
		}
		cout << result << endl;

	}

	return 0;
}

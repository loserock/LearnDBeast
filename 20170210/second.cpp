#include <cmath>
#include <cstdio>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

typedef unsigned int RepType;

static map<int, RepType> gRep = {{'A', 1}, {'C', 4}, {'G', 16}, {'T', 64}};

int main()
{
	unsigned int n = 0;
	cin >> n;
	RepType * g = new RepType[n];
	RepType steadySum = gRep['A'] + gRep['C'] + gRep['G'] + gRep['T'];
	RepType * cg = g;
	unsigned long long gSum = 0;
	for (unsigned int i = 0; i < n; ++i, ++cg)
	{
		*cg = gRep[getchar()];
		gSum += *cg;
	}

    reqSum = n / 4 * steadySum;
    if (reqSum == gSum)
    {
        cout << 0 << endl;
    }

    for (unsigned int l = 1; l < n; ++l)
    {
        //sum search cycle
        for (cg = g; cg <= g + n - l; ++cg)
        {
            unsigned long long cSum = 0;
            for (size_t ns = 0; ns < l; ++ns)
            {
                cSum += cg[ns];
            }
        }
    }

	delete[] g;
	return 0;
}

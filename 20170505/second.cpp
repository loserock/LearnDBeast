#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

//#define DEBUG

long long powmod(long long x, long long e, long long p)
{
	if (e == 0)
		return 1;
	if (e & 1)
		return x * powmod(x, e - 1, p) % p;
	long long rt = powmod(x, e / 2, p);
	return rt * rt % p;
}

long long binom_coeff_mod_prime(long long n, long long k, long long p)
{
	long long res = 1;
	while (n || k)
	{
		long long N = n % p, K = k % p;
		for (long long i = N - K + 1; i <= N; ++i)
			res *= i % p;
		for (long long i = 1; i <= K; ++i)
			res *= powmod(i, p - 2, p) % p;
		n /= p;
		k /= p;
	}
	return res;
}

long long countSubs(string s)
{
	// count chars
	map<char, long long> charNum;
	for (const auto c : s)
	{
		++charNum[c];
	}

	long long ab = charNum['a'] + charNum['b'], cd = charNum['c'] + charNum['d'];

#ifdef USE_MY_METHOD
	// calc six factorial in none cycle, with modulo 1E9-7 check
	long long maxRange = max(ab, cd);

#ifdef DEBUG
	cout << maxRange << endl;
#endif //DEBUG

	long long cFact = 1;
	long long af = 1, bf = 1, cf = 1, df = 1, abf = 1, cdf = 1;
	for (long long i = 1; i <= maxRange; ++i)
	{
		cFact *= i;
		if (cFact > 1000000007)
			cFact %= 1000000007;
		if (i == charNum['a'])
			af = cFact;
		if (i == charNum['b'])
			bf = cFact;
		if (i == charNum['c'])
			cf = cFact;
		if (i == charNum['d'])
			df = cFact;
		if (i == ab)
			abf = cFact;
		if (i == cd)
			cdf = cFact;
	}

#ifdef DEBUG
	cout << charNum['a'] << "! = " << af << "; "
		 << charNum['b'] << "! = " << bf << "; "
		 << charNum['c'] << "! = " << cf << "; "
		 << charNum['d'] << "! = " << df << "; "
		 << ab << "! = " << abf << "; "
		 << cd << "! = " << cdf << endl;
#endif //DEBUG

#ifdef DEBUG
	cout << (abf / (af * bf)) << endl
		 << (cdf / (cf * df)) << endl;
#endif //DEBUG

	// calc final result
	long long r = (abf / (af * bf)) * (cdf / (cf * df)) - 1;
	r %= 1000000007;

	return r;
#endif //USE_MY_METHOD

	long long p = 1000000007;

	long long r = binom_coeff_mod_prime(ab, min(charNum['a'], charNum['b']), p);
	r *= binom_coeff_mod_prime(cd, min(charNum['c'], charNum['d']), p);
	r -= 1;
	r %= p;

	return r;
}

int main()
{
	// Return the number of non-empty perfect subsequences mod 1000000007
	int q;
	cin >> q;
	for (int a0 = 0; a0 < q; a0++)
	{
		string s;
		cin >> s;
		long long result = countSubs(s);
		cout << result << endl;
	}
	return 0;
}

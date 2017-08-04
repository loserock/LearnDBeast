#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <unordered_map>

using namespace std;

template <typename RandomIter1, typename RandomIter2>
void merge(RandomIter1 begin,
		   RandomIter1 middle,
		   RandomIter1 end,
		   RandomIter2 aux,
		   long long *counter = nullptr)
{
	RandomIter1 left = begin;
	RandomIter1 right = middle;
	RandomIter1 left_bound = middle;
	RandomIter1 right_bound = end;

	const auto auxStart = aux;

	while (left != left_bound and right != right_bound)
	{
		if (*right < *left)
		{
			*aux = *right;
			//TODO counter should count the real moving distances!
			if (counter)
				(*counter) += std::distance(begin, right) - std::distance(auxStart, aux);
			++right;
		}
		else
		{
			*aux = *left;
			++left;
		}

		++aux;
	}

	//TODO here can be other hidden swapping?
	copy(left, left_bound, aux);
	copy(right, right_bound, aux);
}

template <typename RandomIter1, typename RandomIter2>
void merge_sort(RandomIter1 source_begin,
				RandomIter1 source_end,
				RandomIter2 target_begin,
				RandomIter2 target_end,
				long long *counter = nullptr)
{
	const auto distance = std::distance(source_begin, source_end);

	if (distance < 2)
	{
		return;
	}

	RandomIter1 source_middle = source_begin;
	RandomIter2 target_middle = target_begin;
	advance(source_middle, distance >> 1); // distance >> 1 is the same as
	// distance / 2
	advance(target_middle, distance >> 1);

	merge_sort(target_begin,
			   target_middle,
			   source_begin,
			   source_middle,
			   counter);

	merge_sort(target_middle,
			   target_end,
			   source_middle,
			   source_end,
			   counter);

	merge(source_begin,
		  source_middle,
		  source_end,
		  target_begin,
		  counter);
}

template <typename RandomIter>
void merge_sort(RandomIter begin, RandomIter end, long long *counter = nullptr)
{
	const auto distance = std::distance(begin, end);

	if (distance < 2)
	{
		return;
	}

	using value_type = typename iterator_traits<RandomIter>::value_type;
	value_type *aux = new value_type[distance];
	copy(begin, end, aux);
	merge_sort(aux, aux + distance, begin, end, counter);
	delete[] aux;
}

long long count_inversions(vector<int> &a)
{
	long long counter = 0;
	merge_sort(a.begin(), a.end(), &counter);
	return counter;
}

int main()
{
	int t;
	cin >> t;
	for (int a0 = 0; a0 < t; a0++)
	{
		int n;
		cin >> n;
		vector<int> arr(n);
		for (int arr_i = 0; arr_i < n; arr_i++)
		{
			cin >> arr[arr_i];
		}
		cout << count_inversions(arr) << endl;
#ifdef DEBUG
		if (!is_sorted(arr.begin(), arr.end()))
		{
			cout << "That was WRONG!" << endl;
		}
#endif // DEBUG
	}
	return 0;
}

// the black box
// https://www.hackerrank.com/contests/w8/challenges/black-box-1/problem

#include <cmath>
#include <set>
#include <unordered_set>
#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <limits.h>

using namespace std;

// Function to return maximum XOR subset in set[]
int maxSubsetXOR(const unordered_set<int> & FullSet)
{
    int INT_BITS=32;
    vector<int> BlackBox;
    copy(FullSet.begin(), FullSet.end(), back_inserter(BlackBox));
    int n = BlackBox.size();

    // Initialize index of chosen elements
    int index = 0;
 
    // Traverse through all bits of integer starting from
    // the most significant bit (MSB)
    for (int i=INT_BITS-1; i>=0; --i)
    {
        // Initialize index of maximum element and the maximum element
        int maxInd = index, maxEle = INT_MIN;
        for (int j=index; j<n; ++j)
        {
             // If i'th bit of BlackBox[j] is BlackBox and BlackBox[j] is greater
             // than max so far.
             if ( (BlackBox[j]&(1<<i))!= 0 && BlackBox[j]>maxEle )
                maxEle = BlackBox[j], maxInd = j;
        }
 
        // If there was no element with i'th bit BlackBox, move to smaller i
        if (maxEle == INT_MIN)
           continue;
 
        // Put maximum element with i'th bit BlackBox at index 'index'
        swap(BlackBox[index], BlackBox[maxInd]);
 
        // Update maxInd and increment index
        maxInd = index;
 
        // Do XOR of BlackBox[maxIndex] with all numbers having i'th
        // bit as BlackBox.
        for (int j=0; j<n; j++)
        {
            // XOR BlackBox[maxInd] those numbers which have the i'th
            // bit BlackBox
            if ((j!=maxInd) && ((BlackBox[j] & (1<<i)) !=0))
                BlackBox[j] = BlackBox[j]^BlackBox[maxInd];
        }
 
        // Increment index of chosen elements
        ++index;
    }
 
    // Final result is XOR of all elements
    int res = 0;
    for (int i=0; i<n; i++)
        res ^= BlackBox[i];
    return res;
}

int main()
{
    unsigned int N = 0;
    cin >> N;
    unordered_set<int> blackBox;
    for (unsigned int i = 0; i<N; ++i)
    {
        int a;
        cin >> a;
        if (a >= 0)
            blackBox.insert(a);
        else
            blackBox.erase(-a);
        cout << maxSubsetXOR(blackBox) << endl;
    }

    return 0;
}

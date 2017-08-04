#include <iostream>
#include <string>

using namespace std;

string twoStrings(const string & s1, const string & s2)
{
    size_t result = s1.find_first_of(s2, 0);
    return result==string::npos?"NO":"YES";
    // for (const auto & c1 : s1)
    // {
    //     for (const auto & c2 : s2)
    //     {
    //         if (c1 == c2)
    //             return "YES";
    //     }
    // }
    // return "NO";
}

int main()
{
    int q;
    cin >> q;
    for (int a0 = 0; a0 < q; a0++)
    {
        string s1;
        cin >> s1;
        string s2;
        cin >> s2;
        string result = twoStrings(s1, s2);
        cout << result << endl;
    }
    return 0;
}

#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
//#include <algorithm>

using namespace std;

struct Command
{
	unsigned int a, b, d;
};

bool operator!=(const Command & c1, const Command & c2)
{return 0 != memcmp(&c1, &c2, sizeof(Command)); };

bool operator==(const Command & c1, const Command & c2)
{return 0 == memcmp(&c1, &c2, sizeof(Command)); };

struct Knight
{
	unsigned int x, y;
	unsigned long long i;
	// Knight(unsigned long long ind): x(), y(), i(ind) {};
	// Knight(const unsigned int & X, const unsigned int & Y, const unsigned long long & ind)
	//  : x(X)
	//  , y(Y)
	//  , i(ind)
	// {};
};

Knight getKnightByCommand(const Command & cmd, const Knight & k)
{
	if (cmd.a <= k.x && cmd.a + cmd.d >= k.x && cmd.b <= k.y && cmd.b + cmd.d >= k.y)
	{
		return {cmd.d + cmd.b + cmd.a - k.y, k.x + cmd.b - cmd.a, k.i};
	}
	return k;
}

void runCommandOnKnight(const Command & cmd, Knight & k)
{
	if (cmd.a <= k.x && cmd.a + cmd.d >= k.x && cmd.b <= k.y && cmd.b + cmd.d >= k.y)
	{
		unsigned int x = k.x;
		k.x = cmd.d + cmd.b + cmd.a - k.y;
		k.y = x + cmd.b - cmd.a;
	}
}

int main()
{
	unsigned long long N = 0;
	unsigned long S = 0;
	cin >> N;
	cin >> S;
	vector<Command> allCommand;
	allCommand.reserve(S);
	for (unsigned long i = 0; i < S; ++i)
	{
		unsigned int a, b, d;
		cin >> a >> b >> d;
		if (d == 0)
		{
			continue;
		}
		allCommand.push_back({b, a, d});
		if (allCommand.size() >= 4)
		{
			auto it = allCommand.crbegin();
			if (*it == it[1] && *it == it[2] && *it == it[3])
			{
				allCommand.resize(allCommand.size() - 4);
			}
		}
	}
	auto createKnightByIndex = [N](unsigned long long ind) -> Knight {return {ind % N + 1, ind / N + 1, ind};};
	unsigned long L = 0;
	cin >> L;
	vector<Knight> allChosenKnight;
	allChosenKnight.reserve(L);
	for (unsigned long i = 0; i < L; ++i)
	{
		unsigned long long ind;
		cin >> ind;
		//Knight k = createKnightByIndex(ind);
		allChosenKnight.push_back(createKnightByIndex(ind));
		//allChosenKnight.push_back({ind % N + 1, ind / N + 1, ind});
		// for (const auto & cmd : allCommand)
		// {
		//  //k = getKnightByCommand(cmd, k);
		//     runCommandOnKnight(cmd, k);
		// }
		// cout << k.y << " " << k.x << endl;
	}
	for (auto & knight : allChosenKnight)
	{
		for (const auto & cmd : allCommand)
		{
			runCommandOnKnight(cmd, knight);
            //knight = getKnightByCommand(cmd, knight);
		}
		cout << knight.y << " " << knight.x << endl;
	}

	return 0;
}

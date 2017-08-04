#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

//#define DEBUG

map<char, int> _c2w = {{'2', 2}, {'3', 3}, {'4', 4}, {'5', 5}, {'6', 6}, {'7', 7}, {'8', 8}, {'9', 9}, {'T', 10}, {'J', 11}, {'Q', 12}, {'K', 13}, {'A', -1}};

struct Card
{
    int weight;
    int suite;
    Card(const char *Chr)
    {
        weight = _c2w[Chr[0]];
        switch (Chr[1])
        {
        case 'S':
            suite = 0;
            break;
        case 'H':
            suite = 1;
            break;
        case 'D':
            suite = 2;
            break;
        case 'C':
            suite = 3;
            break;
        }
    }
};

int main()
{
    vector<Card> cards;
    for (int i = 0; i < 5; ++i)
    {
        string card_s;
        cin >> card_s;
        cards.emplace_back(card_s.c_str());
    }

    // check flush
    bool isFlush = true;
    auto card_it = cards.cbegin();
    int suite = card_it->suite;
    while (++card_it != cards.cend())
    {
        if (card_it->suite != suite)
        {
            isFlush = false;
            break;
        }
    }
    if (!isFlush)
    {
        cout << "NO" << endl;
        return 0;
    }

    // check straight
    bool isStraight = true;
    sort(cards.begin(), cards.end(), [](Card i, Card j) -> bool { return i.weight < j.weight; });
    card_it = cards.cbegin();
    bool hasAce = false;
    if (card_it->weight == -1)
    {
        ++card_it;
        hasAce = true;
    }
    while (++card_it != cards.cend())
    {
        if (card_it->weight != (card_it - 1)->weight + 1)
        {
            isStraight = false;
            break;
        }
    }
    if (isStraight && hasAce && cards[1].weight != _c2w['2'] && cards.back().weight != _c2w['K'])
    {
        #ifdef DEBUG
        cout << "# " << cards[1].weight << " <-first ; last-> " << cards.back().weight << endl;
        #endif
        isStraight = false;
    }

    cout << ((isFlush && isStraight)?"YES":"NO") << endl;

    return 0;
}

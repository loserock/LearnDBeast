#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
 
struct Coord
{
    int x=0;
    int y=0;
    Coord operator+(Coord c) const {return {x+c.x, y+c.y};};
    Coord operator-(Coord c) const {return {x-c.x, y-c.y};};
    void operator+=(Coord c) {x+=c.x; y+=c.y;};
    void operator-=(Coord c) {x-=c.x; y-=c.y;};
};

int main()
{
    int firstInitInput;
    cin >> firstInitInput; cin.ignore();
    int secondInitInput;
    cin >> secondInitInput; cin.ignore();
    int thirdInitInput;
    cin >> thirdInitInput; cin.ignore();
    
    cerr    << "Init values:" << endl
            << firstInitInput << " " << secondInitInput << " " << thirdInitInput << endl;
    
    vector<Coord> positions(thirdInitInput);
    vector<Coord> lastMove(thirdInitInput);
    
    unsigned int gameTurn = 0;
    // game loop
    while (1)
    {
        string firstInput;
        getline(cin, firstInput);
        string secondInput;
        getline(cin, secondInput);
        string thirdInput;
        getline(cin, thirdInput);
        string fourthInput;
        getline(cin, fourthInput);
        
        cerr    << "Turn " << ++gameTurn << " inputs:" << endl
                << firstInput << " " << secondInput << " " << thirdInput << " " << fourthInput << endl;
        cerr    << "Turn " << gameTurn << " positions:" << endl;
        for (int i = 0; i < thirdInitInput; i++)
        {
            int fifthInput;
            int sixthInput;
            if (gameTurn > 1)
            {
                lastMove
            }
            cin >> fifthInput >> sixthInput; cin.ignore();
            cerr << fifthInput << " " << sixthInput << endl;
        }

        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;
        
        // Output: "A, B, C, D or E"
        // A -> X+
        cout << "E" << endl;
    }
}

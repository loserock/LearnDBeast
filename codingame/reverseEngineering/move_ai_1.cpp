#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <set>
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

struct Vec : Coord
{
    double len() { return sqrt(this->x * this->x + this->y * this->y); };
};

class AsciiArtCanvas
{
    Coord size{0,0};
    set<pair<Coord, const char>> Field;
    char * charMap = nullptr;
    size_t _allocSize = 0;
public:
    ~AsciiArtCanvas()
    {
        if (charMap)
            delete[] charMap;
    };
    void Add(const Coord& Pos, const char Chr)
    {
        // TODO check pos & size limit
        charMap[size.x * Pos.y + Pos.x] = Chr;
    };
    void Clear()
    {
        int cNum = size.x * size.y;
        if (_allocSize != cNum)
        {
            if (charMap)
                delete[] charMap;
            _allocSize = cNum;
            charMap = new char[_allocSize + 1];
            charMap[_allocSize]='\0';
        }
        for (int i = 0; i < _allocSize; charMap[i++]=' ');
    };
    void SetSize(int Width, int Height) {size.x = Width; size.y = Height;};
    void Print(ostream & Stream)
    {
        size_t ls = size.x;
        char * buff = new char[ls+1];
        buff[ls] = '\0';
#ifdef DEBUG
        Stream << "DEBUG " << size.x << " " << size.y << " " << charMap << endl;
#endif // DEBUG
        for (size_t l = 0; l < size.y; ++l)
        {
            // strncat(buff, charMap+(l*size.x), ls);
            memcpy(buff, charMap+(l*ls), ls);
            Stream << buff << endl;
        }
        delete[] buff;
    };
    
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
    
    AsciiArtCanvas canv;
    canv.SetSize(firstInitInput+1, secondInitInput+1);

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
        
        canv.Clear();

        for (int i = 0; i < thirdInitInput; i++)
        {
            int fifthInput;
            int sixthInput;
            cin >> fifthInput >> sixthInput; cin.ignore();
            Coord pos{fifthInput, sixthInput};
            canv.Add(pos, 65+i);
            if (gameTurn > 1)
            {
                lastMove[i] = pos - positions[i];
            }
            positions[i] = pos;
            cerr << positions[i].x << " " << positions[i].y << " diff: " << lastMove[i].x << " " << lastMove[i].y << endl;
        }
        canv.Print(cerr);

        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;
        
        // Output: "A, B, C, D or E"
        // A -> X+  ???
        cout << "E" << endl;
    }
}

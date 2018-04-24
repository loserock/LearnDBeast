#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

#define UNDEF_INT -100000

struct Point
{
    int x;
    int y;
    Point& operator+= (const Point& p);
};

bool operator== (const Point p1, const Point p2)
{
    return p1.x == p2.x && p1.y == p2.y;
}

bool operator!= (const Point p1, const Point p2)
{
    return !(p1 == p2);
}

Point operator+ (const Point p1, const Point p2)
{
    return {p1.x + p2.x, p1.y + p2.y};
}

Point& Point::operator+= (const Point& p)
{
    this->x += p.x;
    this->y += p.y;
    return *this;
}

Point operator- (const Point p1, const Point p2)
{
    return {p1.x - p2.x, p1.y - p2.y};
}

int operator* (const Point p1, const Point p2)
{
    return p1.x * p2.x + p1.y * p2.y;
}

double len(const Point p)
{
    return sqrt(p.x * p.x + p.y * p.y);
}

Point normWithMul(const Point p, const double mul)
{
    double l = len(p);
    return {mul * p.x / l, mul * p.y / l};
}

inline double deg2rad(double deg)
{
    return deg * M_PI / 180.0;
}

inline double rad2deg(double rad)
{
    return rad * 180.0 / M_PI;
}

int angle(Point p1, Point p2)
{
    return rad2deg(acos(p1*p2 / (len(p1)*len(p2))));
}

Point RotateWithAngle(const Point p, const int angle)
{
    double theta = deg2rad(angle);
    double cs = cos(theta);
    double sn = sin(theta);
    return {p.x * cs - p.y * sn, p.x * sn + p.y * cs};
}

int main()
{

    vector<Point> checkpointList;
    checkpointList.reserve(5);

    Point podLastPos{UNDEF_INT, UNDEF_INT};
    Point lastCheckPos{UNDEF_INT, UNDEF_INT};
    Point afterNextCheckPos{UNDEF_INT, UNDEF_INT};
    int boost_left = 1;
    int numOfCircle = 0;
    int numOfCheck = 0;

    // game loop

    while (1)
    {
        int x, y; //< x, y position of the pod
        int nextCheckpointX, nextCheckpointY; //< x, y position of the next check point
        int nextCheckpointDist; //< distance to the next checkpoint
        int nextCheckpointAngle; //< angle between your pod orientation and the direction of the next checkpoint
        cin >> x >> y >> nextCheckpointX >> nextCheckpointY >> nextCheckpointDist >> nextCheckpointAngle; cin.ignore();
        int opponentX, opponentY; //< //< x, y position of the opponent's pod
        cin >> opponentX >> opponentY; cin.ignore();

        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;
        
        Point podPos = {x, y};
        if (podLastPos == Point{UNDEF_INT, UNDEF_INT})
            podLastPos = podPos;
        Point podSteering = podPos - podLastPos;
        int podSpeed = len(podSteering);
        Point oppPos = {opponentX, opponentY};
        Point oppRelPos = oppPos - podPos;
        int oppDist = len(oppRelPos);
        Point nextCheckPos = {nextCheckpointX, nextCheckpointY};

        // handling checkpoint storage
        if (lastCheckPos == Point{UNDEF_INT, UNDEF_INT})
            lastCheckPos = nextCheckPos;
        bool checkpointReached = (nextCheckPos != lastCheckPos);
        if (checkpointReached)
        {
            if (numOfCircle <= 0 && find(checkpointList.begin(), checkpointList.end(), lastCheckPos) == checkpointList.end())
            {
                checkpointList.push_back(lastCheckPos);
                if (find(checkpointList.begin(), checkpointList.end(), nextCheckPos) != checkpointList.end())
                {
                    numOfCircle++;
                    numOfCheck = 0;
                }
            }
            else
            {
                if (numOfCheck >= checkpointList.size() - 1)
                {
                    numOfCheck = 0;
                    numOfCircle++;
                }
                else
                    numOfCheck++;
            }
            if (numOfCircle > 0)
                afterNextCheckPos = (numOfCheck < checkpointList.size() - 1 ? checkpointList[numOfCheck + 1] : checkpointList[0]);
            lastCheckPos = nextCheckPos;
        }

        Point nextCheckRelPos = nextCheckPos - podPos;
        Point podDir = normWithMul(RotateWithAngle(nextCheckRelPos, -nextCheckpointAngle), 100.0);
        // TODO Point podAngle = 
        cerr << "Pod heading vec: " << podDir.x << " " << podDir.y << endl;
        cerr << "Pod real steering vec: " << podSteering.x << " " << podSteering.y << endl;
        cerr << "Pod speed: " << podSpeed << endl;
        
        Point target = nextCheckPos;
        bool doShield = false;
        // optimizing target position:
        if (nextCheckpointDist > 1000)
        {
            Point reqSteering = normWithMul(nextCheckRelPos, len(podSteering));
            Point correction = reqSteering - podSteering;
            target += correction;
        }
        else if (numOfCircle > 0 && nextCheckpointDist < 1000 /* && pod steering toward the next checkpoint */)
        {
            target = afterNextCheckPos;
            if (len(oppRelPos) < 600)
                doShield = true;
        }

        int thrust = 0;

        if (abs(nextCheckpointAngle) > 90)
            thrust = 1;
        else if (nextCheckpointDist < 500)
            thrust = 25;
        else if (nextCheckpointDist < 1000)
            thrust = 50;
        else if (nextCheckpointDist < 2000)
            thrust = 75;
        else if (abs(nextCheckpointAngle) > 60)
            thrust = 50;
        else if (abs(nextCheckpointAngle) > 30)
            thrust = 75;
        else
            thrust = 100;
            
        string thrust_text = to_string(thrust);
        
        bool doBoost = boost_left > 0 && abs(nextCheckpointAngle) < 5 && nextCheckpointDist > 5000;
        doBoost &= !(oppDist < 2000 && abs(angle(podSteering, oppRelPos)) < 30);
        if (doBoost)
        {
            --boost_left;
            thrust_text = "BOOST";
            cerr << "now BOOST" << endl;
        }
        else if (doShield)
        {
            thrust_text = "SHIELD";
            cerr << "now SHIELD" << endl;
        }

        // You have to output the target position
        // followed by the power (0 <= thrust <= 100)
        // i.e.: "x y thrust"

        cout << target.x << " " << target.y << " " << thrust_text << endl;
        podLastPos = podPos;
    }
}
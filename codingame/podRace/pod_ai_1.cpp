#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
 
struct Point
{
    int x;
    int y;
};

Point operator+ (const Point p1, const Point p2)
{
    return {p1.x + p2.x, p1.y + p2.y};
}

int main()
{

    vector<Point> checkpointList;
    checkpointList.reserve(5);
    
    int boost_left = 1;

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

        int targetX = nextCheckpointX;
        int targetY = nextCheckpointY;
        int thrust = 0;
        if (nextCheckpointAngle > 90 || nextCheckpointAngle < -90)
            thrust = 1;
        else if (nextCheckpointDist < 500)
            thrust = 5;
        else if (nextCheckpointDist < 1000)
            thrust = 25;
        else if (nextCheckpointDist < 2000)
            thrust = 50;
        else if (nextCheckpointAngle > 60 || nextCheckpointAngle < -60)
            thrust = 50;
        else if (nextCheckpointAngle > 30 || nextCheckpointAngle < -30)
            thrust = 75;
        else
            thrust = 100;
            
        string thrust_text = to_string(thrust);
        
        if (boost_left > 0 && (nextCheckpointAngle < 5 && nextCheckpointAngle > -5) && nextCheckpointDist > 5000)
        {
            --boost_left;
            thrust_text = "BOOST";
            cerr << "now BOOST" << endl;
        }

        // You have to output the target position
        // followed by the power (0 <= thrust <= 100)
        // i.e.: "x y thrust"

        cout << targetX << " " << targetY << " " << thrust_text << endl;
    }
}
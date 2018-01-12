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

        //TODO add angle check to speed
        int thrust = nextCheckpointDist > 150 ? 100 : 50;
        if (nextCheckpointDist < 20)
            thrust = 0;
        else if (nextCheckpointDist < 75)
            thrust = 25;

        // You have to output the target position
        // followed by the power (0 <= thrust <= 100)
        // i.e.: "x y thrust"

        cout << targetX << " " << targetY << " " << thrust << endl;
    }
}
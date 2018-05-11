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
    Point& operator*= (const double s);
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

double operator* (const Point p1, const Point p2)
{
    return (double)p1.x * (double)p2.x + (double)p1.y * (double)p2.y;
}

Point operator* (const Point p1, const double s)
{
    return {(double)p1.x * s, (double)p1.y * s};
}

Point operator* (const double s, const Point p1)
{
    return p1 * s;
}

Point& Point::operator*= (const double s)
{
    this->x *= s;
    this->y *= s;
    return *this;
}

double len(const Point p)
{
    return sqrt(p * p);
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

int angleOf(Point p)
{
    return rad2deg(atan2(p.y, p.x));
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

struct PodData
{
    Point pos{UNDEF_INT, UNDEF_INT};
    Point steering{UNDEF_INT, UNDEF_INT};
    int dirAngle{-1};
    int nextCheckId{0};
    int speed{-1};
    int boostLeft{-1};
    Point dirNorm{UNDEF_INT, UNDEF_INT};
    Point target{UNDEF_INT, UNDEF_INT};
    bool checkpointReached = false;
    string thrustText;
};

static void fillExtraPodData(PodData & pod, const PodData * prevState = nullptr)
{
    pod.speed = len(pod.steering);
    pod.dirNorm = RotateWithAngle({+100,0}, pod.dirAngle);
    // TODO calculate extra datas from prev state, eg. acceleration, realSteering
    if (prevState)
    {
        pod.checkpointReached = (pod.nextCheckId != prevState->nextCheckId);
    }
}

int getSuggestedThrottleByAngle(const int angle)
{
    int a = abs(angle);
    int thrust = 100;
    if (a > 90)
        thrust = 1;
    else if (a > 60)
        thrust = 50;
    else if (a > 30)
        thrust = 75;
    else
        thrust = 100;
    return thrust;
}

void iterateOneTurn(PodData &pod)
{
    const double friction = 0.85;
    const int rotationSpeed = 18;
    // frictioning the latest speed vector
    pod.steering *= friction;
    // rotate the heading vector toward the next target with rotation speed
    Point pod2target = pod.target - pod.pos;
    if (angle(pod.dirNorm, pod.target - pod.pos) < rotationSpeed)
    {
        pod.dirNorm = normWithMul(pod2target, pod.speed);
    }
    else
    {
        int c = (angleOf(pod2target) < angleOf(pod.dirNorm)) ? -1 : 1;
        pod.dirNorm = RotateWithAngle(pod.dirNorm, c * rotationSpeed);
    }
    // calc additional speed, normWithMul it to the heading vector
    double t = getSuggestedThrottleByAngle(angle(pod.dirNorm, pod2target));
    Point acc = normWithMul(pod.dirNorm, t);
    // add the acceleration to the current steering
    pod.steering += acc;
    // moving by steering
    pod.pos += pod.steering;
}

bool isTouchingCheckIfTurningNow(const PodData &pod, const Point nextCheckPos, const Point afterNextCheckPos)
{
    const int touchingDistance = 500; // 600 is the checkpoint radius
    const int maxIterationSteps = 20;
    int distanceIncreasingTurnLimit = 3;
    PodData testPod = pod;
    testPod.target = afterNextCheckPos;

    int dist = len(testPod.pos - nextCheckPos);
    for (int i = 0; i < maxIterationSteps; ++i)
    {
        iterateOneTurn(testPod);
        int currDist = len(testPod.pos - nextCheckPos);
        if (currDist < touchingDistance)
            return true;
        if (currDist > dist)
            --distanceIncreasingTurnLimit;
        if (distanceIncreasingTurnLimit <= 0)
            break;
        dist = currDist;
    }
    return false;
}

int main()
{

    vector<Point> checkpointList;
    checkpointList.reserve(8);
    int numOfLaps = 0;
    int turn = 0;

    vector<PodData> podList(2);
    vector<PodData> oppList(2);

    // Point podLastPos{UNDEF_INT, UNDEF_INT};
    // Point lastCheckPos{UNDEF_INT, UNDEF_INT};
    // Point afterNextCheckPos{UNDEF_INT, UNDEF_INT};

    // init data

    cin >> numOfLaps;
    size_t numOfChecks;
    cin >> numOfChecks;
    checkpointList.resize(numOfChecks, {UNDEF_INT, UNDEF_INT});
    for (auto & checkpoint : checkpointList)
        cin >> checkpoint.x >> checkpoint.y;
    for (auto & pod : podList)
    {
        pod.boostLeft = 1;
        // TODO test and fix basic starting angle
        pod.dirAngle = angle(checkpointList[0] - *checkpointList.crbegin(), {100, 0});
    }

    // game loop

    while (1)
    {
        // input data

        for (auto & pod : podList)
        {
            PodData _prevState = pod;
            cin >> pod.pos.x >> pod.pos.y >> pod.steering.x >> pod.steering.y >> pod.dirAngle >> pod.nextCheckId;
            fillExtraPodData(pod, &_prevState);
        }
        for (auto & opp : oppList)
        {
            PodData _prevState = opp;
            cin >> opp.pos.x >> opp.pos.y >> opp.steering.x >> opp.steering.y >> opp.dirAngle >> opp.nextCheckId;
            fillExtraPodData(opp, &_prevState);
        }

        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;
        
        for (auto & pod : podList)
        {
            // basic AI based on pod_ai_1.cpp

            auto oppClosest = min_element(oppList.cbegin(), oppList.cend(),
                [&pod](const PodData &p1, const PodData &p2) { return len(p1.pos - pod.pos) < len(p2.pos - pod.pos); });
            Point oppRelPos = oppClosest->pos - pod.pos;
            int oppDist = len(oppRelPos);
            const Point nextCheckPos = checkpointList[pod.nextCheckId];
            const Point afterNextCheckPos = (pod.nextCheckId < numOfChecks - 1 ? checkpointList[pod.nextCheckId + 1] : checkpointList[0]);
            Point nextCheckRelPos = nextCheckPos - pod.pos;
            int nextCheckDist = len(nextCheckRelPos);
            cerr << "Pod heading vec: " << pod.dirNorm.x << " " << pod.dirNorm.y << endl;
            cerr << "Pod angle: " << pod.dirAngle << endl;
            cerr << "Pod real speed vec: " << pod.steering.x << " " << pod.steering.y << endl;
            cerr << "Pod speed: " << pod.speed << endl;

            pod.target = nextCheckPos;
            bool doShield = false;
            // optimizing target position:
            if (nextCheckDist > 1200)
            {
                Point reqSteering = normWithMul(nextCheckRelPos, pod.speed);
                Point correction = reqSteering - pod.steering;
                pod.target += correction;
            }
            if (nextCheckDist < 4000 && isTouchingCheckIfTurningNow(pod, nextCheckPos, afterNextCheckPos))
            {
                pod.target = afterNextCheckPos;
                cerr << "drifting enough to reach CheckPt" << endl;
                if (oppDist < 700)
                    doShield = true;
            }

            int thrust = 0;
            int nextCheckRelAngle = angle(pod.dirNorm, nextCheckRelPos);
            int nextTargetRelAngle = angle(pod.dirNorm, pod.target - pod.pos);
            cerr << "next CheckPt rel dir: " << nextCheckRelPos.x << " " << nextCheckRelPos.y << endl;
            cerr << "next target rel angle: " << nextCheckRelAngle << endl;

            if (turn < 2)
                thrust = 100;
            else
                thrust = getSuggestedThrottleByAngle(nextTargetRelAngle);

            pod.thrustText = to_string(thrust);

            bool doBoost = pod.boostLeft > 0 && abs(nextCheckRelAngle) < 5 && nextCheckDist > 5000;
            doBoost &= !(oppDist < 2000 && abs(angle(pod.steering, oppRelPos)) < 30);
            if (doBoost)
            {
                --pod.boostLeft;
                pod.thrustText = "BOOST";
                cerr << "now BOOST" << endl;
            }
            else if (doShield)
            {
                pod.thrustText = "SHIELD";
                cerr << "now SHIELD" << endl;
            }
        }

        // You have to output the target position
        // followed by the power (0 <= thrust <= 100)
        // i.e.: "x y thrust"

        // output command handling

        for (auto & pod : podList)
        {
            cout << pod.target.x << " " << pod.target.y << " " << pod.thrustText << endl;
        }
        ++turn;
    }
}
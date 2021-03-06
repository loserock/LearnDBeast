## Link

<https://www.codingame.com/ide/puzzle/coders-strike-back>

## Rules

### Expert Rules

The game is played on a map 16000 units wide and 9000 units high. The coordinate X=0, Y=0 is the top left pixel.

The checkpoints work as follows:
The checkpoints are circular, with a radius of 600 units.
The disposition of the checkpoints is selected randomly for each race.
The pods work as follows:
If none of your pods make it to their next checkpoint in under 100 turns, you are eliminated and lose the game.
The pods may move normally outside the game area.

Note: You may activate debug mode in the settings panel () to view additional game data.

#### Note

The program must, within an infinite loop, read the contextual data from the standard input and provide to the standard output the desired instructions.

#### Game Input

Input for one game turn
First line: 6 integers x & y for your pod's position. nextCheckpointX & nextCheckpointY for the coordinates of the next checkpoint the pod must go through. nextCheckpointDist for the computed distance between your pod and the next checkpoint, nextCheckpointAngle for the angle in degrees between your pod orientation and the direction of the next checkpoint (from -180 to 180).

Second line: 2 integers opponentX & opponentY for the opponent pod's position.
Output for one game turn
One line: 2 integers for the target coordinates of your pod followed by thrust, the thrust to give to your pod.
Constraints
0 ≤ thrust ≤ 100
Response time first turn ≤ 1000ms
Response time per turn ≤ 150ms

### New Rules above Silver League

You now control two pods instead of one. Additionally, you will receive exhaustive game information to create a powerful AI.

The i/o protocol has been modified. Please refer to the updated statement section for details.

#### Updated Rules for two Pods

The players each control a team of two pods during a race. As soon as a pod completes the race, that pod's team is declared the winner.
The circuit of the race is made up of checkpoints. To complete one lap, your vehicle (pod) must pass through each one in order and back through the start. The first player to reach the start on the final lap wins.

The game is played on a map 16000 units wide and 9000 units high. The coordinate X=0, Y=0 is the top left pixel.

The checkpoints work as follows:

    The checkpoints are circular, with a radius of 600 units.
    Checkpoints are numbered from 0 to N where 0 is the start and N-1 is the last checkpoint.
    The disposition of the checkpoints is selected randomly for each race.

The pods work as follows:

    To pass a checkpoint, the center of a pod must be inside the radius of the checkpoint.
    To move a pod, you must print a target destination point followed by a thrust value. Details of the protocol can be found further down.
    The thrust value of a pod is its acceleration and must be between 0 and 100.
    The pod will pivot to face the destination point by a maximum of 18 degrees per turn and will then accelerate in that direction.
    You can use 1 acceleration boost in the race, you only need to replace the thrust value by the BOOST keyword.
    You may activate a pod's shields with the SHIELD command instead of accelerating. This will give the pod much more weight if it collides with another. However, the pod will not be able to accelerate for the next 3 turns.
    The pods have a circular force-field around their center, with a radius of 400 units, which activates in case of collisions with other pods.
    The pods may move normally outside the game area.
    If none of your pods make it to their next checkpoint in under 100 turns, you are eliminated and lose the game.

On each turn the pods movements are computed this way:

    Rotation: the pod rotates to face the target point, with a maximum of 18 degrees (except for the 1rst round).
    Acceleration: the pod's facing vector is multiplied by the given thrust value. The result is added to the current speed vector.
    Movement: The speed vector is added to the position of the pod. If a collision would occur at this point, the pods rebound off each other.
    Friction: the current speed vector of each pod is multiplied by 0.85
    The speed's values are truncated and the position's values are rounded to the nearest integer.

Collisions are elastic. The minimum impulse of a collision is 120.
A boost is in fact an acceleration of 650.
A shield multiplies the Pod mass by 10.
The provided angle is absolute. 0° means facing EAST while 90° means facing SOUTH.

#### Game Input for two Pods

##### Initialization input

Line 1: laps : the number of laps to complete the race.
Line 2: checkpointCount : the number of checkpoints in the circuit.
Next checkpointCount lines : 2 integers checkpointX , checkpointY for the coordinates of checkpoint.

##### Input for one game turn

First 2 lines: Your two pods.
Next 2 lines: The opponent's pods.
Each pod is represented by: 6 integers, x & y for the position. vx & vy for the speed vector. angle for the rotation angle in degrees. nextCheckPointId for the number of the next checkpoint the pod must go through.

##### Output for one game turn

Two lines: 2 integers for the target coordinates of your pod followed by thrust , the acceleration to give your pod, or by SHIELD to activate the shields, or by BOOST for an acceleration burst. One line per pod.
Constraints
0 ≤ thrust ≤ 100
2 ≤ checkpointCount ≤ 8
Response time first turn ≤ 1000ms
Response time per turn ≤ 75ms

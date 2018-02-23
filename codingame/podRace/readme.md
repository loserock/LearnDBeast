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
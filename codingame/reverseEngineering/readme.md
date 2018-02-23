## Link

<https://www.codingame.com/ide/puzzle/codingame-sponsored-contest>

## Rules

### The Goal

At CodinGame we love inventing new games but developing a game requires a lot of work. We need to agree on the rules, implement a referee to determine whether a solution is correct or not, develop the graphics engine and finally test the game itself. In order to keep improving CodinGame we need to increase the size of our team.

This time, we won't do the graphical part. We won't even bother telling you what the inputs are. It's up to you to understand what you need to do in order to achieve the best possible score.

We will also participate in this challenge, do you think you can beat us?

The possible actions are A, B, C, D and E.

### Game Input

#### Initialization input

Line 1: an integer.
Line 2: an integer.
Line 3: an integer.

#### Input for one game turn

Line 1: a character.
Line 2: a character.
Line 3: a character.
Line 4: a character.
Next few lines: two integers on each line.

#### Output for one game turn

A single line containing one of the following actions: A, B, C, D or E

#### Constraints

Duration of one game turn: 100 ms

## Hints

### Hint 1

This puzzle is a bit particular, in the sense that in order to solve it you must first understand what you're expected to do. This might be confusing at first, but that is intended.

At each turn, you are given 4 characters followed by several lines each containing a pair of integers. These numbers represent the coordinates of the game characters, including yours.

Find out what makes the game end and try to keep it running as long as possible.

### Hint 2

At the end of each game you obtain a score that depends on your movements. If you do not output any invalid action, you'll obtain at least a score of 2. Under certain conditions, you can be rewarded additional points.

Actions A, B, C, D and E allow you to move in the four directions or to hold still. If at the end of the game you have a score of 2, you can deduce that you did not succeed to move. Use this to determine what your coordinates are among the list of coordinates, then identify the meaning of the actions.

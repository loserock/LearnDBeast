## Improvement tasks

### Info calculations

 - Need prediction for the next few rounds!
    - Calculate it in the beginning of every round.
    - Could far-seeing it with predicted strategy: this is the current steering, but the actual pod shall moving there and there...

### Ideal arc

#### Info sources

 - [Many articles](http://vamos.sourceforge.net/computer-controlled-cars/computer-controlled-cars.html)
 - [Just the ideal radius](https://math.stackexchange.com/questions/289575/car-racing-how-to-calculate-the-radius-of-the-racing-line-through-a-turn-of-var)

#### Ideas

 - The arc alone is useless. I need the heading and speed datas, which also based on the current place in the phase-space.
 - Calculating the full phase-space is too resource hungry. :(
 - A three-point calculation could be nice: pod state (position and steering), next checkpoint, after next checkpoint.
 - [x] First: check the earliest turning point by iterating the following N turn!
 - [] Hard coding full throttle to target when finishing.

### Teamwork

### Engaging with rivals

#### Shield usage

 - Check the benefit of shielding in every turn!
 - Enemy close: with the next predicted positions (positions and current steering)

### Others

Currently nothing.
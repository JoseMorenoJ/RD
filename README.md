# Introduction

As part of a course about OO programming design with UML and C++, we started doing a little command line app representing the game Reckless Driver. We will now try to apply the knowledge from the book (game programming patterns to practice and understand better the patterns and the design decisions behind them.

## Reckless Driver
The game consists on a driver (the player) that obtains points as he crashes with things down the road. Every crash will reduce the integrity of the car until it cannot be driven anymore. 

The game is fun, I have played it some time ago, the real game, but I don't remember where. An online games site or something like that.

## Contents
Right now, the game doesn't really look like a game. We have the main programming but the player cannot control anything. The objects appear and randomly, the car will colide with one. The player gets the points and loses some health points. The game finishes when there are no health points left. 

The mechanics of the game work but noone actually plays it.

# Features
## Last updates
After we added the HUB class to print the screen, we managed to break the collisions. No object was colliding anymore. Now it is fixed.
This HUB object is now in charge of printing out the objects and the info about the game. 
Although it is not finished, we will try to encapsulate all the command line control there.

## Immediate developement
We created the branch *component_pattern* to modify our GameObjects using that pattern.

More general, we will tidy up our design to be able to add the future features. The first feature should be to give control to the player.
  - Next thing to consider would be to add a position to the Game Objects and erase the random crashes.

## Future updates  
  - I want to consider to modify the ObjectPool class as this [ObjectPool](http://www.gameprogrammingpatterns.com/object-pool.html) pattern. 
  - For a far future, add the graphics and stop using the command window. That will require more thinking than this.
  - Also for a far future, applygin the [Lightweight](http://www.gameprogrammingpatterns.com/flyweight.html) pattern to the ObjectPool. 

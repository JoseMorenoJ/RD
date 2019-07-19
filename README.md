# Introduction

As part of a course about OO programming design with UML and C++, we started doing a little command line app representing the game Reckless Driver. We will now try to apply the knowledge from the book (game programming patterns to practice and understand better the patterns and the design decisions behind them.

## Reckless Driver
The game consists on a driver (the player) that obtains points as he crashes with things down the road. Every crash will reduce the integrity of the car until it cannot be driven anymore. 

The game is fun, I have played it some time ago, the real game, but I don't remember where. An online games site or something like that.

## Contents
Right now, you still play in a command line tool but you can control the player. The objects appear and randomly and come to you, you have to crash with them. The player gets the points and loses some health points. The game finishes when there are no health points left. 

The mechanics of the game work but noone actually plays it.

# Features
## Last updates
I work in waves of free time and motivation.
### First wave
  -DONE After we added the HUB class to print the screen, we managed to break the collisions. No object was colliding anymore. Now it is fixed.
  - DONE:This HUB object is now in charge of printing out the objects and the info about the game. 
  - DONE: Although it is not finished, we will try to encapsulate all the command line control (system dependendt )there in a system class.

### July 2019 wave
  - DONE: We created the branch *component_pattern* to modify our GameObjects using that pattern.
  - DONE: Next thing to consider would be to add a position to the Game Objects and erase the random crashes.
  - DONE: I want to consider to modify the ObjectPool class as this [ObjectPool](http://www.gameprogrammingpatterns.com/object-pool.html) pattern. 
  - DONE: The first feature should be to give control to the player.
  - DONE: More general, we will tidy up our design to be able to add the future features.

## Immediate developement
Develope the crashes, there are no collisions now.
BUG: Check the GameObject generation, it shows glitches from time to time in the row 0.
Work on the graphics window, use SFML to create the window and represent the objects.

## Future updates  
  - Give a choice to the Player about what car to drive.
  - Introduce a police car to dodge instead of to crash with it.
  - Introduce Boosts.
  - Use music resources.
  - Also for a far future, applying the [Lightweight](http://www.gameprogrammingpatterns.com/flyweight.html) pattern to the ObjectPool. 

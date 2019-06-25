# Introduction
## Udemy Course
A course about OO programming design with UML and C++. The course wasn't finished in Udemy though.

## Reckless Driver
This is about driving and crashing to things without breaking your car.
The game is fun.

## Contents
The game main part is designed but only as a win32/terminal application. It doesn't get any input from the player. It generates random objects in the road and random colissions with them. It stops when the health points of the car are below zero.

## Last updates
After we added the HUB class to print the screen, we managed to break the collisions. No object was colliding anymore. No it is fixed.

## Future updates
  - I want to consider to modify the ObjectPool class as this [ObjectPool](http://www.gameprogrammingpatterns.com/object-pool.html) pattern. 
  - Next thing to consider would be to add a position to the Game Objects and erase the random crashes.
  - For a far future, add the graphics and stop using the comand window. That will require more thinking than this.
  - Also for a far future, applygin the [Lightweight](http://www.gameprogrammingpatterns.com/flyweight.html) pattern to the ObjectPool. 

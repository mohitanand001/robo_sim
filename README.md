# Toy Robot Simulator
## Table of contents:
* [Best practices I have tried to follow](./README.md#best-practices-i-have-tried-to-follow)
* [Description](./README.md#description)
  * [Constraints](./README.md#constraints)
  * [Example Input and Output](./README.md#example-input-and-output)
* [How to run the file](./README.md#how-to-run-the-file)

## Best practices I have tried to follow
* Not using `using namespace std`
* Using `std::vector` in place of raw array.
* Separation of implementation and interface. ( I have made separate header files for classes and functions decalrations)
* Passed `std::strings` by reference rather than by value, to avoid unnecessay copies.
* Used `const` whenever possible, to avoid the possiblity of changing the argument, when passed by reference.
* Used `pragma once` in order to avoid the possiblity of errors in case a header is written multiple times. 
* Used`member initializer list` instead of `member assignment`

## Description

* The application is a simulation of a toy robot moving on a square tabletop, of dimensions 5 units x 5 units.

* There are no other obstructions on the table surface.

* The robot is free to roam around the surface of the table, but must be prevented from falling to destruction. Any movement that would result in the robot falling from the table must be prevented, however further valid movement commands must still be allowed.

Create an application that can read in commands of the following form:
```
PLACE X,Y,F
MOVE
LEFT
RIGHT
REPORT
```

* `PLACE` will put the toy robot on the table in position X,Y and facing NORTH, SOUTH, EAST or WEST.

* The origin (0,0) can be considered to be the SOUTH WEST most corner.

* The first valid command to the robot is a `PLACE` command, after that, any sequence of commands may be issued, in any order, including another `PLACE` command. The application should discard all commands in the sequence until a valid `PLACE` command has been executed

* `MOVE` will move the toy robot one unit forward in the direction it is currently facing.

* `LEFT` and `RIGHT` will rotate the robot 90 degrees in the specified direction without changing the position of the robot.

* `REPORT` will announce the X,Y and F of the robot. This can be in any form, but standard output is sufficient.

* A robot that is not on the table can choose to ignore the `MOVE`, `LEFT`, `RIGHT` and `REPORT` commands.

* Input can be from a file, or from standard input, as the developer chooses.

* Provide test data to exercise the application.

### Constraints

* The toy robot must not fall off the table during movement. This also includes the initial placement of the toy robot.

* Any move that would cause the robot to fall must be ignored.

### Example Input and Output:

#### Example a

    PLACE 0,0,NORTH
    MOVE
    REPORT

Expected output:

    0,1,NORTH

#### Example b

    PLACE 0,0,NORTH
    LEFT
    REPORT

Expected output:

    0,0,WEST

#### Example c

    PLACE 1,2,EAST
    MOVE
    MOVE
    LEFT
    MOVE
    REPORT

Expected output

    3,3,NORTH


## How to run the file
* One way is to create object files for all the cpp files, and then link them together <br>
`g++ command_parser.cpp -c -std=c++11`<br>
`g++ robo_main.cpp -c -std=c++11`<br>
`g++ robot_simulator.o command_parser.o robo_main.o -o robo_move` <br>
`./robo_move`

* There is also a bash file provided, that can be used to do the above process, automatically
* Just do `bash run.sh` and provide the inputs

# Robo_Sim
### Best practices I have tried to follow
* Not using `using namespace std`
* Using `std::vector` in place of raw array.
* Separation of implementation and interface. ( I have made separate header files for classes and functions decalrations)
* Passed `std::strings` by reference rather than by value, to avoid unnecessay copies.
* Used `const` whenever possible, to avoid the possiblity of changing the argument, when passed by reference.
* Used `pragma once` in order to avoid the possiblity of errors in case a header is written multiple times. 
* Used`member initializer list` instead of `member assignment`

### How to run the file
* One way is to create object files for all the cpp files, and then link them together
`g++ command_parser.cpp -c -std=c++11
g++ robo_main.cpp -c -std=c++11
g++ robot_simulator.o command_parser.o robo_main.o -o robo_move
./robo_move`

* There is also a bash file provided, that can be used to do the above process, automatically
* Just do 'bash run.sh' and provide the inputs
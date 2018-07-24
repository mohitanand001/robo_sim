# Robo_Sim
### Best practices I have tried to follow
* Not using `using namespace std`
* Using `std::vector` in place of raw array.
* Separation of implementation and interface. ( I have made separate header files for classes and functions decalrations)
* Passed `std::strings` by reference rather than by value, to avoid unnecessay copies.
* Used `const` whenever possible, to avoid the possiblity of changing the argument, when passed by reference.
* Used `pragma once` in order to avoid the possiblity of errors in case a header is written multiple times. 
* Used`member initializer list` instead of `member assignment`
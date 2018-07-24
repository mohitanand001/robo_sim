g++ robot_simulator.cpp -c -std=c++11
g++ command_parser.cpp -c -std=c++11
g++ robo_main.cpp -c -std=c++11
g++ robot_simulator.o command_parser.o robo_main.o -o robo_move
./robo_move
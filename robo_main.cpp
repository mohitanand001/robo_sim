#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

#include "command.h"
#include "robo.h"

int main()
{
	std::string command , direction;
	int new_x, new_y ; 

	Robo x; 

	while(true)
	{
		// passing command, new_x, new_y as 
		// reference to parse_commands function
		// this ensures that variables are not copied
		// to prevent inefficiency
		command = "", direction = "";
		parse_command(command, new_x, new_y, direction) ;

		x.issue_command(command, new_x, new_y, direction) ; 
	}
}
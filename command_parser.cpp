#include <iostream>
#include <string>
#include <vector>

#include "command.h"

void parse_command(std::string &command, int &x, int &y, std::string &direction)
{

	std::string whole_command, temp_str = "";
	std::vector<int> dir;

	std::getline(std::cin, whole_command);

	for(int i = 0; whole_command[i] != '\0'; i +=1)
	{	
		temp_str = temp_str + whole_command[i];
		if(whole_command[i] == ' ')
		{
			temp_str.pop_back();
			command = temp_str;
			temp_str = "";
		}
		else if(whole_command[i] == ',')
		{
			dir.push_back(std::stoi(temp_str));
			temp_str = "";
		}
	}

	if(command == "PLACE")
	{
		direction = temp_str; 
		x = dir[0]; 
		y = dir[1];
	}

	else
		command = temp_str;


}
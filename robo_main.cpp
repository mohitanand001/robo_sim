#include<iostream>
#include<string> 

#include "robo.h"
#include "command.h"





int main()
{
	std::string command ;
	
	Robo x; 

	while(true)
	{
		command = parse_commands() ;

		x.give_command(command); 
	}
}
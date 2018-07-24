#include<iostream>
#include <string>

#include "robo.h"

Robo::Robo()
{
	placed_on_table = false;
}


void Robo::move_if_safe()
{
	if(placed_on_table == false)
		return;

	if(is_safe_here(x + dx[face], y + dy[face]) == false)
		return ;

	x = x + dx[face];
	y = y + dy[face];

}

void Robo::report_robo_position()
{
	if(placed_on_table == false)
		return; 
	std::cout << x << " " << y << std::endl;
}

bool Robo::is_safe_here(int new_x, int new_y)
{
	if(new_x < 0 or new_x > 4 or new_y < 0 or new_y > 4)
		return false;

	return true;
}


void Robo::rotate_robo(const std::string command)
{
	// rotate_robo clockwise by 90 degrees
	if(command == "RIGHT")
	{
		face = (face + 1) % 4;
	} 	
	// rotate_robo anti-clockwise by 90 degrees
	else
	{
		face = (face -1 + 4) % 4;
	}
}

void Robo::issue_command(const std::string command)
{
	if(command == "MOVE")
	{
		// move robo only if it is safe, i.e. it 
		// does not go out of boundary
		move_if_safe(); 
	}

	else if(command == "LEFT" or command == "RIGHT")
	{
		rotate_robo(command) ;
	}

	else if(command == "REPORT")
	{
		report_robo_position() ;
	}

	else
	{
		place_if_safe() ;
	}
}
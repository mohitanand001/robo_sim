#include <iostream>
#include <string>
#include <map>
#include <vector>

#include "robo.h"

Robo::Robo()
{
	placed_on_table = false;
	direction_map["NORTH"] = 0, direction_map["EAST"] = 1, direction_map["SOUTH"] = 2, direction_map["WEST"] = 3;
	dx = {0, 1, 0, -1};
	dy = {1, 0, -1, 0};

}

// utility function
bool Robo::is_safe_here(int new_x, int new_y)
{
	if(new_x < 0 or new_x > 4 or new_y < 0 or new_y > 4)
		return false;

	return true;
}

// MOVE
void Robo::move_if_safe()
{
	if(placed_on_table == false)
		return;

	if(is_safe_here(x + dx[face], y + dy[face]) == false)
		return ;

	x = x + dx[face];
	y = y + dy[face];

}

// REPORT
void Robo::report_robo_position()
{
	if(placed_on_table == false)
		return; 
	std::cout << x << " " << y <<  " " << face << std::endl;
}

// LEFT or RIGHT
void Robo::rotate_robo(const std::string &command)
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

// PLACE X, Y, face

void Robo::place_if_safe(int new_x, int new_y, const std::string &direction)
{
	if(is_safe_here(new_x, new_y) == false)
		return;

	x = new_x;
	y = new_y;
	face = direction_map[direction]; 
	placed_on_table = true;

}

// Handles all command
void Robo::issue_command(const std::string &command, int new_x, int new_y, const std::string &direction)
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
		place_if_safe(new_x, new_y, direction) ;
	}
}
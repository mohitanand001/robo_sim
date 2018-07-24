#include<iostream>
#include <string>

#include "robo.h"

Robo::Robo()
{
	placed_on_table = false;
}

// void Robo::set_val(int a, int b)
// {
// 	x = a;
// 	y = b;
// }

// void Robo::get_val()
// {
// 	std::cout << x << " " << y << std::endl;
// }

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
	// std::cout
}

bool Robo::is_safe_here(int new_x, int new_y)
{
	if(new_x < 0 or new_x > 4 or new_y < 0 or new_y > 4)
		return false;

	return true;
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
		rotate_robo() ;
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
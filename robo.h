#pragma once

class Robo{

	private:
		int x ; 
		int y ;
		bool placed_on_table ;
		int face ;
		std::vector<int> dx;
		std::vector<int> dy;
		std::map< std::string, int> direction_map;  
		std::map< int, std::string> rev_direction_map;
	public:

		Robo();

		void issue_command(const std::string &command, int new_x, int new_y, const std::string &direction) ; 

		void rotate_robo(const std::string &command);

		void report_robo_position(); 

		bool is_safe_here(int new_x, int new_y); 

		void move_if_safe() ; 

		void place_if_safe(int new_x, int new_y, const std::string &direction);
};

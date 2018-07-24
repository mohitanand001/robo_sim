#pragma once

class Robo{

	private:
		int x ; 
		int y ;
		bool placed_on_table ;
		int face ;
		int dx[] = {0, 1, 0, -1};
		int dy[] = {1, 0, -1, 0};  
	public:

		Robo();

		void issue_command() ; 

		void rotate_robo() ;

		void report_robo_position(); 

		bool is_safe_here(); 

		void move_if_safe() ; 

		void place_if_safe() ;
};

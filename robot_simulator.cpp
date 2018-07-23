
#include<iostream>

class Robo{

	private:
		int x ; 
		int y ;
		std::string face ;  
		static bool placed_on_table ;

	public:
		// default constructor using member initializer list 
		Robo() :
		{face("");} 

		void set_position_or_face(char face, int x, int y)
		{
			this->x = x;
			this->y = y;
			this->face = face;
		}

		void set_position_or_face(std::string face)
		{
			this->face = face; 
		}

		void set_face(std::string face)
		{
			this->face = face; 
		}

		void report_position()
		{
			std:: cout << this->x << " " << this->y << std:: endl; 
		}

		void issue_command(const std::string &comm, )
		{
			if(comm == "MOVE" and is_safe_after_moving(x, y, face))
			{
				set_position(face, x , y); 
			}

			else if(comm == "PLACE ")
			{
				placed_on_table = true; 				
			}

			else
			{
				set_position_or_face(comm); 
			}
		}

};
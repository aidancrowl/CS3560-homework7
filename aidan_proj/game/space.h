//Program:      space.h (Project 6)

//Author:       Aidan Crowl
//Email:        ac833914@ohio.edu

//Lab section:  2626, Pin Zhang

//Description:  This program is the definition and implementation of the class Space.

//Date: April 23, 2017

#include <iostream>
#ifndef SPACE_H
#define SPACE_H

class Space {
	public:
	   Space()
	   {
		occupied = false;
		red = false;
		white = false;
		king = false;
	   }

	   bool is_occupied()const{return occupied;}
	   bool is_empty()const{return !occupied;}
	   bool is_red()const{return red;}
	   bool is_white()const{return white;}
	   bool is_king()const{return king;}

	   void make_empty(){occupied = false; white = false; red = false; king = false;}
	   void place_red(){occupied = true; red = true; white = false;}
	   void place_white(){occupied = true; red = false; white = true;}
	   void make_king(){king = true;}

	private:
	   bool occupied;
	   bool red;
	   bool white;
	   bool king;
};

#endif

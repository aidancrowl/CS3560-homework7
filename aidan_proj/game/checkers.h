//Program:      checkers.h (Project 6)

//Author:       Aidan Crowl
//Email:        ac833914@ohio.edu

//Lab section:  2626, Pin Zhang

//Description:  This program is the definition for the child class Checkers.

//Date: April 23, 2017

#include <iostream>
#include "colors.h"
#include "space.h"
#include "game.h"
#ifndef CHECKERS_H
#define CHECKERS_H

namespace main_savitch_14
{

class Checkers:public game {
	public:
	   Checkers();
	   void restart();
	   void display_status()const;
	   bool is_legal(const std::string& move)const;
	   void make_move(const std::string& move);
	   bool is_jump_available()const;
	   bool is_move_jump(const std::string& move)const;
	   bool next_jump(const std::string& move)const;
	   bool route_exists(const std::string& move)const;
	   bool is_game_over()const;
	   void make_jump(const std::string& move);
	   int evaluate()const;
	   game* clone()const;
	   void compute_moves(std::queue<std::string>& moves)const;

	private:
	   Space board[8][8];
};
}

#endif

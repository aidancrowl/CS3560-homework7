//Alexis Lanier
//Project 6 Part 1
//mancala.h

#ifndef MANCALA_H
#define MANCALA_H
#include <queue>
#include "game.h"
#include "colors.h"

using namespace std;
using namespace main_savitch_14;

class mancala:public main_savitch_14::game{
	public:
		void display_status() const;
		bool is_legal(const string &move) const;
		void make_move(const string &move);
		void restart();
		bool is_game_over()const;
		game* clone()const;
		who winning()const;
		int evaluate()const;
		void compute_moves(std::queue<std::string>& moves) const;
		string get_user_move( ) const;

	private:
		int board[14] = {0, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 0};
		queue <string> moves;
		bool extra = false;
		bool over = false;
};
#endif

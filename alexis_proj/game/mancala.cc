//Alexis Lanier
//Project 6 Part 1
//mancala.cc

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <queue>
#include "mancala.h"

using namespace std;
using namespace main_savitch_14;

void mancala :: display_status() const{      //my board prints out correctly you just have to zoom out in the terminal because it's too big and I didn't have time to 														fix it
	cout << B_BLACK << YELLOW << "                  ---------------------------------------------------------------------------------------------------------                    " << endl;
	cout << B_BLACK << YELLOW << "                  |       1        |        2        |       3        |        4       |        5        |       6        |                    " << endl;
	cout << B_BLACK << YELLOW << "                  ---------------------------------------------------------------------------------------------------------                    " << endl;
	cout << B_BLACK << WHITE << " |";
	for(int r = 0; r < 2; r++){
		if(r == 0){
			cout << B_BLACK << WHITE << "     ******     " << "   ";
			for(int i = 0; i < 6; i++)
				cout << B_BLACK << WHITE << "      **      " << "   ";
			cout << B_BLACK << WHITE << "     ******     " << "   ";
		}else if(r == 1){
			cout << B_BLACK << WHITE << "  *          *  " << "   ";
			for(int i = 0; i < 6; i++)
				cout << B_BLACK << WHITE << "      **      " << "   ";
			cout << B_BLACK << WHITE << "  *          *  " << "   ";
		}

		cout << "|";
		cout << endl;
		cout << " |";

		if(r == 0){
			cout << B_BLACK << WHITE << "   *        *   " << "   ";
			for(int i = 0; i < 6; i++)
				cout << B_BLACK << WHITE << "   *      *   " << "   ";
			cout << B_BLACK << WHITE << "   *        *   " << "   ";
		}else if(r == 1){
			cout << B_BLACK << WHITE << "  *          *  " << "   ";
			for(int i = 0; i < 6; i++)
				cout << B_BLACK << WHITE << "   *      *   " << "   ";
			cout << B_BLACK << WHITE << "  *          *  " << "   ";
		}

		cout << "|";
		cout << endl;
		cout << " |";

		if(r == 0){
			cout << B_BLACK << WHITE << "  *          *  " << "   ";
			for(int i = 0; i < 6; i++)			
				cout << B_BLACK << WHITE << " *          * " << "   ";
			cout << B_BLACK << WHITE << "  *          *  " << "   ";
		}else if(r == 1){
			cout << B_BLACK << WHITE << "  *          *  " << "   ";
			for(int i = 0; i < 6; i++)			
				cout << B_BLACK << WHITE << " *          * " << "   ";
			cout << B_BLACK << WHITE << "  *          *  " << "   ";
		}

		cout << "|";
		cout << endl;
		cout << " |";

		if(r == 0){
			cout << B_BLACK << WHITE << "  *    " << YELLOW << setw(2) << setfill(' ') << right << board[0] << WHITE << "    *  " << "   ";
			for(int i = 0; i < 6; i++)
				cout << B_BLACK << WHITE << "*    " << YELLOW << setw(2) << setfill(' ') << right << board[i + 1] << WHITE << "     *" << "    ";
			cout << B_BLACK << WHITE << "  *    " << YELLOW << setw(2) << setfill(' ') << right << board[13] << WHITE << "    *  " << "   ";
		}else if(r == 1){
			cout << B_BLACK << WHITE << "  *    " << YELLOW << setw(2) << setfill(' ') << right << board[0] << WHITE << "    *  " << "   ";
			for(int i = 0; i < 6; i++)
				cout << B_BLACK << WHITE << "*    " << YELLOW << setw(2) << setfill(' ') << right << board[i + 7] << WHITE << "     *" << "    ";
			cout << B_BLACK << WHITE << "  *    " << YELLOW << setw(2) << setfill(' ') << right << board[13] << WHITE << "    *  " << "   ";
		}

cout << "|";
		cout << endl;
		cout << " |";


		if(r == 0){
			cout << B_BLACK << WHITE << "  *          *  " << "   ";
			for(int i = 0; i < 6; i++)
				cout << B_BLACK << WHITE << " *          * " << "   ";
			cout << B_BLACK << WHITE << "  *          *  " << "   ";
		}else if(r == 1){
			cout << B_BLACK << WHITE << "  *          *  " << "   ";
			for(int i = 0; i < 6; i++)
				cout << B_BLACK << WHITE << " *          * " << "   ";
			cout << B_BLACK << WHITE << "  *          *  " << "   ";
		}

		cout << "|";
		cout << endl;
		cout << " |";
		
		if(r == 0){
			cout << B_BLACK << WHITE << "  *          *  " << "   ";
			for(int i = 0; i < 6; i++)
				cout << B_BLACK << WHITE << "   *      *   " << "   ";
			cout << B_BLACK << WHITE << "  *          *  " << "   ";
		}else if(r == 1){
			cout << B_BLACK << WHITE << "   *        *   " << "   ";
			for(int i = 0; i < 6; i++)
				cout << B_BLACK << WHITE << "   *      *   " << "   ";
			cout << B_BLACK << WHITE << "   *        *   " << "   ";
		}

		cout << "|";
		cout << endl;
		cout << " |";
	
		if(r == 0){
			cout << B_BLACK << WHITE << "  *          *  " << "   ";
			for(int i = 0; i < 6; i++)
				cout << B_BLACK << WHITE << "      **      " <<  "   ";
			cout << B_BLACK << WHITE << "  *          *  " << "   ";
		}else if(r == 1){
			cout << B_BLACK << WHITE << "     ******     " << "   ";
			for(int i = 0; i < 6; i++)
				cout << B_BLACK << WHITE << "      **      " <<  "   ";
			cout << B_BLACK << WHITE << "     ******     " << "   ";
		}

		cout << "|";
		cout << endl;
		cout <<" |";
	}
	
	cout << B_BLACK << YELLOW << "                ---------------------------------------------------------------------------------------------------------                    " << endl;
	cout << B_BLACK << YELLOW << "                  |       7        |        8        |       9        |       10       |       11        |      12        |                    " << endl;
	cout << B_BLACK << YELLOW << "                  ---------------------------------------------------------------------------------------------------------                    " << endl;                         
	cout << endl << RESET;
}

bool mancala :: is_legal(const string &move) const{
	if((move >= "a" && move <= "z") || (move >= "A" && move <= "Z"))
		return false;
	int bin_num = stoi(move);
	if(move.size() > 2)
		return false;
	else{
		if(bin_num < 1 || bin_num > 12)
			return false;
		else if(board[bin_num] == 0)
			return false;
		//computer is player two and computers side is top
		else{
			if(last_mover() == COMPUTER){
				if(bin_num >=7 && bin_num <= 12)
					return true;
				else
					return false;
			}else if(last_mover() == HUMAN){
				if(bin_num >= 1 && bin_num <= 6)
					return true;
				else
					return false;
			}
		}
	}
}

void mancala :: make_move(const string &move){
	int bin_num = stoi(move);
	int num_of_stones = board[bin_num];
	extra = false;
	board[bin_num] = 0;
	while(num_of_stones > 0){
			if(bin_num > 1 && bin_num <= 6){
				bin_num--;
				if(num_of_stones == 1 && board[bin_num] == 0 && last_mover() == HUMAN){ //computer drops last stone in empty bin on its side
					board[bin_num] = 0;
					board[0] = board[0] + 1 + board[bin_num + 6];
					board[bin_num + 6] = 0;
					num_of_stones--;
				}else{
					board[bin_num] = board[bin_num] + 1;
					num_of_stones--;
				}
			}else if(bin_num == 1){
				if(last_mover() == HUMAN){
					board[0] = board[0] + 1;
					if(num_of_stones == 1){ //last stone is dropped in mancala
						game::make_move(move); //increment move for extra turn
						extra = true;
					}					
					num_of_stones--;
				}
				bin_num = bin_num + 6;
				if(num_of_stones != 0){
					if(num_of_stones == 1 && board[bin_num] == 0 && last_mover() == COMPUTER){
						board[bin_num] = 0;
						board[13] = board[13] + 1 + board[bin_num - 6];
						board[bin_num - 6] = 0;
						num_of_stones--;
					}else{
						board[bin_num] = board[bin_num] + 1;
						num_of_stones--;
					}
				}
			}else if(bin_num >= 7 && bin_num < 12){
				bin_num++;
				if(num_of_stones == 1 && board[bin_num] == 0 && last_mover() == COMPUTER){
					board[bin_num] = 0;
					board[13] = board[13] + 1 + board[bin_num - 6];
					board[bin_num - 6] = 0;
					num_of_stones--;
				}else{
					board[bin_num] = board[bin_num] + 1;
					num_of_stones--;
				}
			}else if(bin_num == 12){
				if(last_mover() == COMPUTER){
					board[13] = board[13] + 1;
					if(num_of_stones == 1){ //last stone is dropped in mancala
						game::make_move(move); //increment move for extra turn
						extra = true;
					}
					num_of_stones--;
				}
				bin_num = bin_num - 6;
				if(num_of_stones != 0){
					if(num_of_stones == 1 && board[bin_num] == 0 && last_mover() == HUMAN){ //player drops last stone in empty bin on their side
						board[bin_num] = 0;
						board[0] = board[0] + 1 + board[bin_num + 6];
						board[bin_num + 6] = 0;
						num_of_stones--;
					}else{
						board[bin_num] = board[bin_num] + 1;
						num_of_stones--;
					}
				}
			}
	}
	if(board[1] == 0 && board[2] == 0 && board[3] == 0 && board[4] == 0 && board[5] == 0 && board[6] == 0){ //computer side of board is empty
		board[13] = (48- board[0]); //human gets stones left on their side
		for(int i = 7; i < 13; i++)
			board[i] = 0;
		over = true; //game is over
	}else if(board[7] == 0 && board[8] == 0 && board[9] == 0 && board[10] == 0 && board[11] == 0 && board[12] == 0){
		board[0] = 48- board[13];
		for(int i = 1; i < 7; i++)
			board[i] = 0;
		over = true;
	}

	game::make_move(move); //increment move number

}

main_savitch_14::game::who mancala :: winning()const{
	if(board[13] > board[0]){
		return HUMAN;
	}else if(board[13] < board[0]){
		return COMPUTER;
	}else if(board[13] == board[0]){
		return NEUTRAL;
	}
}

bool mancala :: is_game_over()const{
	if(over == true){
		return true;
	}else
		return false;
}

string mancala :: get_user_move( ) const{
	if(extra == true){
		cout << "Extra turn!" << endl;
		string answer;
		display_message("Your move, please: ");
		getline(cin, answer);
		return answer;
	}else{
		string answer;
		display_message("Your move, please: ");
		getline(cin, answer);
		return answer;
    }
}

void mancala :: restart(){ //reset whole board
	board[0] = board[13] = 0;
	for(int i = 1; i < 13; i++){
		board[i] = 4;
	}
	over = false;
	game::restart();
}

main_savitch_14 :: game *mancala :: clone() const{		
	return new mancala(*this); 
}

void mancala :: compute_moves(std::queue<std::string>& moves) const{
	string tmp;
	if(last_mover() == HUMAN){ //add legal moves for computer to queue
		for(int i = 1; i < 7; i++){
			tmp = to_string(i);
			if(is_legal(tmp))
				moves.push(tmp);
		}
	}else if(last_mover() == COMPUTER){ //add legal moves for human to queue
		for(int i = 7; i < 13; i++){
			tmp = to_string(i);
			if(is_legal(tmp))
				moves.push(tmp);
		}
	}
}

int mancala :: evaluate()const{
	int value;
	value = board[0]; //computer mancala - human mancala
	//for(int i = 7; i <= 13; i++)
		//value -= board[i];
	for(int i = 1; i <=6; i++)
		value += board[i];
	return value;
}




//Program:      checkers.cc (Project 6)

//Author:       Aidan Crowl
//Email:        ac833914@ohio.edu

//Lab section:  2626, Pin Zhang

//Description:  This program is the implementation for the child class Checkers.

//Date: April 23, 2017

#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cstring>
#include <string>
#include <cstring>
#include <queue>
#include "checkers.h"
using namespace std;

namespace main_savitch_14
{
	Checkers::Checkers():game()
	{
		restart();
	}

	void Checkers::restart()
	{
		for(int i = 0; i < 8; i++)
		{
			for(int j = 0; j < 8; j++)
			{
				if(j % 2 == 0 && i % 2 == 0 && i != 4)
				{
					if(i < 3)
					{
						board[i][j].place_red();
					}
					else if(i > 4)
					{
						board[i][j].place_white();
					}
					else
					{
						board[i][j].make_empty();
					}
				}
				else if(i % 2 != 0 && j % 2 != 0 && i != 3)
				{
					if(i < 3)
					{
						board[i][j].place_red();
					}
					else if(i > 4)
					{
                                                board[i][j].place_white();
					}
					else
					{
						board[i][j].make_empty();
					}
				}
				else
				{
					board[i][j].make_empty();
				}
			}
		}

		game::restart();
	}

	void Checkers::display_status()const
	{
		cout << "  " << setw(5) << "A" << setw(9) << "B" << setw(9) << "C" << setw(9) << "D";
		cout << setw(9) << "E" << setw(9) << "F" << setw(9) << "G" << setw(9) << "H" << endl;

		cout << " " << setfill('-') << setw(73) << "" << endl;
		cout << setfill(' ');

		for(int i = 0; i < 8; i++)
		{
			for(int k = 0; k < 5; k++)
			{
				for(int j = 0; j < 8; j++)
                		{
                        		if(i % 2 == 0 && j % 2 == 0 && k == 2 && board[i][j].is_occupied() && board[i][j].is_red())
                        		{
						if(board[i][j].is_king())
						{
							if(j == 0)
                                                	{
                                                        	cout << i + 1 << "|" << B_BLUE << RED << setw(5) << "@";
								cout << setw(4) << "" << B_BLACK << WHITE;
                                                	}
                                                	else
                                                	{
                                                	        cout << B_BLUE << RED << setw(5) << "@" << setw(4) << "" << B_BLACK << WHITE;
                                                	}
						}
						else
						{
							if(j == 0)
							{
								cout << i + 1 << "|" << B_BLUE << RED << setw(5) << "+";
								cout << setw(4) << "" << B_BLACK << WHITE;
							}
							else
							{
								cout << B_BLUE << RED << setw(5) << "+" << setw(4) << "" << B_BLACK << WHITE;
							}
                        			}
					}
					else if(i % 2 == 0 && j % 2 == 0 && k == 2 && board[i][j].is_occupied() && board[i][j].is_white())
                                        {
						if(board[i][j].is_king())
						{
							if(j == 0)
                                                	{
                                                        	cout << i + 1 << "|" << B_BLUE << setw(5) << "@" << setw(4) << "" << B_BLACK;
                                                	}
                                                	else
                                                	{
                                                        	cout << B_BLUE << setw(5) << "@" << setw(4) << "" << B_BLACK;
                                                	}
						}
						else
						{
                                                	if(j == 0)
                                                	{
                                                        	cout << i + 1 << "|" << B_BLUE << setw(5) << "+" << setw(4) << "" << B_BLACK;
                                                	}
                                                	else
                                                	{
                                                        	cout << B_BLUE << setw(5) << "+" << setw(4) << "" << B_BLACK;
                                                	}
                                        	}
					}
					else if(i % 2 == 0 && j % 2 != 0)
					{
						cout << B_BLACK << setw(9) << "";
					}
                        		else if(i % 2 != 0 && j % 2 != 0 && k == 2 && board[i][j].is_occupied())
                        		{
						if(board[i][j].is_red())
						{
							if(board[i][j].is_king())
							{
								cout << B_BLUE << RED << setw(5) << "@" << setw(4) << "" << B_BLACK << WHITE;
							}
							else
							{
								cout << B_BLUE << RED << setw(5) << "+" << setw(4) << "" << B_BLACK << WHITE;
							}
						}
						else
						{
							if(board[i][j].is_king())
							{
								cout << B_BLUE << setw(5) << "@" << setw(4) << "" << B_BLACK;
							}
							else
							{
								cout << B_BLUE << setw(5) << "+" << setw(4) << "" << B_BLACK;
							}
						}
					}
					else if(i % 2 != 0 && j % 2 == 0)
					{
						if(j == 0 && k == 2)
						{
							cout << i + 1<< "|" << B_BLACK << setw(9) << "";
						}
						else if(j == 0 && k != 2)
						{
							cout << " |" << B_BLACK << setw(9) << "";
						}
						else
						{
							cout << B_BLACK << setw(9) << "";
						}
					}
					else if(i % 2 == 0)
					{
						if(j == 0 && k == 2)
						{
							cout << i + 1 << "|" << B_BLUE << setw(9) << "" << B_BLACK;
						}
						else if(j == 0 && k != 2)
						{
							cout << " |" << B_BLUE << setw(9) << "" << B_BLACK;
						}
						else
						{
							cout << B_BLUE << setw(9) << "" << B_BLACK;
						}
					}
					else
					{
						if(j == 0)
						{
							cout << " |" << B_BLUE << setw(9) << "" << B_BLACK;
						}
						else
						{
							cout << B_BLUE << setw(9) << "" << B_BLACK;
						}
					}
				}

				cout << endl;
			}
		}

		cout << " " << setfill('-') << setw(73) << "" << endl;
		cout << setfill(' ');

		cout << endl;
	}

	bool Checkers::is_legal(const string& move)const
	{
		int initial_i, initial_j, final_i, final_j;
                bool red = false, white = false;

                initial_j = int(tolower(move[0]) - 'a');
                initial_i = int(move[1] - '1');

		final_j = int(tolower(move[2]) - 'a');
                final_i = int(move[3] - '1');

		if(initial_i < 0 || initial_i > 7 || initial_j < 0 || initial_j > 7)
		{
			return false;
		}
		if(final_i < 0 || final_i > 7 || final_j < 0 || final_j > 7)
		{
			return false;
		}

		if(next_mover() == HUMAN)
		{
			if(is_jump_available() && next_jump(move))
			{
				cout << "A multi-jump move is available. Enter the complete route." << endl;
				return false;
			}
			else if(is_jump_available() && !is_move_jump(move) && !next_jump(move) && route_exists(move))
			{
				return true;
			}
			else if(is_jump_available() && is_move_jump(move) && !next_jump(move))
			{
				return true;
			}
			else if(is_jump_available())
			{
				cout << "A jump is available." << endl;
				return false;
			}
			else if(board[initial_i][initial_j].is_red())
			{
				cout << "Not your turn." << endl;
			}
			else
			{
				if(board[initial_i][initial_j].is_king())
				{
					if(final_j == initial_j - 1 && final_i == initial_i - 1)
                                	{
                                        	if(board[initial_i][initial_j].is_white() && board[final_i][final_j].is_empty())
                                        	{
                                                	return true;
                                        	}
                                	}
                                	else if(final_j == initial_j + 1 && final_i == initial_i - 1)
                                	{
                                        	if(board[initial_i][initial_j].is_white() && board[final_i][final_j].is_empty())
                                        	{
                                                	return true;
                                        	}
                                	}
					else if(final_j == initial_j - 1 && final_i == initial_i + 1)
					{
						if(board[initial_i][initial_j].is_white() && board[final_i][final_j].is_empty())
						{
							return true;
						}
					}
					else if(final_j == initial_j + 1 && final_i == initial_i + 1)
                                        {
                                                if(board[initial_i][initial_j].is_white() && board[final_i][final_j].is_empty())
                                                {
                                                	return true;
                                                }
                                        }
					else
					{
						return false;
					}
				}
				else
				{
					if(final_j == initial_j - 1 && final_i == initial_i - 1)
					{
						if(board[initial_i][initial_j].is_white() && board[final_i][final_j].is_empty())
						{
							return true;
						}
					}
					else if(final_j == initial_j + 1 && final_i == initial_i - 1)
					{
						if(board[initial_i][initial_j].is_white() && board[final_i][final_j].is_empty())
                                		{
                                        	        return true;
                                		}
					}
					else
					{
						return false;
					}
				}
			}
		}
		else if(next_mover() == COMPUTER)
		{
			if(is_jump_available() && next_jump(move))
                        {
//                                cout << "A multi-jump move is available. Enter the complete route." << endl;
                                return false;
                        }
                        else if(is_jump_available() && !is_move_jump(move) && !next_jump(move) && route_exists(move))
                        {
                                return true;
                        }
                        else if(is_jump_available() && is_move_jump(move) && !next_jump(move))
                        {
                                return true;
                        }
			else if(is_jump_available())
			{
//				cout << "A jump is available." << endl;
				return false;
			}
			else if(board[initial_i][initial_j].is_white())
			{
//				cout << "Not your turn." << endl;
			}
			else
			{
				if(board[initial_i][initial_j].is_king())
				{
					if(final_j == initial_j - 1 && final_i == initial_i + 1)
                                	{
                                        	if(board[initial_i][initial_j].is_red() && board[final_i][final_j].is_empty())
                                        	{
                                                	return true;
                                        	}
                                	}
                                	else if(final_j == initial_j + 1 && final_i == initial_i + 1)
                                	{
                                        	if(board[initial_i][initial_j].is_red() && board[final_i][final_j].is_empty())
                                        	{
                                                        return true;
                                        	}
                                	}
					else if(final_j == initial_j - 1 && final_i == initial_i - 1)
					{
						if(board[initial_i][initial_j].is_red() && board[final_i][final_j].is_empty())
						{
							return true;
						}
					}
					else if(final_j == initial_j + 1 && final_i == initial_i - 1)
                                        {
                                                if(board[initial_i][initial_j].is_red() && board[final_i][final_j].is_empty())
                                                {
                                                	return true;
                                                }
                                        }
                                	else
                                	{
                                        	return false;
					}
				}
				else
				{
					if(final_j == initial_j - 1 && final_i == initial_i + 1)
                        		{
						if(board[initial_i][initial_j].is_red() && board[final_i][final_j].is_empty())
                                		{
                                                	return true;
                                		}
                        		}
                        		else if(final_j == initial_j + 1 && final_i == initial_i + 1)
                        		{
						if(board[initial_i][initial_j].is_red() && board[final_i][final_j].is_empty())
                                		{
                                                	return true;
                                		}
                        		}
                        		else
                        		{
                                		return false;
                        		}
				}
			}
		}
	}

	void Checkers::make_move(const string& move)
	{
		int initial_i, initial_j, final_i, final_j;
		bool red = false, white = false, king = false;

		if(next_mover() == HUMAN)
		{
			if(is_jump_available() && route_exists(move))
			{
				for(int i = 0; i <= move.length() - 4; i += 2)
                		{
                        		string new_move = move.substr(i,4);
                        		make_jump(new_move);
					display_status();
                		}
			}
			else if(is_jump_available() && is_move_jump(move))
			{
				make_jump(move);
				display_status();

/*
				while(next_jump(move))
				{
					cout << "Another jump is available." << endl;
					cout << "Still your turn." << endl;
					string new_move;

        				new_move = get_user_move( );
        				while (!is_legal(new_move))
        				{
            					display_message("Illegal move.\n");
            					new_move = get_user_move( );
        				}
        				make_move(new_move);
					game::make_move(new_move);
				}
*/

			}


			else
			{
				initial_j = int(tolower(move[0]) - 'a');
				initial_i = int(move[1] - '1');

				if(board[initial_i][initial_j].is_red())
				{
					red = true;
					white = false;
				}
				else
				{
					red = false;
					white = true;
				}

				if(board[initial_i][initial_j].is_king())
				{
					king = true;
				}
				else
				{
					king = false;
				}

				final_j = int(tolower(move[2]) - 'a');
				final_i = int(move[3] - '1');

				board[initial_i][initial_j].make_empty();

				if(red)
				{
					board[final_i][final_j].place_red();
					if(final_i == 7)
					{
						board[final_i][final_j].make_king();
					}
				}
				else
				{
					board[final_i][final_j].place_white();
					if(final_i == 0)
					{
						board[final_i][final_j].make_king();
					}
				}

				if(king)
				{
					board[final_i][final_j].make_king();
				}
			}
		}
		else if(next_mover() == COMPUTER)
		{
			if(is_jump_available() && route_exists(move))
                        {
                                for(int i = 0; i <= move.length() - 4; i += 2)
                                {
                                        string new_move = move.substr(i,4);
                                        make_jump(new_move);
                                        display_status();
                                }
                        }
			else if(is_jump_available() && is_move_jump(move))
                        {
                                make_jump(move);
                                display_status();
/*
                                while(next_jump(move))
                                {
//                                        cout << "Another jump is available." << endl;
  //                                      cout << "Still your turn." << endl;
                                        string new_move;

                                        new_move = get_user_move( );
                                        while (!is_legal(new_move))
                                        {
//                                                display_message("Illegal move.\n");
                                                new_move = get_user_move( );
                                        }
                                        make_move(new_move);
                                        game::make_move(new_move);
                                }
*/

                        }


			else
                        {
                                initial_j = int(tolower(move[0]) - 'a');
                                initial_i = int(move[1] - '1');

                                if(board[initial_i][initial_j].is_red())
                                {
                                        red = true;
                                        white = false;
                                }
                                else
                                {
                                        red = false;
                                        white = true;
                                }

                                if(board[initial_i][initial_j].is_king())
                                {
                                        king = true;
                                }
                                else
                                {
                                        king = false;
                                }

                                final_j = int(tolower(move[2]) - 'a');
                                final_i = int(move[3] - '1');

                                board[initial_i][initial_j].make_empty();

				if(red)
                                {
                                        board[final_i][final_j].place_red();
                                        if(final_i == 7)
                                        {
                                                board[final_i][final_j].make_king();
                                        }
                                }
                                else
                                {
                                        board[final_i][final_j].place_white();
                                        if(final_i == 0)
                                        {
                                                board[final_i][final_j].make_king();
                                        }
                                }

                                if(king)
                                {
                                        board[final_i][final_j].make_king();
                                }
                        }
                }

		game::make_move(move);
	}

	bool Checkers::is_jump_available()const
	{
		int white_count = 0, red_count = 0;

		for(int i = 0; i < 8; i++)
		{
			for(int j = 0; j < 8; j++)
			{
				if(next_mover() == HUMAN)
                		{
					if(board[i][j].is_king())
					{
						if(i == 0 || i == 1)
						{
							if(j == 0 || j == 1)
							{
								if(board[i][j].is_white())
                                                        	{
                                                                	if(board[i + 1][j + 1].is_red() && board[i + 2][j + 2].is_empty())
                                                                	{
                                                                        	white_count++;
                                                                	}
                                                        	}
							}
							else if(j == 6 || j == 7)
							{
								if(board[i][j].is_white())
                                                        	{
                                                                	if(board[i + 1][j - 1].is_red() && board[i + 2][j - 2].is_empty())
                                                                	{
                                                                     		white_count++;
                                                                	}
                                                        	}
							}
							else
							{
								if(board[i][j].is_white())
                                                                {
                                                                        if(board[i + 1][j + 1].is_red() && board[i + 2][j + 2].is_empty())
                                                                        {
                                                                        	white_count++;
	                                                                }
									else if(board[i + 1][j - 1].is_red() && board[i + 2][j - 2].is_empty())
                                                                        {
                                                                        	white_count++;
                                                                        }

                                                                }
							}
						}
						else if(i == 6 || i == 7)
						{
							if(j == 0 || j == 1)
                                                        {
                                                                if(board[i][j].is_white())
                                                                {
                                                                        if(board[i - 1][j + 1].is_red() && board[i - 2][j + 2].is_empty())
                                                                        {
                                                                        	white_count++;
                                                                        }
                                                                }
                                                        }
                                                        else if(j == 6 || j == 7)
                                                        {
                                                                if(board[i][j].is_white())
                                                                {
                                                                        if(board[i - 1][j - 1].is_red() && board[i - 2][j - 2].is_empty())
                                                                        {
                                                                        	white_count++;
                                                                        }
                                                                }
                                                        }
							else
                                                        {
                                                                if(board[i][j].is_white())
                                                                {
                                                                        if(board[i - 1][j + 1].is_red() && board[i - 2][j + 2].is_empty())
                                                                        {
                                                                        	white_count++;
                                                                        }
                                                                        else if(board[i - 1][j - 1].is_red() && board[i - 2][j - 2].is_empty())
                                                                        {
                                                                        	white_count++;
                                                                        }

                                                                }
                                                        }
						}
						else
						{
							if(j == 0 || j == 1)
                                                        {
                                                                if(board[i][j].is_white())
                                                                {
                                                                        if(board[i - 1][j + 1].is_red() && board[i - 2][j + 2].is_empty())
                                                                        {
                                                                        	white_count++;
                                                                        }
                                                                        else if(board[i + 1][j + 1].is_red() && board[i + 2][j + 2].is_empty())
                                                                        {
                                                                        	white_count++;
                                                                        }
                                                                }

                                                        }
                                                        else if(j == 6 || j == 7)
                                                        {
                                                                if(board[i][j].is_white())
                                                                {
                                                                        if(board[i - 1][j - 1].is_red() && board[i - 2][j - 2].is_empty())
                                                                        {
                                                                        	white_count++;
                                                                        }
                                                                        else if(board[i + 1][j - 1].is_red() && board[i + 2][j - 2].is_empty())
                                                                        {
                                                                        	white_count++;
                                                                        }
                                                                }
                                                        }
							else
							{
								if(board[i][j].is_white())
                                                                {
                                                                        if(board[i - 1][j - 1].is_red() && board[i - 2][j - 2].is_empty())
                                                                        {
                                                                        	white_count++;
                                                                        }
                                                                        else if(board[i + 1][j - 1].is_red() && board[i + 2][j - 2].is_empty())
                                                                        {
                                                                        	white_count++;
                                                                        }
                                                                        else if(board[i - 1][j + 1].is_red() && board[i - 2][j + 2].is_empty())
                                                                        {
                                                                        	white_count++;
                                                                        }
                                                                        else if(board[i + 1][j + 1].is_red() && board[i + 2][j + 2].is_empty())
                                                                        {
                                                                        	white_count++;
                                                                        }
                                                                }
							}
						}
					}
					else
					{
						if(i == 0 || i == 1);
						else if(j == 0 || j == 1)
						{
							if(board[i][j].is_white())
                                        		{
                                                		if(board[i - 1][j + 1].is_red() && board[i - 2][j + 2].is_empty())
                                                		{
                                                               		white_count++;
                                                		}
							}
						}
						else if(j == 7 || j == 6)
						{
							if(board[i][j].is_white())
                                        		{
                                                		if(board[i - 1][j - 1].is_red() && board[i - 2][j - 2].is_empty())
                                                		{
                                                                	white_count++;
                                                		}
							}
						}
						else
						{
                        				if(board[i][j].is_white())
                        				{
                                				if(board[i - 1][j + 1].is_red() && board[i - 2][j + 2].is_empty())
                                				{
                                                			white_count++;
                                				}
                                				else if(board[i - 1][j - 1].is_red() && board[i - 2][j - 2].is_empty())
                                				{
                                                			white_count++;
                                				}
                					}
						}
					}
				}
				else if(next_mover() == COMPUTER)
                		{
					if(board[i][j].is_king())
					{
						if(i == 0 || i == 1)
                                                {
                                                        if(j == 0 || j == 1)
                                                        {
                                                                if(board[i][j].is_red())
                                                                {
                                                                        if(board[i + 1][j + 1].is_white() && board[i + 2][j + 2].is_empty())
                                                                        {
                                                                        	red_count++;
                                                                        }
                                                                }
                                                        }
                                                        else if(j == 6 || j == 7)
                                                        {
                                                                if(board[i][j].is_red())
                                                                {
                                                                        if(board[i + 1][j - 1].is_white() && board[i + 2][j - 2].is_empty())
                                                                        {
                                                                        	red_count++;
                                                                        }
                                                                }
                                                        }
							else
                                                        {
                                                                if(board[i][j].is_red())
                                                                {
                                                                        if(board[i + 1][j + 1].is_white() && board[i + 2][j + 2].is_empty())
                                                                        {
                                                                        	red_count++;
                                                                        }
                                                                        else if(board[i + 1][j - 1].is_white() && board[i + 2][j - 2].is_empty())
                                                                        {
                                                                        	red_count++;
                                                                        }

                                                                }
                                                        }
                                                }
						else if(i == 6 || i == 7)
                                                {
                                                        if(j == 0 || j == 1)
                                                        {
                                                                if(board[i][j].is_red())
                                                                {
                                                                        if(board[i - 1][j + 1].is_white() && board[i - 2][j + 2].is_empty())
                                                                        {
                                                                        	red_count++;
                                                                        }
                                                                }
                                                        }
							else if(j == 6 || j == 7)
                                                        {
                                                                if(board[i][j].is_red())
                                                                {
                                                                        if(board[i - 1][j - 1].is_white() && board[i - 2][j - 2].is_empty())
                                                                        {
                                                                        	red_count++;
                                                                        }
                                                                }
                                                        }
							else
                                                        {
                                                                if(board[i][j].is_red())
                                                                {
                                                                        if(board[i - 1][j + 1].is_white() && board[i - 2][j + 2].is_empty())
                                                                        {
                                                                        	red_count++;
                                                                        }
                                                                        else if(board[i - 1][j - 1].is_white() && board[i - 2][j - 2].is_empty())
                                                                        {
                                                                        	red_count++;
                                                                        }

                                                                }
                                                        }
                                                }
						else
						{
							if(board[i][j].is_red())
							{
								if(board[i - 1][j - 1].is_white() && board[i - 2][j - 2].is_empty())
                                                                {
                                	                        	red_count++;
                     	                                        }
      	                                                        else if(board[i + 1][j - 1].is_white() && board[i + 2][j - 2].is_empty())
              	                                          	{
                                      		                	red_count++;
                                                                }
                                                                else if(board[i - 1][j + 1].is_white() && board[i - 2][j + 2].is_empty())
                                                                {
                	                                        	red_count++;
       	                                                        }
                                                                else if(board[i + 1][j + 1].is_white() && board[i + 2][j + 2].is_empty())
                                                       		{
                                	                        	red_count++;
                                                                }
                                                        }
                                                }
                                       	}
					else
					{
						if(i == 7 || i == 6);
                        			else if(j == 0 || j == 1)
						{
							if(board[i][j].is_red())
                                        		{
                                                		if(board[i + 1][j + 1].is_white() && board[i + 2][j + 2].is_empty())
                                                		{
                                                                	red_count++;
                                                		}
							}
						}
						else if(j == 7 || j == 6)
						{
							if(board[i][j].is_red())
                                        		{
                                                		if(board[i + 1][j - 1].is_white() && board[i + 2][j - 2].is_empty())
                                                		{
                                                                	red_count++;
                                                		}
							}
						}
						else
						{
							if(board[i][j].is_red())
                        				{
                                				if(board[i + 1][j + 1].is_white() && board[i + 2][j + 2].is_empty())
                                				{
                                                			red_count++;
                                				}
                                				else if(board[i + 1][j - 1].is_white() && board[i + 2][j - 2].is_empty())
                                				{
                                                			red_count++;
                                				}
                        				}
  	          				}
					}
				}
			}
		}

		if(next_mover() == HUMAN)
		{
			if(white_count != 0)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else if(next_mover() == COMPUTER)
		{
			if(red_count != 0)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}

	bool Checkers::is_move_jump(const string& move)const
	{
		int initial_i, initial_j, final_i, final_j;
                bool red = false, white = false;

                initial_j = int(tolower(move[0]) - 'a');
                initial_i = int(move[1] - '1');

                final_j = int(tolower(move[move.length() - 2]) - 'a');
                final_i = int(move[move.length() - 1] - '1');

		if(!is_jump_available())
		{
			return false;
		}
		else
		{
			if(next_mover() == HUMAN)
                	{
				if(board[initial_i][initial_j].is_king())
				{
                       			if(board[initial_i][initial_j].is_white())
	                      		{
	        				if(final_i == (initial_i - 2) && final_j == (initial_j + 2))
                                        	{
		                        		if(board[initial_i - 1][initial_j + 1].is_red() && board[initial_i - 2][initial_j + 2].is_empty())
        	                        		{
                                                		return true;
							}
							else
							{
								return false;
							}
                                		}
        		               		else if(final_i == (initial_i - 2) && final_j == (initial_j - 2))
                                        	{
							if(board[initial_i - 1][initial_j - 1].is_red() && board[initial_i - 2][initial_j - 2].is_empty())
	                	                	{
                                                		return true;
							}
							else
							{
								return false;
							}
						}
						else if(final_i == (initial_i + 2) && final_j == (initial_j + 2))
                                                {
                                                        if(board[initial_i + 1][initial_j + 1].is_red() && board[initial_i + 2][initial_j + 2].is_empty())
                                                        {
                                                                return true;
                                                        }
                                                        else
                                                        {
                                                                return false;
                                                        }
                                                }
						else if(final_i == (initial_i + 2) && final_j == (initial_j - 2))
                                                {
                                                        if(board[initial_i + 1][initial_j - 1].is_red() && board[initial_i + 2][initial_j - 2].is_empty())
                                                        {
                                                                return true;
                                                        }
                                                        else
                                                        {
                                                                return false;
                                                        }
                                                }
						else
						{
							return false;
						}
					}
                                	else
                                	{
                                        	return false;
                                	}
                        	}
				else
				{
					if(board[initial_i][initial_j].is_white())
                                        {
                                                if(final_i == (initial_i - 2) && final_j == (initial_j + 2))
                                                {
                                                        if(board[initial_i - 1][initial_j + 1].is_red() && board[initial_i - 2][initial_j + 2].is_empty())
                                                        {
                                                                return true;
                                                        }
                                                        else
                                                        {
                                                                return false;
                                                        }
                                                }
                                                else if(final_i == (initial_i - 2) && final_j == (initial_j - 2))
                                                {
                                                        if(board[initial_i - 1][initial_j - 1].is_red() && board[initial_i - 2][initial_j - 2].is_empty())
                                                        {
                                                                return true;
                                                        }
                                                        else
                                                        {
                                                                return false;
                                                        }
                                                }
						else
						{
							return false;
						}
					}
					else
					{
						return false;
					}
				}
                	}
			else if(next_mover() == COMPUTER)
			{
				if(board[initial_i][initial_j].is_king())
				{
					if(board[initial_i][initial_j].is_red())
                        		{
						if(final_i == (initial_i + 2) && final_j == (initial_j + 2))
                                        	{
	                              			if(board[initial_i + 1][initial_j + 1].is_white() && board[initial_i + 2][initial_j + 2].is_empty())
                                			{
                                                		return true;
                                        		}
							else
							{
								return false;
							}
                                		}
	        				else if(final_i == (initial_i + 2) && final_j == (initial_j - 2))
                                        	{
		                        		if(board[initial_i + 1][initial_j - 1].is_white() && board[initial_i + 2][initial_j - 2].is_empty())
        	                        		{
                                                		return true;
                                        		}
							else
							{
								return false;
							}
                                		}
						else if(final_i == (initial_i - 2) && final_j == (initial_j + 2))
                                                {
                                                        if(board[initial_i - 1][initial_j + 1].is_white() && board[initial_i - 2][initial_j + 2].is_empty())
                                                        {
                                                                return true;
                                                        }
                                                        else
                                                        {
                                                                return false;
                                                        }
                                                }
                                                else if(final_i == (initial_i - 2) && final_j == (initial_j - 2))
                                                {
                                                        if(board[initial_i - 1][initial_j - 1].is_white() && board[initial_i - 2][initial_j - 2].is_empty())
                                                        {
                                                                return true;
                                                        }
                                                        else
                                                        {
                                                                return false;
                                                        }
                                                }
						else
						{
							return false;
						}
                                	}
					else
                                	{
                                        	return false;
                                	}
                        	}
				else
				{
					if(board[initial_i][initial_j].is_red())
                                        {
                                                if(final_i == (initial_i + 2) && final_j == (initial_j + 2))
                                                {
                                                        if(board[initial_i + 1][initial_j + 1].is_white() && board[initial_i + 2][initial_j + 2].is_empty())
                                                        {
                                                                return true;
                                                        }
                                                        else
                                                        {
                                                                return false;
                                                        }
                                                }
                                                else if(final_i == (initial_i + 2) && final_j == (initial_j - 2))
                                                {
                                                        if(board[initial_i + 1][initial_j - 1].is_white() && board[initial_i + 2][initial_j - 2].is_empty())
                                                        {
                                                                return true;
                                                        }
                                                        else
                                                        {
                                                                return false;
                                                        }
                                                }
						else
						{
							return false;
						}
					}
					else
					{
						return false;
					}
				}
                	}
		}
	}

	bool Checkers::next_jump(const string& move)const
	{
		int initial_i, initial_j, final_i, final_j;

                initial_j = int(tolower(move[0]) - 'a');
                initial_i = int(move[1] - '1');

                final_j = int(tolower(move[move.length() - 2]) - 'a');
                final_i = int(move[move.length() - 1] - '1');

                if(!is_jump_available())
                {
                        return false;
                }
		else if(!is_move_jump(move))
		{
			return false;
		}
		else
                {
                        if(next_mover() == HUMAN)
                        {
				if(board[initial_i][initial_j].is_king())// && board[final_i][final_j].is_white())
				{
					if(final_i == 0 || final_i == 1)
					{
                                        	if(final_j == 0 || final_j == 1)
						{
							if(board[final_i + 1][final_j + 1].is_red() && board[final_i + 2][final_j + 2].is_empty())
                                                        {
                                                               	return true;
                                                        }
                                                        else
                                                        {
                                                             	return false;
                                                        }
                                                }
						else if(final_j == 6 || final_j == 7)
						{
							if(board[final_i + 1][final_j - 1].is_red() && board[final_i + 2][final_j - 2].is_empty())
                                                       	{
                                                               	return true;
                                                       	}
                                                       	else
                                                       	{
                                                               	return false;
                                                     	}
						}
						else
						{
							if(board[final_i + 1][final_j + 1].is_red() && board[final_i + 2][final_j + 2].is_empty())
                                                       	{
                                                               	return true;
                                                       	}
							else if(board[final_i + 1][final_j - 1].is_red() && board[final_i + 2][final_j - 2].is_empty())
                                                       	{
                                                               	return true;
                                                       	}
                                                       	else
                                                       	{
                                                               	return false;
                                                       	}
						}
					}
					else if(final_i == 6 || final_i == 7)
					{
						if(final_j == 0 || final_j == 1)
                                               	{
                                                       	if(board[final_i - 1][final_j + 1].is_red() && board[final_i - 2][final_j + 2].is_empty())
                                                       	{
                                                               	return true;
                                                       	}
                                                       	else
                                                       	{
                                                               	return false;
                                                       	}
                                               	}
                                               	else if(final_j == 6 || final_j == 7)
                                               	{
                                                       	if(board[final_i - 1][final_j - 1].is_red() && board[final_i - 2][final_j - 2].is_empty())
                                                       	{
                                                               	return true;
                                                        }
                                                       	else
                                                       	{
                                                               	return false;
                                                       	}
                                               	}
						else
						{
							if(board[final_i - 1][final_j + 1].is_red() && board[final_i - 2][final_j + 2].is_empty())
                                                       	{
                                                               	return true;
                                                       	}
                                                        else if(board[final_i - 1][final_j - 1].is_red() && board[final_i - 2][final_j - 2].is_empty())
                                                       	{
                                                               	return true;
                                                       	}
                                                       	else
                                                       	{
                                                               	return false;
                                                       	}
                                               	}
					}
					else
					{
						if(final_j == 0 || final_j == 1)
                                               	{
                                                       	if(board[final_i - 1][final_j + 1].is_red() && board[final_i - 2][final_j + 2].is_empty())
                                                       	{
                                                               	return true;
                                                       	}
							else if(board[final_i + 1][final_j + 1].is_red() && board[final_i + 2][final_j + 2].is_empty())
                                                       	{
                                                               	return true;
                                                       	}
							else
							{
								return false;
							}
						}
						else if(final_j == 6 || final_j == 7)
                                               	{
                                                       	if(board[final_i - 1][final_j - 1].is_red() && board[final_i - 2][final_j - 2].is_empty())
                                                       	{
                                                               	return true;
                                                       	}
							else if(board[final_i + 1][final_j - 1].is_red() && board[final_i + 2][final_j - 2].is_empty())
                                                       	{
                                                               	return true;
                                                       	}
							else
							{
								return false;
							}
						}
						else
						{
							if(board[final_i - 1][final_j - 1].is_red() && board[final_i - 2][final_j - 2].is_empty())
                                                       	{
                                                       	        return true;
                                                       	}
                                                        else if(board[final_i + 1][final_j - 1].is_red() && board[final_i + 2][final_j - 2].is_empty())
                                                	{
                                                                return true;
                                                        }
							else if(board[final_i - 1][final_j + 1].is_red() && board[final_i - 2][final_j + 2].is_empty())
                                                        {
                                                                return true;
                                                        }
                                                        else if(board[final_i + 1][final_j + 1].is_red() && board[final_i + 2][final_j + 2].is_empty())
                                                        {
                                                                return true;
                                                        }
							else
							{
								return false;
							}
						}
					}
				}
				else if(!board[final_i][final_j].is_king())// && board[final_i][final_j].is_white())
				{
					if(final_i == 0 || final_i == 1)
                                	{
                	                	return false;
                                	}
                                	else if(final_j == 0 || final_j == 1)
                                	{
                                        	if(board[final_i - 1][final_j + 1].is_red() && board[final_i - 2][final_j + 2].is_empty())
                                            	{
        	                                	return true;
                                               	}
                                       	}
                                	else if(final_j == 7 || final_j == 6)
                                	{
	                                        if(board[final_i - 1][final_j - 1].is_red() && board[final_i - 2][final_j - 2].is_empty())
                                                {
                                                	return true;
                                                }
                                        }
					else
                                	{
                        	                if(board[final_i - 1][final_j + 1].is_red() && board[final_i - 2][final_j + 2].is_empty())
                                                {
       		                                	return true;
						}
                                                else if(board[final_i - 1][final_j - 1].is_red() && board[final_i - 2][final_j - 2].is_empty())
                                                {
                                                	return true;
                                                }
                                        }
                                }
				else
				{
					return false;
				}
			}
                        else if(next_mover() == COMPUTER)
                        {
				if(board[final_i][final_j].is_king())// && board[final_i][final_j].is_red())
                                {
                                        if(final_i == 0 || final_i == 1)
                                        {
                                                if(final_j == 0 || final_j == 1)
                                                {
                                                        if(board[final_i + 1][final_j + 1].is_white() && board[final_i + 2][final_j + 2].is_empty())
                                                        {
                                                                return true;
                                                        }
                                                        else
                                                        {
                                                                return false;
                                                        }
                                                }
                                                else if(final_j == 6 || final_j == 7)
                                                {
                                                        if(board[final_i + 1][final_j - 1].is_white() && board[final_i + 2][final_j - 2].is_empty())
                                                        {
                                                                return true;
                                                        }
                                                        else
                                                        {
                                                                return false;
                                                        }
                                                }
						else
                                                {
                                                        if(board[final_i + 1][final_j + 1].is_white() && board[final_i + 2][final_j + 2].is_empty())
                                                        {
                                                                return true;
                                                        }
                                                        else if(board[final_i + 1][final_j - 1].is_white() && board[final_i + 2][final_j - 2].is_empty())
                                                        {
                                                                return true;
                                                        }
                                                        else
                                                        {
                                                                return false;
                                                        }
                                                }
                                        }
					else if(final_i == 6 || final_i == 7)
                                        {
                                                if(final_j == 0 || final_j == 1)
                                                {
                                                        if(board[final_i - 1][final_j + 1].is_white() && board[final_i - 2][final_j + 2].is_empty())
                                                        {
                                                                return true;
                                                        }
                                                        else
                                                        {
                                                                return false;
                                                        }
                                                }
                                                else if(final_j == 6 || final_j == 7)
                                                {
                                                        if(board[final_i - 1][final_j - 1].is_white() && board[final_i - 2][final_j - 2].is_empty())
                                                        {
                                                                return true;
                                                        }
                                                        else
                                                        {
                                                                return false;
                                                        }
                                                }
						else
                                                {
                                                        if(board[final_i - 1][final_j + 1].is_white() && board[final_i - 2][final_j + 2].is_empty())
                                                        {
                                                                return true;
                                                        }
                                                        else if(board[final_i - 1][final_j - 1].is_white() && board[final_i - 2][final_j - 2].is_empty())
                                                        {
                                                                return true;
                                                        }
                                                        else
                                                        {
                                                                return false;
                                                        }
                                                }
                                        }
					else
                                        {
                                                if(final_j == 0 || final_j == 1)
                                                {
                                                        if(board[final_i - 1][final_j + 1].is_white() && board[final_i - 2][final_j + 2].is_empty())
                                                        {
                                                                return true;
                                                        }
                                                        else if(board[final_i + 1][final_j + 1].is_white() && board[final_i + 2][final_j + 2].is_empty())
                                                        {
                                                                return true;
                                                        }
                                                        else
                                                        {
                                                                return false;
                                                        }
                                                }
                                                else if(final_j == 6 || final_j == 7)
                                                {
                                                        if(board[final_i - 1][final_j - 1].is_white() && board[final_i - 2][final_j - 2].is_empty())
                                                        {
                                                                return true;
                                                        }
                                                        else if(board[final_i + 1][final_j - 1].is_white() && board[final_i + 2][final_j - 2].is_empty())
                                                        {
                                                                return true;
                                                        }
                                                        else
                                                        {
                                                                return false;
                                                        }
                                                }
						else
                                                {
                                                        if(board[final_i - 1][final_j - 1].is_white() && board[final_i - 2][final_j - 2].is_empty())
                                                        {
                                                                return true;
                                                        }
                                                        else if(board[final_i + 1][final_j - 1].is_white() && board[final_i + 2][final_j - 2].is_empty())
                                                        {
                                                                return true;
                                                        }
                                                        else if(board[final_i - 1][final_j + 1].is_white() && board[final_i - 2][final_j + 2].is_empty())
                                                        {
                                                                return true;
                                                        }
                                                        else if(board[final_i + 1][final_j + 1].is_white() && board[final_i + 2][final_j + 2].is_empty())
                                                        {
                                                                return true;
                                                        }
                                                        else
                                                        {
                                                                return false;
                                                        }
                                                }
					}
				}
				else if(!board[final_i][final_j].is_king())// && board[final_i][final_j].is_red())
				{
                                	if(final_i == 7 || final_i == 6)
                                	{
                                       		return false;
                                	}
                                	else if(final_j == 0 || final_j == 1)
                                	{
                                                if(board[final_i + 1][final_j + 1].is_white() && board[final_i + 2][final_j + 2].is_empty())
                                                {
                                                	return true;
                                                }
                                        }
					else if(final_j == 7 || final_j == 6)
        	                        {
                                                if(board[final_i + 1][final_j - 1].is_white() && board[final_i + 2][final_j - 2].is_empty())
                                                {
                                                	return true;
                                                }
                                        }
					else
        	                        {
                                                if(board[final_i + 1][final_j + 1].is_white() && board[final_i + 2][final_j + 2].is_empty())
                                                {
                                	                return true;
                                                }
                                                else if(board[final_i + 1][final_j - 1].is_white() && board[final_i + 2][final_j - 2].is_empty())
                                                {
                                                	return true;
                                                }
                                        }
                                }
				else
				{
					return false;
				}
                        }
		}
	}

	bool Checkers::route_exists(const string& move)const
	{
		int truth_counter = 0;

		string new_move = move.substr(0,4);

		if(!is_move_jump(new_move))
		{
			return false;
		}
		else
		{
			for(int i = 2; i <= move.length() - 4; i += 2)
			{
				new_move = move.substr(i,4);

				if(!next_jump(new_move))
				{
					truth_counter++;
				}
			}
		}

		if(truth_counter > 1)
		{
			return false;
		}
		else
		{
			return true;
		}
	}

	void Checkers::make_jump(const string& move)
	{
		int initial_i, initial_j, final_i, final_j;
                bool red = false, white = false, king = false;

		initial_j = int(tolower(move[0]) - 'a');
                initial_i = int(move[1] - '1');

                if(board[initial_i][initial_j].is_red())
                {
	                red = true;
                        white = false;
                }
                else
                {
	                red = false;
                        white = true;
                }

		if(board[initial_i][initial_j].is_king())
		{
			king = true;
		}
		else
		{
			king = false;
		}

                final_j = int(tolower(move[2]) - 'a');
                final_i = int(move[3] - '1');

                board[initial_i][initial_j].make_empty();

                if(red)
                {
	                board[final_i][final_j].place_red();
			if(final_i == 7)
			{
				board[final_i][final_j].make_king();
			}
                }
                else
                {
	                board[final_i][final_j].place_white();
			if(final_i == 0)
			{
				board[final_i][final_j].make_king();
			}
                }

		if(king)
		{
			board[final_i][final_j].make_king();

                       	if(final_i == initial_i - 2 && final_j == initial_j + 2)
                       	{
                               	board[initial_i - 1][initial_j + 1].make_empty();
                       	}
                       	else if(final_i == initial_i - 2 && final_j == initial_j - 2)
                       	{
                               	board[initial_i - 1][initial_j - 1].make_empty();
                       	}
			else if(final_i == initial_i + 2 && final_j == initial_j + 2)
			{
				board[initial_i + 1][initial_j + 1].make_empty();
			}
			else if(final_i == initial_i + 2 && final_j == initial_j - 2)
			{
				board[initial_i + 1][initial_j - 1].make_empty();
			}
		}
		else
		{
			if(next_mover() == HUMAN)
			{
				if(final_j == initial_j + 2)
				{
					board[initial_i - 1][initial_j + 1].make_empty();
				}
				else if(final_j == initial_j - 2)
				{
					board[initial_i - 1][initial_j - 1].make_empty();
				}
			}
			else if(next_mover() == COMPUTER)
			{
				if(final_j == initial_j + 2)
                        	{
                                	board[initial_i + 1][initial_j + 1].make_empty();
                        	}
                        	else if(final_j == initial_j - 2)
                        	{
                                	board[initial_i + 1][initial_j - 1].make_empty();
                        	}
			}
		}

//                game::make_move(move);
        }

	bool Checkers::is_game_over()const
	{
		int white_count = 0, red_count = 0;

		for(int i = 0; i < 8; i++)
		{
			for(int j = 0; j < 8; j++)
			{
				if(board[i][j].is_white())
				{
					white_count++;
				}
				else if(board[i][j].is_red())
				{
					red_count++;
				}
			}
		}

		if(white_count == 0)
		{
			cout << "Red wins! Game over." << endl;
			return true;
		}
		else if(red_count == 0)
		{
			cout << "White wins! Game over." << endl;
			return true;
		}
		else
		{
			return false;
		}
	}

	int Checkers::evaluate()const
	{
		int white_count = 0, red_count = 0;

                for(int i = 0; i < 8; i++)
                {
                        for(int j = 0; j < 8; j++)
                        {
                                if(board[i][j].is_white())
                                {
                                        white_count++;
                                }
                                else if(board[i][j].is_red())
                                {
                                        red_count++;
                                }
                        }
                }

                if(white_count > red_count)
                {
                        return -1;
                }
                else if(red_count > white_count)
                {
                        return 1;
                }
		else
                {
                        return 0;
                }
        }

	game* Checkers::clone()const
	{
		return new Checkers(*this);
	}

	void Checkers::compute_moves(queue<string>& moves)const
	{
		for(int i = 0; i < 8; i++)
		{
			for(int j = 0; j < 8; j++)
			{
/*

				char initial_i, initial_j, final_i, final_j;
                                char move[4];
                                string s_move, n_move;

                                initial_j = char(j) + 'a';
                                initial_i = char(i) + '1';

				for(int k = 0; k < 8; k++)
				{
					for(int l = 0; l < 8; l++)
					{
						final_j = char(k) + 'a';
						final_i = char(l) + '1';

						move[0] = final_j;
                                        	move[1] = final_i;
                                                move[2] = initial_j;
                                                move[3] = initial_i;

                                                s_move = move;

                                                n_move = s_move.substr(0,4);

                                                if(is_legal(n_move))
                                                {
  	                                        	moves.push(n_move);
                                                }
					}
				}
			}
		}
	}

*/






				if(next_mover() == HUMAN)
				{
					if(board[i][j].is_white() && board[i][j].is_king())
					{
						if(is_jump_available())
						{
							char initial_i, initial_j;
                                                	char move[4];
                                                	string s_move, n_move;

                                                	initial_j = char(j) + 'a';
                                                	initial_i = char(i) + '1';

                                                	move[0] = initial_j + 2;
                                                	move[1] = initial_i - 2;
                                                	move[2] = initial_j;
                                                	move[3] = initial_i;

                                                	s_move = move;

							n_move = s_move.substr(0,4);

                                                	if(is_legal(n_move))
                                                	{
                                                        	moves.push(n_move);
                                                	}

							move[0] = initial_j - 2;
                                                        move[1] = initial_i - 2;
                                                        move[2] = initial_j;
                                                        move[3] = initial_i;

                                                        s_move = move;

							n_move = s_move.substr(0,4);

                                                        if(is_legal(n_move))
                                                        {
//                                                                cout << "Move: " << s_move << endl;
                                                                moves.push(n_move);
                                                        }

							move[0] = initial_j + 2;
                                                        move[1] = initial_i + 2;
                                                        move[2] = initial_j;
                                                        move[3] = initial_i;

                                                        s_move = move;

							n_move = s_move.substr(0,4);

                                                        if(is_legal(n_move))
                                                        {
 //                                                               cout << "Move: " << s_move << endl;
                                                                moves.push(n_move);
                                                        }

							move[0] = initial_j - 2;
                                                        move[1] = initial_i + 2;
                                                        move[2] = initial_j;
                                                        move[3] = initial_i;

                                                        s_move = move;

							n_move = s_move.substr(0,4);

                                                        if(is_legal(n_move))
                                                        {
//                                                                cout << "Move: " << s_move << endl;
                                                                moves.push(n_move);
                                                        }
						}
						else
						{
							char initial_i, initial_j;
							char move[4];
							string s_move, n_move;

                					initial_j = char(j) + 'a';
                					initial_i = char(i) + '1';

//							cout << initial_j << initial_i << endl;

							move[0] = initial_j + 1;
							move[1] = initial_i - 1;
							move[2] = initial_j;
							move[3] = initial_i;

							s_move = move;

							n_move = s_move.substr(0,4);

							if(is_legal(n_move))
							{
//								cout << "Move: " << s_move << endl;
								moves.push(n_move);
							}

							move[0] = initial_j - 1;
                                                	move[1] = initial_i + 1;
                                                	move[2] = initial_j;
                                                	move[3] = initial_i;

                                                	s_move = move;

							n_move = s_move.substr(0,4);

                                                	if(is_legal(n_move))
                                                	{
//	                                                      	cout << "Move: " << s_move << endl;
                                                        	moves.push(n_move);
                                                	}

							move[0] = initial_j + 1;
                                                	move[1] = initial_i + 1;
                                                	move[2] = initial_j;
                                                	move[3] = initial_i;

                                                	s_move = move;

							n_move = s_move.substr(0,4);

                                                	if(is_legal(n_move))
                                                	{
//	                                                      	cout << "Move: " << s_move << endl;
                                                        	moves.push(n_move);
                                                	}

							move[0] = initial_j - 1;
                                                	move[1] = initial_i + 1;
                                                	move[2] = initial_j;
                                                	move[3] = initial_i;

                                                	s_move = move;

							n_move = s_move.substr(0,4);

                                                	if(is_legal(n_move))
                                                	{
//                                                        	cout << "Move: " << s_move << endl;
                                                        	moves.push(n_move);
                                                	}
						}
					}
					else if(board[i][j].is_white() && !board[i][j].is_king())
					{
						if(is_jump_available())
						{
							char initial_i, initial_j;
                                                        char move[4];
                                                        string s_move, n_move;

                                                        initial_j = char(j) + 'a';
                                                        initial_i = char(i) + '1';

//							cout << initial_j << initial_i << endl;

                                                        move[0] = initial_j + 2;
                                                        move[1] = initial_i - 2;
                                                        move[2] = initial_j;
                                                        move[3] = initial_i;

                                                        s_move = move;

							n_move = s_move.substr(0,4);

                                                        if(is_legal(n_move))
                                                        {
//                                                                cout << "Move: " << s_move << endl;
                                                                moves.push(n_move);
                                                        }

                                                        move[0] = initial_j - 2;
                                                        move[1] = initial_i - 2;
                                                        move[2] = initial_j;
                                                        move[3] = initial_i;

                                                        s_move = move;

							n_move = s_move.substr(0,4);

                                                        if(is_legal(n_move))
                                                        {
//                                                                cout << "Move: " << s_move << endl;
                                                                moves.push(n_move);
                                                        }
						}
						else
						{
							char initial_i, initial_j;
                                                	char move[4];
							string s_move, n_move;

                                                	initial_j = char(j) + 'a';
                                                	initial_i = char(i) + '1';

//							cout << initial_j << initial_i << endl;

                                                	move[0] = initial_j + 1;
                                                	move[1] = initial_i - 1;
                                                	move[2] = initial_j;
                                                	move[3] = initial_i;

                                                	s_move = move;

							n_move = s_move.substr(0,4);

							if(is_legal(n_move))
							{
 //                                               		cout << "Move: " << s_move << endl;
								moves.push(n_move);
							}

							move[0] = initial_j - 1;
                                                	move[1] = initial_i - 1;
                                                	move[2] = initial_j;
                                                	move[3] = initial_i;

                                                	s_move = move;

							n_move = s_move.substr(0,4);

                                                	if(is_legal(n_move))
                                                	{
//                                                        	cout << "Move: " << s_move << endl;
                                                		moves.push(n_move);
							}
						}
					}
				}
				else if(next_mover() == COMPUTER)
                                {
                                        if(board[i][j].is_red() && board[i][j].is_king())
                                        {
						if(is_jump_available())
						{
							char initial_i, initial_j;
                                                        char move[4];
                                                        string s_move, n_move;

                                                        initial_j = char(j) + 'a';
                                                        initial_i = char(i) + '1';

//							cout << initial_j << initial_i << endl;

                                                        move[2] = initial_j + 2;
                                                        move[3] = initial_i - 2;
                                                        move[0] = initial_j;
                                                        move[1] = initial_i;

                                                        s_move = move;

							n_move = s_move.substr(0,4);

                                                        if(is_legal(n_move))
                                                        {
//                                                                cout << "Move: " << s_move << endl;
                                                                moves.push(n_move);
                                                        }

                                                        move[2] = initial_j - 2;
                                                        move[3] = initial_i - 2;
                                                        move[0] = initial_j;
                                                        move[1] = initial_i;

                                                        s_move = move;

							n_move = s_move.substr(0,4);

                                                        if(is_legal(n_move))
                                                        {
 //                                                               cout << "Move: " << s_move << endl;
                                                                moves.push(n_move);
                                                        }

							move[2] = initial_j + 2;
                                                        move[3] = initial_i + 2;
                                                        move[0] = initial_j;
                                                        move[1] = initial_i;

                                                        s_move = move;

							n_move = s_move.substr(0,4);

                                                        if(is_legal(n_move))
                                                        {
//                                                                cout << "Move: " << s_move << endl;
                                                                moves.push(n_move);
                                                        }

                                                        move[2] = initial_j - 2;
                                                        move[3] = initial_i + 2;
                                                        move[0] = initial_j;
                                                        move[1] = initial_i;

                                                        s_move = move;

							n_move = s_move.substr(0,4);

                                                        if(is_legal(n_move))
                                                        {
//                                                                cout << "Move: " << s_move << endl;
                                                                moves.push(n_move);
							}
						}
						else
						{
                                                	char initial_i, initial_j;
                                                	char move[4];
                                                	string s_move, n_move;

                                                	initial_j = char(j) + 'a';
                                                	initial_i = char(i) + '1';

//							cout << initial_j << initial_i << endl;

                                                	move[2] = initial_j + 1;
                                                	move[3] = initial_i - 1;
                                                	move[0] = initial_j;
                                                	move[1] = initial_i;

                                                	s_move = move;

							n_move = s_move.substr(0,4);

                                                	if(is_legal(n_move))
                                                	{
//                                                    		cout << "Move: " << s_move << endl;
                                                        	moves.push(n_move);
                                                	}

							move[2] = initial_j - 1;
                                                	move[3] = initial_i - 1;
                                                	move[0] = initial_j;
                                                	move[1] = initial_i;

                                                	s_move = move;

							n_move = s_move.substr(0,4);

                                                	if(is_legal(n_move))
                                                	{
//                                                      		cout << "Move: " << s_move << endl;
                                                        	moves.push(n_move);
                                                	}

                                                	move[2] = initial_j + 1;
                                                	move[3] = initial_i + 1;
                                                	move[0] = initial_j;
                                                	move[1] = initial_i;

                                                	s_move = move;

							n_move = s_move.substr(0,4);

							if(is_legal(n_move))
                                                	{
//                                                      		cout << "Move: " << s_move << endl;
                                                        	moves.push(n_move);
                                                	}

                                                	move[2] = initial_j - 1;
                                                	move[3] = initial_i + 1;
                                                	move[0] = initial_j;
                                                	move[1] = initial_i;

                                                	s_move = move;

							n_move = s_move.substr(0,4);

                                                	if(is_legal(n_move))
                                                	{
//                                                      		cout << "Move: " << s_move << endl;
                                                        	moves.push(n_move);
                                                	}
						}
					}
					else if(board[i][j].is_red() && !board[i][j].is_king())
                                        {
						if(is_jump_available())
						{
							char initial_i, initial_j;
                                                        char move[4];
                                                        string s_move, n_move;

                                                        initial_j = char(j) + 'a';
                                                        initial_i = char(i) + '1';

//							cout << initial_j << initial_i << endl;

                                                        move[2] = initial_j + 2;
                                                        move[3] = initial_i + 2;
                                                        move[0] = initial_j;
                                                        move[1] = initial_i;

                                                        s_move = move;

							n_move = s_move.substr(0,4);

                                                        if(is_legal(n_move))
                                                        {
//                                                        	cout << "Move: " << s_move << endl;
                                                                moves.push(n_move);
                                                        }

                                                        move[2] = initial_j - 2;
                                                        move[3] = initial_i + 2;
                                                        move[0] = initial_j;
                                                        move[1] = initial_i;

                                                        s_move = move;

							n_move = s_move.substr(0,4);

                                                        if(is_legal(n_move))
                                                        {
//	                                                	cout << "Move: " << s_move << endl;
                                                                moves.push(n_move);
                                                        }
						}
						else
						{
                                                	char initial_i, initial_j;
                                                	char move[5];
                                                	string s_move, n_move;

                                                	initial_j = char(j) + 'a';
                                                	initial_i = char(i) + '1';

//							cout << initial_j << initial_i << endl;

                                                	move[2] = initial_j + 1;
                                                	move[3] = initial_i + 1;
                                                	move[0] = initial_j;
                                                	move[1] = initial_i;

                                                	s_move = move;

							n_move = s_move.substr(0,4);

                                                	if(is_legal(n_move))
                                                	{
//                                                      		cout << "Move: " << s_move << endl;
                                                        	moves.push(n_move);
                                                	}

							move[2] = initial_j - 1;
                                                	move[3] = initial_i + 1;
                                                	move[0] = initial_j;
                                                	move[1] = initial_i;

                                                	s_move = move;

							n_move = s_move.substr(0,4);

                                                	if(is_legal(n_move))
                                                	{
 //                                                     		cout << "Move: " << s_move << endl;
                                                        	moves.push(n_move);
                                                	}
                                        	}
					}
				}
			}
		}
	}


}


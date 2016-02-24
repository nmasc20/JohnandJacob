/**
 * ohhi.cpp
 *
 * EECS 183, Winter 2015
 * Project 3: 0h h1
 *
 * John Paul Imperial, Jacob Rich
 * jpimp, jacobjdr
 *
 * <#A description of the project here#>
 */

#include <iostream>
#include <cctype>
#include "utility.h"
#include "ohhi.h"

///////////////////////////////////////
// UTILITY FUNCTIONS //////////////////
///////////////////////////////////////

int count_unknown_squares(const int board[MAX_SIZE][MAX_SIZE], int size) {
    int unknown = 0;
    for (int x = 0; x < size; x++)
        for (int y = 0; y < size; y++)
            if (board[x][y] == 0) {
                unknown++;
            }
    return unknown;
}


///////////////////////////////////////
// VALIDITY CHECKS ////////////////////
///////////////////////////////////////

bool row_has_no_threes_of_color(const int board[MAX_SIZE][MAX_SIZE],
                                int size,
                                int row,
                                int color) {
    const int oneSpace = 1;
    const int twoSpace = 2;

    for (int i = 0; i < size - twoSpace; i++)
        if (board[row][i] == board[row][i + oneSpace] &&
            board[row][i + oneSpace] == board[row][i + twoSpace]
            && board[row][i] == color) {
            return false;
        }
            
    return true;   
}

bool col_has_no_threes_of_color(const int board[MAX_SIZE][MAX_SIZE],
                                int size,
                                int col,
                                int color) {
    const int oneSpace = 1;
    const int twoSpace = 2;

    for (int i = 0; i < size - twoSpace; i++)
        if (board[i][col] == board[i + oneSpace][col] &&
            board[i + oneSpace][col] == board[i + twoSpace][col]
            && board[i][col] == color) {
            return false;

        }
           
    return true;
}

bool board_has_no_threes(const int board[MAX_SIZE][MAX_SIZE], int size) {

	for (int i = 0; i < size; i++)
		if (!row_has_no_threes_of_color(board, size, i, BLUE) || 
			!col_has_no_threes_of_color(board, size, i, BLUE) ||
			!row_has_no_threes_of_color(board, size, i, RED) ||
			!col_has_no_threes_of_color(board, size, i, RED)) {

        return false;
    }
    return true;
}

bool rows_are_different(const int board[MAX_SIZE][MAX_SIZE],
                        int size,
                        int row1,
                        int row2) {
    for (int col = 0; col < size; col++)
        if (board[row1][col] == 0 || board[row2][col] == 0 ||
            board[row1][col] != board[row2][col]) {
            return true;
        }

    return false;
}

bool cols_are_different(const int board[MAX_SIZE][MAX_SIZE],
                        int size,
                        int col1,
                        int col2) {
    for (int row = 0; row < size; row++)
        if (board[row][col1] == 0 || board[row][col2] == 0 ||
            board[row][col1] != board[row][col2]) {
            return true;
        }

    return false;
}

bool board_has_no_duplicates(const int board[MAX_SIZE][MAX_SIZE], int size) {
    for (int x = 0; x < size; x++) {
        for (int y = x + 1; y < size; y++) {
            if (!rows_are_different(board, size, x, y)) {
                return false;
            }
            else if (!cols_are_different(board, size, x, y)) {
                return false;
            }
        }
    }

    return true;
}


///////////////////////////////////////
// SOLVING FUNCTIONS //////////////////
///////////////////////////////////////

void solve_three_in_a_row(int board[MAX_SIZE][MAX_SIZE],
                          int size,
                          int row,
                          bool announce) {
	for (int col = 0; col < size; col++) {
		if (board[row][col] == board[row][col + 1] && board[row][col] != UNKNOWN) {
			board[row][col + 2] = opposite_color(board[row][col]);
			if (col > 0) {
				board[row][col - 1] = opposite_color(board[row][col]);
			}
		}
	}
	for (int col = 0; col < size; col++) {
		if (board[row][col] == board[row][col + 2] && board[row][col] != UNKNOWN) {
			board[row][col + 1] = opposite_color(board[row][col]);
		}
	}
	
}

void solve_three_in_a_column(int board[MAX_SIZE][MAX_SIZE],
                             int size,
                             int col,
                             bool announce) {
	for (int col = 0; col < size; col++) {
		if (board[row][col] == board[row][col + 1] && board[row][col] != UNKNOWN) {
			board[row][col + 2] = opposite_color(board[row][col]);
			if (col > 0) {
				board[row][col - 1] = opposite_color(board[row][col]);
			}
		}
	}
	for (int col = 0; col < size; col++) {
		if (board[row][col] == board[row][col + 2] && board[row][col] != UNKNOWN) {
			board[row][col + 1] = opposite_color(board[row][col]);
		}
	}
}


void solve_balance_row(int board[MAX_SIZE][MAX_SIZE],
                       int size,
                       int row,
                       bool announce) {
	int num_red = 0;
	int num_blue = 0;
	for (int col = 0; col < size; col++) {
		if (board[row][col] == RED) {
			num_red++;
		}
		else if (board[row][col] == BLUE) {
			num_blue++;
		}
	}
	//if num red tiles is exactly half row, mark unknown squares as blue
	//go through row, if element is UNKNOWN, mark as blue
		//vice versa for blue
	if (num_red == size / 2) {
		for (int col = 0; col < size; col++) {
			if (board[row][col] == UNKNOWN) {
				mark_square_as(board, size, row, col, BLUE, announce);
				cout << "Square has been modified." << endl;
			}
		}
	}
	
	if (num_blue == size / 2) {
		for (int col = 0; col < size; col++) {
			if (board[row][col] == UNKNOWN) {
				mark_square_as(board, size, row, col, RED, announce);
				cout << "Square has been modified." << endl;
			}
		}
	}
	
	
}

void solve_balance_column(int board[MAX_SIZE][MAX_SIZE],
                          int size,
                          int col,
                          bool announce) {
	int num_red = 0;
	int num_blue = 0;
	for (int row = 0; row < size; row++) {
		if (board[row][col] == RED) {
			num_red++;
		}
		else if (board[row][col] == BLUE) {
			num_blue++;
		}
	}
	//if num red tiles is exactly half col, mark unknown squares as blue
	//go through col, if element is UNKNOWN, mark as blue
	//vice versa for blue
	if (num_red == size / 2) {
		for (int row = 0; row < size; row++) {
			if (board[row][col] == UNKNOWN) {
				mark_square_as(board, size, row, col, BLUE, announce);
				cout << "Square has been modified." << endl;
			}
		}
	}
	if (num_blue == size / 2) {
		for (int row = 0; row < size; row++) {
			if (board[row][col] == UNKNOWN) {
				mark_square_as(board, size, row, col, RED, announce);
				cout << "Square has been modified." << endl;
			}
		}
	}
}


///////////////////////////////////////
// GAMEPLAY FUNCTIONS /////////////////
///////////////////////////////////////

bool board_is_solved(const int board[MAX_SIZE][MAX_SIZE], int size) {
    // your code here
    return false;
}

bool check_valid_input(int size, int row_input, char col_input,
                       char color_char, int &row, int &col) {
    // your code here
    return false;
}

bool check_valid_move(const int original_board[MAX_SIZE][MAX_SIZE],
                      const int current_board[MAX_SIZE][MAX_SIZE],
                      int size, int row, int col, int color) {
    // your code here
    return false;
}


///////////////////////////////////////
// S'MORE FUNCTIONS ///////////////////
///////////////////////////////////////


void solve_lookahead_row(int board[MAX_SIZE][MAX_SIZE],
                         int size,
                         int row,
                         bool announce) {
    // your code here
}

void solve_lookahead_column(int board[MAX_SIZE][MAX_SIZE],
                            int size,
                            int col,
                            bool announce) {
    // your code here
}

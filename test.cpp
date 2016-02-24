/**
 * test.cpp
 *
 * EECS 183, Winter 2015
 * Project 3: 0h h1 Test Suite
 *
 * John Paul Imperial, Jacob Rich
 * jpimp, jacobjdr
 *
 * <#A description of the project here#>
 */

#include <iostream>
#include "utility.h"
#include "ohhi.h"

void test_count_unknown_squares();
void test_row_has_no_threes_of_color();
void test_col_has_no_threes_of_color();
void test_board_has_no_threes();
void test_solve_balance_row();
void test_solve_balance_column();
void test_solve_three_in_a_row();

int main() {
    //test_count_unknown_squares();
    //test_row_has_no_threes_of_color();
    //test_col_has_no_threes_of_color();
	//test_board_has_no_threes();
	//test_solve_balance_row();
	//test_solve_balance_column();
	test_solve_three_in_a_row();
    return 0;
}


void test_count_unknown_squares() {
    int board[MAX_SIZE][MAX_SIZE];

    // test case 1
    string test_board_1[] = {"O-OX",
                             "OO--",
                             "X---",
                             "-O--"};
    int size_1 = 4;
    read_board_from_string(board, test_board_1, size_1);
    cout << count_unknown_squares(board, size_1) << endl;

    // add more tests here
}

void test_row_has_no_threes_of_color() {
    int board[MAX_SIZE][MAX_SIZE];

    //test case 1
    string test_board_1[] = {"O-OX",
                             "-OOO",
                             "X---",
                             "-O--"};
    int size_1 = 4;
    read_board_from_string(board, test_board_1, size_1);
    cout << "Row 0: " << row_has_no_threes_of_color(board, size_1, 0, RED) << endl;
    cout << "Row 1: " << row_has_no_threes_of_color(board, size_1, 1, RED) << endl;
    cout << "Row 1: " << row_has_no_threes_of_color(board, size_1, 1, BLUE) << endl;
    cout << "Row 2: " << row_has_no_threes_of_color(board, size_1, 2, RED) << endl;
}

void test_col_has_no_threes_of_color() {
    int board[MAX_SIZE][MAX_SIZE];

    //test case 1
    string test_board_1[] = {"----",
                             "XXO-",
                             "-XO-",
                             "--O-" };
    int size_1 = 4;
    read_board_from_string(board, test_board_1, size_1);
    cout << "Col 1: " << col_has_no_threes_of_color(board, size_1, 1, RED) << endl;
    cout << "Col 2: " << col_has_no_threes_of_color(board, size_1, 2, RED) << endl;
    cout << "Col 2: " << col_has_no_threes_of_color(board, size_1, 2, BLUE) << endl;
    cout << "Col 3: " << col_has_no_threes_of_color(board, size_1, 3, RED) << endl;
}

void test_board_has_no_threes() {
	int board[MAX_SIZE][MAX_SIZE];
	string test_board_1[] = { "----",
						      "XXO-",
							  "-XO-",
							  "--O-" };

	string test_board_2[] = { "----",
						      "XXO-",
							  "-XO-",
							  "--X-" };
	int size_1 = 4;
	read_board_from_string(board, test_board_1, size_1);
	cout << "test_board_1 should be 0: " << board_has_no_threes(board, size_1) << endl;
	read_board_from_string(board, test_board_2, size_1);
	cout << "test_board_2 should be 1: " << board_has_no_threes(board, size_1) << endl;


}

void test_solve_balance_row() {
	bool announce = true;
	int board[MAX_SIZE][MAX_SIZE];
	string test_board_1[] = { "O-OX",
							  "-OOX",
							  "XX-O",
							  "-OXX" };

	int size_1 = 4;
	read_board_from_string(board, test_board_1, size_1);
	solve_balance_row(board, size_1, 0, announce);
	solve_balance_row(board, size_1, 1, announce);
	solve_balance_row(board, size_1, 2, announce);
	solve_balance_row(board, size_1, 3, announce);
	print_board(board, size_1);
	
}

void test_solve_balance_column() {
	bool announce = true;
	int board[MAX_SIZE][MAX_SIZE];
	string test_board_1[] = { "O-OX",
							  "-OOX",
							  "OX-O",
							  "-OX-" };

	int size_1 = 4;
	read_board_from_string(board, test_board_1, size_1);
	solve_balance_column(board, size_1, 0, announce);
	solve_balance_column(board, size_1, 1, announce);
	solve_balance_column(board, size_1, 2, announce);
	solve_balance_column(board, size_1, 3, announce);
	print_board(board, size_1);

}

void test_solve_three_in_a_row() {
	bool announce = true;
	int board[MAX_SIZE][MAX_SIZE];
	string test_board_1[] = { "OO--",
						      "-OO-",
							  "-XX-",
							  "--XX" };

	int size_1 = 4;
	read_board_from_string(board, test_board_1, size_1);
	solve_three_in_a_row(board, size_1, 0, announce);
	solve_three_in_a_row(board, size_1, 1, announce);
	solve_three_in_a_row(board, size_1, 2, announce);
	solve_three_in_a_row(board, size_1, 3, announce);
	print_board(board, size_1);

	string test_board_2[] = { "O-O-",
							  "-O-O",
							  "-X-X",
						      "--XX" };

	read_board_from_string(board, test_board_2, size_1);
	solve_three_in_a_row(board, size_1, 0, announce);
	solve_three_in_a_row(board, size_1, 1, announce);
	solve_three_in_a_row(board, size_1, 2, announce);
	solve_three_in_a_row(board, size_1, 3, announce);
	print_board(board, size_1);
}
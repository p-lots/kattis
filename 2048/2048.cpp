#include <algorithm>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

typedef std::vector<std::vector<int> > board_vec;

std::vector<int> tokenize(std::string);

void slide_left(board_vec &, int);

void move_left(board_vec &);

void slide_right(board_vec &, int);

void move_right(board_vec &);

void slide_up(board_vec &, int);

void move_up(board_vec &);

void slide_down(board_vec &, int);

void move_down(board_vec &);

void do_move(int, board_vec &);

int main(int argc, char *argv[])
{
	std::string temp;
	int linecount = 1, move = -1;
	board_vec board;
	
	while (std::getline(std::cin, temp)) {
		if (linecount < 5) {
			board.push_back(tokenize(temp));
			linecount++;
		}
		else {
			move = std::stoi(temp);
		}
	}

	do_move(move, board);

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			std::cout << board[i][j];
			if (j < 3) {
				std::cout << ' ';
			}
			else {
				std::cout << '\n';
			}
		}
	}

	return 0;
}

std::vector<int> tokenize(std::string line)
{
	std::vector<int> ret;
	std::stringstream ss(line);
	std::string temp;
	while (std::getline(ss, temp, ' ')) {
		ret.push_back(std::stoi(temp));
	}
	return ret;
}

void slide_left(board_vec &board, int i)
{
	for (int j = 1; j < 4; j++) {
		for (int k = j; k > 0; k--) {
			if (board[i][k - 1] == 0) {
				std::swap(board[i][k - 1], board[i][k]);
			}
		}
	}
}

void move_left(board_vec &board)
{
	for (int i = 0; i < 4; i++) {
		slide_left(board, i);
		for (int j = 1; j < 4; j++) {
			if (board[i][j] == board[i][j - 1]) {
				board[i][j] = 0;
				board[i][j - 1] *= 2;
			}
		}
		slide_left(board, i);
	}
}

void slide_right(board_vec &board, int i)
{
	for (int j = 2; j > -1; j--) {
		for (int k = j; k < 3; k++) {
			if (board[i][k + 1] == 0) {
				std::swap(board[i][k], board[i][k + 1]);
			}
		}
	}
}

void move_right(board_vec &board)
{
	for (int i = 0; i < 4; i++) {
		slide_right(board, i);
		for (int j = 2; j > -1; j--) {
			if (board[i][j] == board[i][j + 1]) {
				board[i][j] = 0;
				board[i][j + 1] *= 2;
			}
		}
		slide_right(board, i);
	}
}

void slide_up(board_vec &board, int j)
{
	for (int i = 1; i < 4; i++) {
		for (int k = i; k > 0; k--) {
			if (board[k - 1][j] == 0) {
				std::swap(board[k][j], board[k - 1][j]);
			}
		}
	}
}

void move_up(board_vec &board)
{
	for (int j = 0; j < 4; j++) {
		slide_up(board, j);
		for (int i = 1; i < 4; i++) {
			if (board[i][j] == board[i - 1][j]) {
				board[i][j] = 0;
				board[i - 1][j] *= 2;
			}
		}
		slide_up(board, j);
	}
}

void slide_down(board_vec &board, int j)
{
	for (int i = 2; i > -1; i--) {
		for (int k = i; k < 3; k++) {
			if (board[k + 1][j] == 0) {
				std::swap(board[k][j], board[k + 1][j]);
			}
		}
	}
}

void move_down(board_vec &board)
{
	for (int j = 0; j < 4; j++) {
		slide_down(board, j);
		for (int i = 2; i > -1; i--) {
			if (board[i][j] == board[i + 1][j]) {
				board[i][j] = 0;
				board[i + 1][j] *= 2;
			}
		}
		slide_down(board, j);
	}
}

/**
 * 0 == left
 * 1 == up
 * 2 == right
 * 3 == down
 */

void do_move(int move, board_vec &board)
{
	switch (move) {
		case 0:
		move_left(board);
		break;
		case 1:
		move_up(board);
		break;
		case 2:
		move_right(board);
		break;
		case 3:
		move_down(board);
		break;
		default:
		throw std::domain_error("Invalid move");
		break;
	}
}
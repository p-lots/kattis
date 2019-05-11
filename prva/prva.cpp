#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

int main(int argc, char *argv[])
{
	int r, c;
	std::string line;
	std::getline(std::cin, line);
	std::stringstream ss(line);
	ss >> r >> c;
	int lines = r;
	std::vector<std::string> board;
	while (lines-- > 0) {
		std::getline(std::cin, line);
		board.push_back(line);
	}
	std::vector<std::string> word_list;
	for (auto it = board.begin(); it != board.end(); it++) {
		std::string word;
		for (auto str_it = it->begin(); str_it != it->end(); str_it++) {
			if (*str_it == '#') {
				if (word.length() >= 2) {
					word_list.push_back(word);	
				}
				word.clear();
				continue;
			}
			else {
				word.push_back(*str_it);
			}
		}
		if (word.length() >= 2) {
			word_list.push_back(word);
		}
	}
	for (unsigned i = 0; i < c; i++) {
		std::string word;
		for (unsigned j = 0; j < r; j++) {
			if (board[j][i] == '#') {
				if (word.length() >= 2) {
					word_list.push_back(word);
				}
				word.clear();
				continue;
			}
			else {
				word.push_back(board[j][i]);
			}
		}
		if (word.length() >= 2) {
			word_list.push_back(word);
		}
	}
	std::sort(word_list.begin(), word_list.end());
	std::cout << word_list.front();
	return 0;
}
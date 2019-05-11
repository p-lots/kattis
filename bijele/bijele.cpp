#include <iostream>
#include <sstream>
#include <string>
#include <vector>

std::vector<std::string> tokenize(std::string line)
{
	std::stringstream ss(line);
	std::string temp;
	std::vector<std::string> ret;
	while (std::getline(ss, temp, ' ')) {
		ret.push_back(temp);
	}
	return ret;
}

int main(int argc, char *argv[])
{
	std::string temp;

	while (std::getline(std::cin, temp)) {
		std::vector<std::string> tokens = tokenize(temp);
		int kings = std::stoi(tokens[0]);
		int queens = std::stoi(tokens[1]);
		int rooks = std::stoi(tokens[2]);
		int bishops = std::stoi(tokens[3]);
		int knights = std::stoi(tokens[4]);
		int pawns = std::stoi(tokens[5]);
		std::cout << 1 - kings << ' ';
		std::cout << 1 - queens << ' ';
		std::cout << 2 - rooks << ' ';
		std::cout << 2 - bishops << ' ';
		std::cout << 2 - knights << ' ';
		std::cout << 8 - pawns;
	}

	return 0;
}
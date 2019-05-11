#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <string>

int main(int argc, char *argv[])
{
	std::string line;
	std::cin >> line;
	std::map<char, unsigned> card_counts;
	for (char c : line) {
		card_counts[c]++;
	}
	unsigned score = 0;
	for (auto p : card_counts) {
		score += std::pow(p.second, 2);
	}
	if ((card_counts.find('T') != card_counts.end()
		&& card_counts.find('C') != card_counts.end())
		&& card_counts.find('G') != card_counts.end()) {
		score += std::min(card_counts.at('T'),
			std::min(card_counts.at('C'), card_counts.at('G'))) * 7;
	}
	std::cout << score;
	return 0;
}
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main(int argc, char *argv[])
{
	std::string line;
	std::getline(std::cin, line);
	std::vector<std::string> cards;
	for (unsigned i = 0; i < line.length(); i += 3) {
		std::string card = line.substr(i, 3);
		if (std::find(cards.begin(), cards.end(), card) != cards.end()) {
			std::cout << "GRESKA";
			return 0;
		}
		cards.push_back(card);
	}
	int p_count = 13, k_count = 13, h_count = 13, t_count = 13;
	for (std::string card : cards) {
		char suit = card.front();
		if (suit == 'P') {
			p_count--;
		}
		else if (suit == 'K') {
			k_count--;
		}
		else if (suit == 'H') {
			h_count--;
		}
		else if (suit == 'T') {
			t_count--;
		}
	}
	std::cout << p_count << ' ' << k_count << ' ';
	std::cout << h_count << ' ' << t_count;
	return 0;
}

#include <iostream>
#include <map>
#include <utility>
#include <vector>

int main(int argc, char *argv[])
{
	std::map<char, std::pair<int, int> > lookup_table = {
		{ 'A', { 11, 11 } },
		{ 'K', { 4, 4 } },
		{ 'Q', { 3, 3 } },
		{ 'J', { 20, 2 } },
		{ 'T', { 10, 10 } },
		{ '9', { 14, 0 } },
		{ '8', { 0, 0 } },
		{ '7', { 0, 0 } }
	};
	int num_hands;
	char dom_suit;
	std::cin >> num_hands >> dom_suit;
	std::vector<std::pair<char, char> > hands;
	int total_cards = num_hands * 4;
	while (total_cards--) {
		char card, suit;
		std::cin >> card >> suit;
		hands.push_back(std::make_pair(card, suit));
	}
	int sum = 0;
	for (const auto c : hands) {
		if (c.second == dom_suit) {
			sum += lookup_table.at(c.first).first;
		}
		else {
			sum += lookup_table.at(c.first).second;
		}
	}
	std::cout << sum;
	return 0;
}
#include <algorithm>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

std::vector<std::string> tokenize(std::string line)
{
	std::vector<std::string> ret;
	std::stringstream ss(line);
	std::string temp;
	while (std::getline(ss, temp, ' ')) {
		ret.push_back(temp);
	}
	return ret;
}

int main(int argc, char *argv[])
{
	int customers;
	std::string line;
	while (std::getline(std::cin, line)) {
		customers = std::stoi(line);
		if (customers == 0) {
			break;
		}
		std::map<std::string, std::vector<std::string> > item_map;
		for (unsigned i = 0; i < customers; i++) {
			std::getline(std::cin, line);
			std::string cust_name;
			std::vector<std::string> tokens, food_items;
			tokens = tokenize(line);
			cust_name = tokens.at(0);
			food_items = std::vector<std::string>(tokens.begin() + 1, tokens.end());
			for (std::string s : food_items) {
				item_map[s].push_back(cust_name);
			}
		}
		for (auto &p : item_map) {
			std::cout << p.first << ' ';
			std::sort(p.second.begin(), p.second.end());
			for (auto s : p.second) {
				std::cout << s << ' ';
			}
			std::cout << '\n';
		}
		std::cout << '\n';
	}
	return 0;
}
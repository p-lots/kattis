#include <iostream>
#include <map>
#include <string>

int main()
{
	std::string line;
	std::getline(std::cin, line);
	int cases = std::stoi(line);
	std::map<char, std::string> adjacent_map = {
		{ 'a', "abc" }, { 'b', "abc" }, { 'c', "abc" },
		{ 'd', "def" }, { 'e', "def" }, { 'f', "def" },
		{ 'g', "ghi" }, { 'h', "ghi" }, { 'i', "ghi" },
		{ 'j', "jkl" }, { 'k', "jkl" }, { 'l', "jkl" },
		{ 'm', "mno" }, { 'n', "mno" }, { 'o', "mno" },
		{ 'p', "pqrs" }, { 'q', "pqrs" }, { 'r', "pqrs" }, { 's', "pqrs" },
		{ 't', "tuv" }, { 'u', "tuv" }, { 'v', "tuv" },
		{ 'w', "wxyz" }, { 'x', "wxyz" }, { 'y', "wxyz" }, { 'z', "wxyz" },
		{ ' ', " " }
	};
	std::map<char, std::string> lookup_table = {
		{ 'a', "2" }, { 'b', "22" }, { 'c', "222" },
		{ 'd', "3" }, { 'e', "33" }, { 'f', "333" },
		{ 'g', "4" }, { 'h', "44" }, { 'i', "444" },
		{ 'j', "5" }, { 'k', "55" }, { 'l', "555" },
		{ 'm', "6" }, { 'n', "66" }, { 'o', "666" },
		{ 'p', "7" }, { 'q', "77" }, { 'r', "777" }, { 's', "7777" },
		{ 't', "8" }, { 'u', "88" }, { 'v', "888" },
		{ 'w', "9" }, { 'x', "99" }, { 'y', "999" }, { 'z', "9999" },
		{ ' ', "0" }
	};
	int cases_output = 1;
	while (cases--) {
		std::getline(std::cin, line);
		std::string output = "";
		for (auto it = line.begin(); it != line.end() - 1; it++) {
			output += lookup_table.at(*it);
			char next = *(it + 1);
			if (adjacent_map.at(next) == adjacent_map.at(*it)) {
				output += " ";
			}
		}
		output += lookup_table.at(line.back());
		std::cout << "Case #" << cases_output++ << ": " << output << '\n';
	}
	return 0;
}
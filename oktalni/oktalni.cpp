#include <cmath>
#include <map>
#include <iostream>
#include <string>

std::map<std::string, std::string> lookup_table = {
	{ "000", "0" },
	{ "001", "1" },
	{ "010", "2" },
	{ "011", "3" },
	{ "100", "4" },
	{ "101", "5" },
	{ "110", "6" },
	{ "111", "7" }
};

int main()
{
	std::string line;
	std::getline(std::cin, line);
	while (line.length() % 3 != 0) {
		line = "0" + line;
	}
	std::string result = "";
	for (unsigned i = 0; i < line.length(); i += 3) {
		auto slice = line.substr(i, 3);
		result += lookup_table.at(slice);
	}
	std::cout << result;
	return 0;
}
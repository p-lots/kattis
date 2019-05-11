#include <cctype>
#include <iostream>
#include <map>
#include <string>
#include <sstream>
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

std::string make_lower(std::string str)
{
	for (char &c : str)
		if (std::isalpha(c)) 
			c = std::tolower(c);
	return str;
}

int main()
{
	std::string line;
	int list_number = 1;
	while (std::getline(std::cin, line)) {
		int num_lines = std::stoi(line);
		if (num_lines == 0) {
			break;
		}
		std::map<std::string, int> list;
		while (num_lines--) {
			std::getline(std::cin, line);
			auto tokens = tokenize(line);
			auto list_insert = make_lower(tokens.back());
			list[list_insert]++;
		}
		std::cout << "List " << list_number++ << ":\n";
		for (auto pair : list) {
			std::cout << pair.first << " | " << pair.second << '\n';
		}
	}
	return 0;
}
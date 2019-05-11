#include <iostream>
#include <string>
#include <vector>

int main(int argc, char *argv[])
{
	int set_num = 1;
	std::string line;
	while (std::getline(std::cin, line)) {
		int num_strings = std::stoi(line);
		if (num_strings == 0) {
			break;
		}
		std::vector<std::string> first, last;
		for (unsigned i = 0; i < num_strings; i++) {
			std::getline(std::cin, line);
			if (i % 2 == 0) {
				first.push_back(line);
			}
			else {
				last.push_back(line);
			}
		}
		std::vector<std::string> result;
		for (std::string s : first) {
			result.push_back(s);
		}
		for (auto it = last.crbegin(); it != last.crend(); it++) {
			result.push_back(*it);
		}
		std::cout << "SET " << set_num++ << '\n';
		for (std::string s : result) {
			std::cout << s << '\n';
		}
	}	
	return 0;
}

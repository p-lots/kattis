#include <iostream>
#include <sstream>
#include <string>
#include <vector>

std::vector<std::string> tokenize(std::string);

int main(int argc, char *argv[])
{
	std::string line;
	bool first_time = true;
	while (std::getline(std::cin, line)) {
		if (first_time) {
			first_time = false;
		}
		else {
			std::vector<std::string> tokenized = tokenize(line);
			if (tokenized[0] == "simon" && tokenized[1] == "says") {
				for (auto it = tokenized.begin() + 2;
					it != tokenized.end(); it++) {
					std::cout << *it;
					if (it != tokenized.end() - 1) std::cout << ' ';
				}
			}
			std::cout << '\n';
		}
	}
	return 0;
}

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
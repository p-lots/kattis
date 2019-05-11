#include <iostream>
#include <sstream>
#include <string>
#include <vector>

std::vector<int> tokenize(std::string);

int main(int argc, char *argv[])
{
	std::string line;
	std::getline(std::cin, line);
	int num_cases = std::stoi(line);
	while (num_cases--) {
		std::getline(std::cin, line);
		auto tokens = tokenize(line);
		unsigned prev = tokens.front(), sum = 0;
		for (auto it = tokens.begin() + 1; it != tokens.end(); it++) {
			if (*it == 0) {
				break;
			}
			unsigned max_from_prev = prev * 2;
			if (*it > max_from_prev) {
				sum += *it - max_from_prev;
			}
			prev = *it;
		}
		std::cout << sum << '\n';
	}
	return 0;
}

std::vector<int> tokenize(std::string line)
{
	std::vector<int> ret;
	std::stringstream ss(line);
	std::string temp;
	while (std::getline(ss, temp, ' ')) {
		ret.push_back(std::stoi(temp));
	}
	return ret;
}

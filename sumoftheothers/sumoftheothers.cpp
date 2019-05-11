#include <iostream>
#include <numeric>
#include <sstream>
#include <string>
#include <vector>

std::vector<int> tokenize(std::string);

bool sum_of_others(std::vector<int> &, std::vector<int>::iterator &);

int main(int argc, char *argv[])
{
	std::string line;
	while (std::getline(std::cin, line)) {
		auto tokens = tokenize(line);
		auto exclude = tokens.begin();
		while (!sum_of_others(tokens, exclude)) {
			exclude++;
			if (exclude == tokens.end()) {
				return 1;
			}
		}
		std::cout << *exclude << '\n';
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

bool sum_of_others(std::vector<int> &numbers, std::vector<int>::iterator &exclude)
{
	int expected_sum = *exclude;
	std::vector<int> new_numbers;
	if (exclude == numbers.begin()) {
		new_numbers = std::vector<int>(exclude + 1, numbers.end());
	}
	else {
		new_numbers = std::vector<int>(numbers.begin(), exclude);
		new_numbers.insert(new_numbers.end(), exclude + 1, numbers.end());
	}
	int actual_sum = std::accumulate(new_numbers.begin(), new_numbers.end(), 0);
	return expected_sum == actual_sum;
}
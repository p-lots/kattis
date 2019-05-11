#include <cmath>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

std::vector<int> tokenize(std::string line)
{
	std::vector<int> ret;
	std::stringstream ss(line);
	std::string temp;
	while (std::getline(ss, temp, ' ' ))
		ret.push_back(std::stoi(temp));
	return ret;
}

int distance(int first, int second)
{
	return (40 - std::abs(first - second)) * 9;
}

int main()
{
	std::string line;
	while (std::getline(std::cin, line)) {
		auto numbers = tokenize(line);
		if (numbers.at(0) == 0 && numbers.at(1) == 0
			&& numbers.at(2) == 0 && numbers.at(3) == 0)
			break;
		int result = distance(numbers.at(0), numbers.at(1))
		+ distance(numbers.at(1), numbers.at(2))
		+ distance(numbers.at(2), numbers.at(3))
		+ 1080;
		std::cout << result << '\n';
	}
	return 0;
}
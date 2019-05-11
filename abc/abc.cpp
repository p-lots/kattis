#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int main()
{
	std::string line;
	std::getline(std::cin, line);
	std::vector<int> numbers;
	std::stringstream ss(line);
	while (std::getline(ss, line, ' ')) {
		numbers.push_back(std::stoi(line));
	}
	std::sort(numbers.begin(), numbers.end());
	int a, b, c;
	a = numbers.at(0);
	b = numbers.at(1);
	c = numbers.at(2);
	std::getline(std::cin, line);
	for (const char &ch : line) {
		if (ch == 'A') {
			std::cout << a;
		}
		else if (ch == 'B') {
			std::cout << b;
		}
		else if (ch == 'C') {
			std::cout << c;
		}
		std::cout << ' ';
	}
	return 0;
}
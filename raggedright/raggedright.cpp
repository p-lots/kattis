#include <cmath>
#include <iostream>
#include <string>
#include <vector>

int main(int argc, char *argv[])
{
	std::vector<std::string> lines;
	std::string temp;
	int max = 0;
	while (std::getline(std::cin, temp)) {
		int len = temp.length();
		if (len > max) {
			max = len;
		}
		lines.push_back(temp);
	}
	int result = 0;
	for (auto it = lines.begin(); it != lines.end() - 1; it++) {
		if (it->length() < max) {
			result += std::pow(max - it->length(), 2);
		}
	}
	std::cout << result;
	return 0;
}

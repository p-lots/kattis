#include <iostream>
#include <sstream>
#include <string>
#include <vector>

std::vector<std::string> tokenize(std::string line)
{
	std::vector<std::string> ret;
	std::stringstream ss(line);
	std::string temp;
	while (std::getline(ss, temp, '-')) {
		ret.push_back(temp);
	}
	return ret;
}

int main()
{
	std::string line;
	std::getline(std::cin, line);
	auto tokens = tokenize(line);
	std::string result = "";
	for (std::string s : tokens) {
		result += s[0];
	}
	std::cout << result;
	return 0;
}
#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
	int cases;
	std::string line;
	std::getline(std::cin, line);
	cases = std::stoi(line);
	int wins = 0;
	while (cases--) {
		std::string temp;
		std::getline(std::cin, temp);
		auto cd_pos = temp.find("CD");
		if (cd_pos == std::string::npos) wins++;
	}
	std::cout << wins << '\n';
	return 0;
}
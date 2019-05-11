#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
	std::string line;
	std::getline(std::cin, line);
	int cases = std::stoi(line);
	while (cases-- > 0) {
		std::getline(std::cin, line);
		std::cout << line.length() << '\n';
	}
	return 0;
}

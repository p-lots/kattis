#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
	std::string line;
	std::getline(std::cin, line);
	int cases = std::stoi(line);
	while (cases--) {
		std::getline(std::cin, line);
		if (line.find("=") != std::string::npos) {
			std::cout << "skipped\n";
			continue;
		}
		auto plus_pos = line.find("+");
		int lhs = std::stoi(line.substr(0, plus_pos));
		int rhs = std::stoi(line.substr(plus_pos + 1));
		std::cout << lhs + rhs << '\n';
	}
	return 0;
}
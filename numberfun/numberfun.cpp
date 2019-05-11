#include <iostream>
#include <sstream>
#include <string>

int main(int argc, char *argv[])
{
	std::string line;
	std::getline(std::cin, line);
	int cases = std::stoi(line);
	while (cases--) {
		std::getline(std::cin, line);
		std::stringstream ss(line);
		int a, b, c;
		ss >> a >> b >> c;
		if ((a + b == c) || (a - b == c) || (b - a == c) || (a * b == c)
			|| (static_cast<double>(a) / static_cast<double>(b) == static_cast<double>(c))
			|| (static_cast<double>(b) / static_cast<double>(a) == static_cast<double>(c)))
			std::cout << "Possible\n";
		else std::cout << "Impossible\n";
	}
	return 0;
}
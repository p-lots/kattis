#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

int main(int argc, char *argv[])
{
	std::string line;
	std::getline(std::cin, line);
	int cases = std::stoi(line);
	int numer = 0, denom = 0, n;
	std::getline(std::cin, line);
	std::stringstream ss(line);
	while (ss >> n) {
		if (n < 0) continue;
		numer += n;
		denom++;
	}
	if (denom == 0) {
		std::cout << 0;
		return 0;
	}
	std::cout << std::fixed << std::setprecision(10)
		<< static_cast<double>(numer) / static_cast<double>(denom);
	return 0;
}
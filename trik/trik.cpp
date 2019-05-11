#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
	std::string moves;
	std::getline(std::cin, moves);
	bool cupL = true, cupM = false, cupR = false;
	for (const char c : moves) {
		if (c == 'A') {
			std::swap(cupL, cupM);
		}
		else if (c == 'B') {
			std::swap(cupM, cupR);
		}
		else if (c == 'C') {
			std::swap(cupL, cupR);
		}
	}
	std::cout << (cupL ? "1" : cupM ? "2" : "3");
	return 0;
}
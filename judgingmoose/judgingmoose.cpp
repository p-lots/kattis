#include <iostream>
#include <sstream>
#include <string>

int main(int argc, char *argv[])
{
	int l = 0, r = 0;
	std::cin >> l >> r;
	if (l == 0 && r == 0) {
		std::cout << "Not a moose";
		return 0;
	}
	std::string e_or_o = l == r ? "Even" : "Odd";
	int tines = std::max(l, r) * 2;
	std::cout << e_or_o << " " << tines;
	return 0;
}
#include <iostream>

int main(int argc, char *argv[])
{
	std::string line;
	std::cin >> line;
	if (line.empty()) {
		std::cout << "no hiss";
		return 0;
	}
	auto s_pos = line.find("ss");
	if (s_pos == std::string::npos) {
		std::cout << "no hiss";
		return 0;
	}
	else {
		std::cout << "hiss";
		return 0;
	}
	std::cout << "no hiss";
	return 0;
}
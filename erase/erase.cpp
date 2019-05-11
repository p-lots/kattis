#include <iostream>
#include <string>

int main()
{
	std::string line;
	std::getline(std::cin, line);
	int rotations = std::stoi(line);
	std::getline(std::cin, line);
	std::string original = line;
	std::string expected = original;
	std::getline(std::cin, line);
	std::string actual = line;
	for (unsigned i = 0; i < rotations; i++) {
		for (auto &c : expected) {
			if (c == '0') c = '1';
			else if (c == '1') c = '0';
		}
	}
	std::cout << (expected == actual ? "Deletion succeeded" : "Deletion failed");
	return 0;
}
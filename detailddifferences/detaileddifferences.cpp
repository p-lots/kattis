#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
	std::string line;
	std::getline(std::cin, line);
	int cases = std::stoi(line);
	while (cases-- > 0) {
		std::string input1, input2;
		std::getline(std::cin, input1);
		std::getline(std::cin, input2);
		std::cout << input1 << '\n' << input2 << '\n';
		for (unsigned i = 0; i < input1.length(); i++) {
			if (input1[i] == input2[i]) {
				std::cout << '.';
			}
			else {
				std::cout << '*';
			}
		}
		std::cout << "\n\n";
	}
}
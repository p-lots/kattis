#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
	bool first_time = true;
	std::string temp;
	int carrots = 0;
	while (std::getline(std::cin, temp)) {
		if (first_time) {
			std::string::size_type space = temp.find(' ');
			carrots = std::stoi(temp.substr(space + 1));
			first_time = false;
		}
	}
	std::cout << carrots;
	return 0;
}
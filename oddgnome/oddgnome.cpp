#include <iostream>
#include <sstream>
#include <string>
#include <vector>

std::vector<int> tokenize(std::string line)
{
	std::vector<int> ret;
	std::stringstream ss(line);
	std::string temp;
	while (std::getline(ss, temp, ' '))
		ret.push_back(std::stoi(temp));
	return ret;
}

int main(int argc, char *argv[])
{
	std::string line;
	std::getline(std::cin, line);
	int cases = std::stoi(line);
	while (cases--) {
		std::getline(std::cin, line);
		auto tokens = tokenize(line);
		auto gnomes = std::vector<int>(tokens.begin() + 1, tokens.end());
		int starting_gnome = gnomes.front();
		for (unsigned i = 0; i < gnomes.size(); i++) {
			if (gnomes[i] != starting_gnome + i) {
				std::cout << i + 1 << '\n';
				break;
			}
		}
	}
	return 0;
}
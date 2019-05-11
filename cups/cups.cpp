#include <cctype>
#include <iostream>
#include <map>
#include <string>

int main(int argc, char *argv[])
{
	int cases;
	std::string line;
	std::getline(std::cin, line);
	cases = std::stoi(line);
	std::map<int, std::string> data;
	while (cases-- > 0) {
		std::getline(std::cin, line);
		int n;
		std::string color;
		if (std::isdigit(line.at(0))) {
			auto pos = line.find(" ");
			n = std::stoi(line.substr(0, pos)) / 2;
			color = line.substr(pos + 1);
		}
		else {
			auto pos = line.find(" ");
			n = std::stoi(line.substr(pos + 1));
			color = line.substr(0, pos);
		}
		data[n] = color;
	}
	for (auto p : data) {
		std::cout << p.second << '\n';
	}
	return 0;
}

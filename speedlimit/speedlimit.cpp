#include <iostream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

int main(int argc, char *argv[])
{
	std::string line;
	while (std::getline(std::cin, line)) {
		int cases = std::stoi(line);
		if (cases == -1) {
			break;
		}
		std::vector<std::pair<int, int> > hours_vec;
		while (cases-- > 0) {
			std::getline(std::cin, line);
			std::stringstream ss(line);
			int speed, hours;
			ss >> speed >> hours;
			hours_vec.push_back(std::make_pair(speed, hours));
		}
		auto it = hours_vec.begin();
		int sum = it->first * it->second;
		for (auto it2 = hours_vec.begin() + 1; it2 != hours_vec.end(); it2++) {
			sum += (it2->first * (it2->second - it->second));
			it = it2;
		}
		std::cout << sum << " miles\n";
	}
	return 0;
}
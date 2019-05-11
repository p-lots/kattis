#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main(int argc, char *argv[])
{
	int cases;
	std::cin >> cases;
	std::vector<std::string> names;
	while (cases-- > 0) {
		std::string name;
		std::cin >> name;
		names.push_back(name);
	}
	std::vector<std::string> names_alph = names, names_rev_alph = names;
	std::sort(names_alph.begin(), names_alph.end());
	std::sort(names_rev_alph.rbegin(), names_rev_alph.rend());
	if (names == names_alph) {
		std::cout << "INCREASING";
	}
	else if (names == names_rev_alph) {
		std::cout << "DECREASING";
	}
	else {
		std::cout << "NEITHER";
	}
	return 0;
}

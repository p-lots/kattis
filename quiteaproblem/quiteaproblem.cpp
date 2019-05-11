#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>

int main()
{
	std::string line;
	while (std::getline(std::cin, line)) {
		bool has_problem = false;
		for (unsigned i = 0; i < line.length(); i++) {
			auto check = line.substr(i, 7);
			std::transform(check.begin(), check.end(), check.begin(), [](char &c) {
				return std::tolower(c);
			});
			if (check == "problem"){
				has_problem = true;
				break;
			}
		}
		std::cout << (has_problem ? "yes\n" : "no\n");
	}
	return 0;
}
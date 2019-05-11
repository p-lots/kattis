#include <cctype>
#include <iostream>
#include <set>
#include <string>

std::set<char> make_set(std::string line)
{
	std::set<char> ret;
	for (const char &c : line) {
		if (std::isalpha(c)) {
			ret.insert(std::tolower(c));
		}
	}
	return ret;
}

int main()
{
	std::string line;
	std::getline(std::cin, line);
	int cases = std::stoi(line);
	while (cases--) {
		std::getline(std::cin, line);
		auto letters_set = make_set(line);
		if (letters_set.size() == 26) {
			std::cout << "pangram";
		}
		else {
			std::cout << "missing ";
			for (char ch = 'a'; ch <= 'z'; ch++) 
				if (letters_set.count(ch) != 1) 
					std::cout << ch;
		}
		std::cout << '\n';
	}
	return 0;
}
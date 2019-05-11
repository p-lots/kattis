#include <cctype>
#include <iomanip>
#include <iostream>

int main(int argc, char *argv[])
{
	std::string line;

	std::cin >> line;

	double len = line.length();
	double whitespace_count = 0, lowercase_count = 0;
	double uppercase_count = 0, symbol_count = 0;
	double whitespace_ratio, lowercase_ratio;
	double uppercase_ratio, symbol_ratio;

	for (char c : line) {
		if (c == '_') {
			whitespace_count++;
		}
		else if (islower(c)) {
			lowercase_count++;
		}
		else if (isupper(c)) {
			uppercase_count++;
		}
		else {
			symbol_count++;
		}
	}

	whitespace_ratio = whitespace_count / len;
	lowercase_ratio = lowercase_count / len;
	uppercase_ratio = uppercase_count / len;
	symbol_ratio = symbol_count / len;

	std::cout << std::setprecision(16) << whitespace_ratio << '\n';
	std::cout << lowercase_ratio << '\n';
	std::cout << uppercase_ratio << '\n';
	std::cout << symbol_ratio << '\n';

	return 0;
}
#include <algorithm>
#include <iostream>
#include <iterator>
#include <map>
#include <string>

void rotate(std::string &input, int rotation)
{
	std::string source = "ABCDEFGHIJKLMNOPQRSTUVWXYZ_.";
	std::map<char, char> lookup_table;
	for (unsigned i = 0; i < source.length(); i++) {
		lookup_table[source[i]] = source.at((i + rotation) % 28);
	}
	for (unsigned i = 0; i < input.length(); i++) {
		input[i] = lookup_table.at(input[i]);
	}
}

int main(int argc, char *argv[])
{
	int rotation;
	std::string input;
	while (std::cin >> rotation >> input) {
		if (rotation > 0) {
			std::string result;
			std::copy(input.rbegin(), input.rend(), std::back_inserter(result));
			rotate(result, rotation);
			std::cout << result << '\n';
		}
	}
	return 0;
}
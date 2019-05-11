#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
	std::string line, result;
	std::cin >> line;
	char prev = line.at(0), curr;
	for (unsigned i = 1; i < line.length(); i++) {
		curr = line.at(i);
		if (curr != prev) {
			result.push_back(prev);
		}
		prev = curr;
	}
	if (prev != result.back()) {
		result.push_back(prev);
	}
	std::cout << result;
	return 0;
}
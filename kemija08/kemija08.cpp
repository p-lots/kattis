#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
	std::string line, result;
	std::getline(std::cin, line);
	for (unsigned i = 0; i < line.length(); i++) {
		if (line[i] == 'a' || line[i] == 'e' || line[i] == 'i'
			|| line[i] == 'o' || line[i] == 'u') {
			result.push_back(line[i]);
			i += 2;
			continue;
		}
		result.push_back(line[i]);
	}
	std::cout << result;
	return 0;
}
#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

static const std::vector<std::pair<std::string, std::string> > alt_names = {
	{ "A#", "Bb" },
	{ "C#", "Db" },
	{ "D#", "Eb" },
	{ "F#", "Gb" },
	{ "G#", "Ab" }
};

std::vector<std::string> tokenize(std::string);

int main(int argc, char *argv[])
{
	std::string line;
	int counter = 1;
	while (std::getline(std::cin, line)) {
		auto tokens = tokenize(line);
		std::string note = tokens[0];
		auto it = std::find_if(alt_names.begin(), alt_names.end(), [&note](const std::pair<std::string, std::string> &pair) {
			return pair.first == note || pair.second == note;
		});
		std::cout << "Case " << counter++ << ": ";
		if (it == alt_names.end()) {
			std::cout << "UNIQUE\n";
		}
		else {
			if (it->first == note) {
				std::cout << it->second << ' ' << tokens[1] << '\n';
			}
			else {
				std::cout << it->first << ' ' << tokens[1] << '\n';
			}
		}
	}
	return 0;
}

std::vector<std::string> tokenize(std::string line)
{
	std::vector<std::string> ret;
	std::stringstream ss(line);
	std::string temp;
	while (std::getline(ss, temp, ' ')) {
		ret.push_back(temp);
	}
	return ret;
}

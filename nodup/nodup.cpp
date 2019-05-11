#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <vector>

std::vector<std::string> tokenize(std::string line)
{
	std::vector<std::string> ret;
	std::stringstream ss(line);
	std::string temp;
	while (std::getline(ss, temp, ' '))
		ret.push_back(temp);
	return ret;
}

int main(int argc, char *argv[])
{
	std::string line;
	while (std::getline(std::cin, line)) {
		auto tokens = tokenize(line);
		std::set<std::string> word_set;
		bool has_no_dup = true;
		for (const auto &word : tokens) {	
			if (word_set.count(word) == 1) {
				//std::cout << "no";
				//return 0;
				has_no_dup = false;
			}
			else {
				word_set.insert(word);
			}
		}
		std::cout << (has_no_dup ? "yes\n" : "no\n");
	}
	return 0;
}
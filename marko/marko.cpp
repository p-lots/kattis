#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

int main()
{
	std::map<char, char> lookup_table = {
		{ 'a', '2' }, { 'b', '2' }, { 'c', '2' },
		{ 'd', '3' }, { 'e', '3' }, { 'f', '3' },
		{ 'g', '4' }, { 'h', '4' }, { 'i', '4' },
		{ 'j', '5' }, { 'k', '5' }, { 'l', '5' },
		{ 'm', '6' }, { 'n', '6' }, { 'o', '6' },
		{ 'p', '7' }, { 'q', '7' }, { 'r', '7' }, { 's', '7' },
		{ 't', '8' }, { 'u', '8' }, { 'v', '8' },
		{ 'w', '9' }, { 'x', '9' }, { 'y', '9' }, { 'z', '9' }
	};
	std::string line;
	std::getline(std::cin, line);
	int cases = std::stoi(line);
	std::vector<std::string> words;
	while (cases--) {
		std::getline(std::cin, line);
		words.push_back(line);
	}
	std::getline(std::cin, line);
	std::string keys = line;
	std::transform(words.begin(), words.end(), words.begin(), [&](std::string &str) {
		auto ret = str;
		for (char &c : ret) {
			c = lookup_table.at(c);
		}
		return ret;
	});
	int count = 0;
	for (auto it = words.begin(); it != words.end(); it++) {
		if (keys == *it) {
			count++;
		}
	}
	std::cout << count;
	return 0;
}
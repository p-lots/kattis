#include <cctype>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

bool is_vowel(char letter)
{
	return letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o'
		|| letter == 'u' || letter == 'y';
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

std::string make_pig_latin(std::string sentence)
{
	auto words = tokenize(sentence);
	std::string ret = "";
	for (const auto &word : words) {
		std::string new_word = "";
		char first = std::tolower(word.at(0));
		if (is_vowel(first)) new_word = word + "yay";
		else {
			for (unsigned i = 0; i < word.length(); i++) {
				if (is_vowel(word.at(i))) {
					new_word = word.substr(i) + word.substr(0, i) + "ay";
					break;
				}
			}
		}
		ret += new_word + " ";
	}
	ret.pop_back();
	return ret;
}

int main()
{
	std::string line;
	while (std::getline(std::cin, line)) {
		std::cout << make_pig_latin(line) << '\n';
	}
	return 0;
}
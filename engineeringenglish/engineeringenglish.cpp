#include <cctype>
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

std::string make_lower(std::string word)
{
	for (char &c : word)
		if (std::isalpha(c))
			c = std::tolower(c);
	return word;
}

std::string engineer_english(std::string line, std::set<std::string> &read_words)
{
	auto tokens = tokenize(line);
	std::vector<std::string> new_sentence;
	for (const auto &word : tokens) {
		auto lower_word = make_lower(word);
		auto new_word = word;
		if (read_words.count(lower_word) == 0) {
			read_words.insert(lower_word);
		}
		else {
			new_word = ".";
		}
		new_sentence.push_back(new_word);
	}
	std::string ret = "";
	for (const auto &word : new_sentence) {
		ret += word + " ";
	}
	ret.pop_back();
	return ret;
}

int main()
{
	std::string line;
	std::set<std::string> read_words;
	while (std::getline(std::cin, line)) {
		std::cout << engineer_english(line, read_words) << '\n';
	}
	return 0;
}
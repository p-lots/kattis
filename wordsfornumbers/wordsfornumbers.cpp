#include <cctype>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

std::vector<std::string> tokenize(std::string line)
{
	std::stringstream ss(line);
	std::string temp;
	std::vector<std::string> ret;
	while (std::getline(ss, temp, ' '))
		ret.push_back(temp);
	return ret;
}

std::string make_word(int n)
{
	std::vector<std::string> ones = {
		"zero",
		"one",
		"two",
		"three",
		"four",
		"five",
		"six",
		"seven",
		"eight",
		"nine"
	};
	std::vector<std::string> tweens_teens = {
		"ten",
		"eleven",
		"twelve",
		"thirteen",
		"fourteen",
		"fifteen",
		"sixteen",
		"seventeen",
		"eighteen",
		"nineteen"
	};
	std::vector<std::string> tens = {
		"twenty",
		"thirty",
		"forty",
		"fifty",
		"sixty",
		"seventy",
		"eighty",
		"ninety"
	};
	if (n < 10)
		return ones.at(n);
	else if (n < 20)
		return tweens_teens.at(n % 10);
	else {
		if (n % 10 == 0)
			return tens.at(n / 10 - 2);
		else
			return tens.at(n / 10 - 2) + "-" + ones.at(n % 10);
	}
}

std::string words_for_numbers(std::string line)
{
	std::string ret = "";
	auto tokens = tokenize(line);
	std::vector<std::string> new_sentence;
	for (const auto &word : tokens) {
		try {
			auto n = std::stoi(word);
			std::string new_word = make_word(n);
			new_sentence.push_back(new_word);
		}
		catch (std::exception e) {
			new_sentence.push_back(word);
		}
	}
	for (const auto &word : new_sentence)
		ret += word + " ";
	if (std::islower(ret[0])) ret[0] = std::toupper(ret[0]);
	ret.pop_back();
	return ret;
}

int main()
{
	std::string line;
	while (std::getline(std::cin, line)) {
		std::cout << words_for_numbers(line) << '\n';
	}
	return 0;
}
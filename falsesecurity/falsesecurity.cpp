#include <algorithm>
#include <iostream>
#include <map>
#include <string>

std::map<std::string, char> lookup_table = {
	{".-", 'A'},
	{"-...", 'B'},
	{"-.-.", 'C'},
	{"-..", 'D'},
	{".", 'E'},
	{"..-.", 'F'},
	{"--.", 'G'},
	{"....", 'H'},
	{"..", 'I'},
	{".---", 'J'},
	{"-.-", 'K'},
	{".-..", 'L'},
	{"--", 'M'},
	{"-.", 'N'},
	{"---", 'O'},
	{".--.", 'P'},
	{"--.-", 'Q'},
	{".-.", 'R'},
	{"...", 'S'},
	{"-", 'T'},
	{"..-", 'U'},
	{"...-", 'V'},
	{".--", 'W'},
	{"-..-", 'X'},
	{"-.--", 'Y'},
	{"--..", 'Z'},
	{"..--", '_'},
	{".-.-", ','},
	{"---.", '.'},
	{"----", '?'}
};

void make_reverse_lookup(std::map<char, std::string> &output,
	std::map<std::string, char> input)
{
	for (auto it : input) {
		output[it.second] = it.first;
	}
}

int main(int argc, char *argv[])
{
	std::string line;
	std::map<char, std::string> reverse_lookup;
	make_reverse_lookup(reverse_lookup, lookup_table);

	while (std::cin >> line) {
		std::string step_one_letters, step_one_numbers;
		for (char c : line) {
			step_one_letters += reverse_lookup.at(c);
			std::string len = std::to_string(reverse_lookup.at(c).length());
			step_one_numbers += len;
		}
		std::string step_two_numbers(step_one_numbers.rbegin(), step_one_numbers.rend());
		std::string result;
		unsigned i = 0, j = 0;
		while (i < step_one_letters.length()
			&& j < step_two_numbers.length()) {
			unsigned len = step_two_numbers[j] - '0';
			std::string lookup = step_one_letters.substr(i, len);
			result += lookup_table.at(lookup);
			i += len;
			j++;
		}
		std::cout << result << '\n';
	}

	return 0;
}
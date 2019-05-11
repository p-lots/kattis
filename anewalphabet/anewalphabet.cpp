#include <cstring>
#include <iostream>
#include <map>
#include <string>

static const std::map<char, std::string> lookup_table = {
	{'a', "@"},
	{'b', "8"},
	{'c', "("},
	{'d', "|)"},
	{'e', "3"},
	{'f', "#"},
	{'g', "6"},
	{'h', "[-]"},
	{'i', "|"},
	{'j', "_|"},
	{'k', "|<"},
	{'l', "1"},
	{'m', "[]\\/[]"},
	{'n', "[]\\[]"},
	{'o', "0"},
	{'p', "|D"},
	{'q', "(,)"},
	{'r', "|Z"},
	{'s', "$"},
	{'t', "']['"},
	{'u', "|_|"},
	{'v', "\\/"},
	{'w', "\\/\\/"},
	{'x', "}{"},
	{'y', "`/"},
	{'z', "2"}
};

std::string make_new_alphabet(std::string);

int main(int argc, char *argv[])
{
	std::string temp;

	while (std::getline(std::cin, temp)) {
		std::string result = make_new_alphabet(temp);
		std::cout << result << '\n';
	}
}

std::string make_new_alphabet(std::string input)
{
	std::string ret;

	for (const char c : input) {
		if (isalpha(c)) {
			ret += lookup_table.at(tolower(c));
		}
		else {
			ret.push_back(c);
		}
	}

	return ret;
}
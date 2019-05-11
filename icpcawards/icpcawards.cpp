#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

typedef std::pair<std::string, std::string> school_team_name;
typedef std::vector<school_team_name> name_vec;

std::vector<std::string> tokenize(std::string line)
{
	std::vector<std::string> ret;
	std::stringstream ss(line);
	std::string temp;
	while (std::getline(ss, temp, ' '))
		ret.push_back(temp);
	return ret;
}

void print_names(name_vec names)
{
	for (const auto &name : names) {
		std::cout << name.first << ' ' << name.second << '\n';
	}
}

int main(int argc, char *argv[])
{
	std::string line;
	std::getline(std::cin, line);
	int cases = std::stoi(line);
	name_vec names;
	while (cases--) {
		std::getline(std::cin, line);
		auto tokens = tokenize(line);
		names.push_back(std::make_pair(tokens[0], tokens[1]));
	}
	std::set<std::string> first_place_uni, second_place_uni, third_place_uni;
	name_vec first_place_name_vec, second_place_name_vec;
	name_vec third_place_name_vec;
	for (const auto &pair : names) {
		if (first_place_name_vec.size() < 4) {
			if (first_place_uni.count(pair.first) == 0) {
				first_place_name_vec.push_back(pair);
				first_place_uni.insert(pair.first);
				second_place_uni.insert(pair.first);
				third_place_uni.insert(pair.first);
			}
		}
		else if (second_place_name_vec.size() < 4) {
			if (second_place_uni.count(pair.first) == 0) {
				second_place_name_vec.push_back(pair);
				second_place_uni.insert(pair.first);
				third_place_uni.insert(pair.first);
			}
		}
		else if (third_place_name_vec.size() < 4) {
			if (third_place_uni.count(pair.first) == 0) {
				third_place_name_vec.push_back(pair);
				third_place_uni.insert(pair.first);
			}
		}
		else break;
	}
	print_names(first_place_name_vec);
	print_names(second_place_name_vec);
	print_names(third_place_name_vec);
	return 0;
}
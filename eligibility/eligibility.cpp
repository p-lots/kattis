#include <iostream>
#include <sstream>
#include <string>
#include <vector>

std::vector<std::string> tokenize(std::string line, char delim)
{
	std::vector<std::string> ret;
	std::stringstream ss(line);
	std::string temp;
	while (std::getline(ss, temp, delim)) {
		ret.push_back(temp);
	}
	return ret;
}

int parse_date(std::string date_str)
{
	auto tokens = tokenize(date_str, '/');
	return std::stoi(tokens[0]);
}

int parse_eligibility(int studies_begin_year, int birth_year, int courses)
{
	if (studies_begin_year >= 2010) {
		return 0;
	}
	else if (birth_year >= 1991) {
		return 0;
	}
	else if (courses > 40) {
		return 1;
	}
	else {
		return 2;
	}
}

int main(int argc, char *argv[])
{
	int cases;
	std::string line;
	std::getline(std::cin, line);
	cases = std::stoi(line);
	while (cases-- > 0) {
		std::getline(std::cin, line);
		auto tokens = tokenize(line, ' ');
		std::string name = tokens[0];
		int studies_begin_year = parse_date(tokens[1]);
		int birth_year = parse_date(tokens[2]);
		int courses = std::stoi(tokens[3]);
		std::cout << name << ' ';
		switch (parse_eligibility(studies_begin_year, birth_year, courses)) {
			case 0:
			std::cout << "eligible\n";
			break;
			case 1:
			std::cout << "ineligible\n";
			break;
			case 2:
			std::cout << "coach petitions\n";
			break;
			default:
			std::cout << "Error: Invalid input\n";
			break;
		}
	}
	return 0;
}
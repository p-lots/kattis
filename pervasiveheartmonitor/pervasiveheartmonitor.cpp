#include <cctype>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

std::vector<std::string> tokenize(std::string);

std::string get_name(std::vector<std::string>);

double get_average(std::vector<std::string>);

int main(int argc, char *argv[])
{
	std::string line;
	while (std::getline(std::cin, line)) {
		auto tokens = tokenize(line);
		auto name = get_name(tokens);
		double average = get_average(tokens);
		std::cout << std::setprecision(5) << std::fixed << average << ' ';
		std::cout << name << '\n';
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

std::string get_name(std::vector<std::string> tokens)
{
	std::string ret;
	for (std::string s : tokens) {
		if (std::isalpha(s.front())) {
			ret += s + " ";
		}
	}
	return ret;
}

double get_average(std::vector<std::string> tokens)
{
	double sum = 0.0, count = 0.0;
	for (std::string s : tokens) {
		if (std::isdigit(s.front())) {
			sum += std::stod(s);
			count++;
		}
	}
	return sum / count;
}
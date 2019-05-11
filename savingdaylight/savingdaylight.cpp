#include <iostream>
#include <sstream>
#include <string>
#include <vector>

std::vector<std::string> tokenize(std::string);

int time_to_mins(std::string);

int main(int argc, char *argv[])
{
	std::string line;
	while (std::getline(std::cin, line)) {
		auto tokens = tokenize(line);
		auto date = tokens.at(0) + " " + tokens.at(1) + " " + tokens.at(2);
		auto start_time = time_to_mins(tokens.at(3)), end_time = time_to_mins(tokens.at(4));
		int duration = end_time - start_time;
		int dur_hours = duration / 60, dur_mins = duration % 60;
		std::cout << date << ' ';
		std::cout << dur_hours << " hours ";
		std::cout << dur_mins << " minutes\n";
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

int time_to_mins(std::string t)
{
	int hours = std::stoi(t.substr(0, t.find(":")));
	int minutes = std::stoi(t.substr(t.find(":") + 1));
	return hours * 60 + minutes;
}
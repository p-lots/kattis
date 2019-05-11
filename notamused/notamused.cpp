#include <iomanip>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>
#include <utility>

typedef std::pair<int, int> time_pair;
typedef std::vector<time_pair> time_pair_vec;
typedef std::map<std::string, time_pair_vec> name_map;

std::vector<std::string> tokenize(std::string line)
{
	std::vector<std::string> ret;
	std::stringstream ss(line);
	std::string temp;
	while (std::getline(ss, temp, ' '))
		ret.push_back(temp);
	return ret;
}

int main()
{
	std::string line;
	int day = 1;
	name_map names_times;
	while (std::getline(std::cin, line)) {
		if (line == "CLOSE") {
			std::cout << "Day " << day++ << '\n';
			for (auto it = names_times.begin(); it != names_times.end(); it++) {
				std::cout << it->first << " $";
				double total = 0.0;
				for (auto vec_it = it->second.begin(); vec_it != it->second.end(); vec_it++) {
					total += static_cast<double>(vec_it->second - vec_it->first) * 0.1;
				}
				std::cout << std::fixed << std::setprecision(2) << total << '\n';
			}
			std::cout << '\n';
			continue;
		}
		else if (line == "OPEN") {
			names_times = std::map<std::string, time_pair_vec>();
			continue;
		}
		auto tokens = tokenize(line);
		auto direction = tokens.at(0);
		auto name = tokens.at(1);
		auto t = std::stoi(tokens.at(2));
		if (direction == "ENTER") {
			if (names_times.count(name) == 0) {
				time_pair t_p = std::make_pair(t, 0);
				time_pair_vec t_p_v = { t_p };
				names_times[name] = t_p_v;
			}
			else {
				time_pair t_p = std::make_pair(t, 0);
				names_times[name].push_back(t_p);
			}
		}
		else if (direction == "EXIT") {
			auto last_pair = names_times[name].end() - 1;
			last_pair->second = t;
		}
	}
	return 0;
}
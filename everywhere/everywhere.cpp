#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main(int argc, char *argv[])
{
	std::string line;
	int num_trips;
	std::cin >> num_trips;
	while (num_trips-- > 0) {
		int num_city_cases;
		std::cin >> num_city_cases;
		std::vector<std::string> cities;
		while (num_city_cases-- > 0) {
			std::string city;
			std::cin >> city;
			if (std::find(cities.begin(), cities.end(), city) == cities.end()) {
				cities.push_back(city);
			}
		}
		int num_cities = cities.size();
		std::cout << num_cities << '\n';
	}
	return 0;
}
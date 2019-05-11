#include <iostream>
#include <sstream>
#include <string>

int main(int argc, char *argv[])
{
	std::string temp;
	bool first_time = true;
	int number_of_temperatures = 0, below_zero_count = 0;
	long temperature_temp;
	while (std::getline(std::cin, temp)) {
		if (first_time) {
			number_of_temperatures = std::stoi(temp);
			first_time = false;
		}
		else {
			std::stringstream ss(temp);
			std::string temp2;
			while (std::getline(ss, temp2, ' ')) {
				temperature_temp = std::stoi(temp2);
				if (temperature_temp < 0) {
					below_zero_count++;
				}
			}
		}
	}
	std::cout << below_zero_count;
	return 0;
}
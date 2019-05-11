#include <iostream>
#include <string>

#define CALORES_PER_BOTTLE 400

int calculate_soylent(int calories)
{
	int test = calories / CALORES_PER_BOTTLE;
	if (test * CALORES_PER_BOTTLE < calories) {
		return test + 1;
	}
	else {
		return test;
	}
}

int main(int argc, char *argv[])
{
	std::string temp;
	bool first_time = true;
	int cases, case_counter = 0;

	while (std::getline(std::cin, temp)) {
		if (first_time) {
			cases = std::stoi(temp);
			first_time = false;
		}
		else {
			if (case_counter < cases) {
				std::cout << calculate_soylent(std::stoi(temp)) << '\n';
				case_counter++;
			}
		}
	}

	return 0;
}